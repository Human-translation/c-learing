#pragma once
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<unordered_map>
#include<zlib.h>
#include<pthread.h>
#include<boost/filesystem.hpp>
#include<boost/algorithm/string.hpp>
#include"httplib.h"
#include"LogSvr.hpp"
#define NONHOT_TIME 10  //最后一次访问时间在10秒以外
#define INTERVAL_TIME 30  //非热点的检测30秒一次

#define BACKUP_PATH "./backup/"  //要备份的文件路径
#define GZFILE_PATH "./gzfile/"  //压缩后的文件路径
#define DATA_FILE "./list.backup"  //数据管理模块的数据备份文件名称


namespace _cloud_sys
{   


    class FileUtil
    {
        public:
            static bool Read(const std::string &Name,std::string* Body) //读取文件内容
            {
                std::ifstream fin(Name,std::ios::binary);
                if(!fin.is_open())
                {
                    LOG(ERROR,"open file failed ---")<< Name <<std::endl;
                    return false;
                }
                int64_t fsize = boost::filesystem::file_size(Name);
                Body->resize(fsize);
                fin.read(&(*Body)[0],fsize);
                if(fin.good() == false)
                {
                    LOG(ERROR,"file read failed ---")<< Name <<std::endl;
                    return false;
                }
                fin.close();
                return true;
            }

            static bool Write(const std::string &Name, const std::string &Body) //向文件写入数据
            {
                std::ofstream fout(Name, std::ios::binary);  //ofstrem默认打开文件时会清空原有内容
                if(!fout.is_open())  //打开失败
                {
                    LOG(ERROR,"FileUtil::Write open failed ---")<< Name <<std::endl;
                    return false;                                    
                }
                fout.write(&Body[0], Body.size());
                if(!fout.good())
                {
                    LOG(ERROR,"FileUtil::Write file failed!")<< Name <<std::endl;
                    return false;         
                }
                fout.close();
                return true;
            }
    };

    class CompressUtil
    {
        public:
            static bool Compress(const std::string &Src, const std::string &Dst)  //压缩
            {
                std::string body;
                FileUtil::Read(Src,&body);
                gzFile gf = gzopen(Dst.c_str(),"wb");
                if(gf == NULL)
                {
                    LOG(ERROR,"open file failed ---")<< Dst  <<std::endl;
                    return false;
                }
                int wlen = 0;
                while(wlen < body.size())
                {
                    int ret = gzwrite(gf,&body[wlen],body.size() - wlen);
                    if(ret == 0)
                    {
                        LOG(ERROR,"file write compress data failed ---")<< Dst  <<std::endl;
                        return false;
                    }
                    wlen += ret;
                }
                gzclose(gf);
                return true;
            }
            
            //解压缩--压缩包名称--源文件名称
            static bool UnCompress(const std::string &Src, const std::string &Dst) //解压缩
            {
                std::ofstream fout(Dst,std::ios::binary);
                if(!fout.is_open())
                {
                    LOG(ERROR,"open file failed ---")<< Dst  <<std::endl;
                    return false;
                }
                gzFile gf = gzopen(Src.c_str(),"rb");
                if(gf == NULL)
                {
                    LOG(ERROR,"CompressUtil::UnCompress : open file failed ---")<< Src  <<std::endl;
                    fout.close();  //压缩文件打开失败但是源文件打开成功了，返回时需要关闭
                    return false;
                }
                int ret;
                char tmp[4096] = {0};
                while((ret = gzread(gf,tmp,4096)) > 0)
                {
                    fout.write(tmp,ret);
                }

                gzclose(gf);
                fout.close();
                return true;
            }          
    };

    class DataManager
    {
        public:
            DataManager(const std::string &Path)
                :BackFile_(Path)
            {
                pthread_rwlock_init(&Rwlock_,NULL); 
            }

            ~DataManager()
            {
                pthread_rwlock_destroy(&Rwlock_);
            }

            bool Exists(const std::string &Name) //判断文件是否存在
            {
                pthread_rwlock_rdlock(&Rwlock_);
                auto it = FileList_.find(Name);
                if(it == FileList_.end())
                {
                    pthread_rwlock_unlock(&Rwlock_);
                    return false;
                }
                pthread_rwlock_unlock(&Rwlock_);
                return true;
            }

            bool IsCompress(const std::string &Name) //判断文件是否已经压缩
            {
                pthread_rwlock_rdlock(&Rwlock_);
                auto it = FileList_.find(Name);
                if(it == FileList_.end())
                {
                    pthread_rwlock_unlock(&Rwlock_);
                    return false;
                }
                if(it->first == it->second)
                {
                    pthread_rwlock_unlock(&Rwlock_);
                    return false;
                }
                pthread_rwlock_unlock(&Rwlock_);
                return true;
            }

            bool NonCompressList(std::vector<std::string>* List) //获取未压缩文件列表
            {
                pthread_rwlock_rdlock(&Rwlock_);
                auto it = FileList_.begin();
                for(;it != FileList_.end();++it)
                {
                    if(it->first == it->second)
                    {
                        List->push_back(it->first);
                    }
                }
                pthread_rwlock_unlock(&Rwlock_);
                return true;
            }

            bool Insert(const std::string &Src,const std::string &Dst) //插入更新数据
            {
                pthread_rwlock_wrlock(&Rwlock_);
                FileList_[Src] = Dst;

                pthread_rwlock_unlock(&Rwlock_);
                Storage();
                return true;
            }

            bool GetAllName(std::vector<std::string>* List) //获取所有文件名称
            {
                pthread_rwlock_rdlock(&Rwlock_);
                auto it = FileList_.begin();
                for(;it != FileList_.end();++it)
                {
                    List->push_back(it->first);
                }

                pthread_rwlock_unlock(&Rwlock_);
                return true;
            }

            bool GetGzName(const std::string &Src, std::string *Dst)
            {
                auto it = FileList_.find(Src);
                if(it == FileList_.end())  //没找到文件
                    return false;
                *Dst = it->second;
                return true;
            }

            bool Storage() //数据改变后持久化存储
            {
                std::stringstream tmp;
                pthread_rwlock_rdlock(&Rwlock_);
                auto it = FileList_.begin();
                for(;it != FileList_.end();++it)
                {
                    tmp << it->first << " " << it->second << "\r\n";
                }
                pthread_rwlock_unlock(&Rwlock_);
                FileUtil::Write(BackFile_, tmp.str());  //持久化存储写入时不需要在锁内进行
                return true;
            }

            bool InitLoad() //初始化加载
            {
                std::string body;
                if(!FileUtil::Read(BackFile_, &body))
                {
                    return false;
                }
                std::vector<std::string> list;
                boost::split(list, body, boost::is_any_of("\r\n"), boost::token_compress_off);
                for(auto i : list)
                {
                    size_t pos = i.find(" ");
                    if(pos == std::string::npos)
                    {
                        continue;
                    }
                    std::string key = i.substr(0,pos);
                    std::string val = i.substr(pos+1);

                    Insert(key,val);
                }
                return true;
            }

        private:
            std::string BackFile_; //持久化数据存储文件名称
            std::unordered_map<std::string,std::string> FileList_; //数据管理容器
            pthread_rwlock_t Rwlock_;
    };

    _cloud_sys::DataManager data_manage(DATA_FILE);

    class NonHotCompress
    {
        public:    
            NonHotCompress(const std::string BuPath,const std::string DirPath)
                :BuDir_(BuPath)
                ,GzDir_(DirPath)
            {
                
            }

            ~NonHotCompress()
            {

            }

            bool Start() //总体向外提供的功能接口，开始压缩模块
            {
                while(1)
                {
                    std::vector<std::string> list;
                    data_manage.NonCompressList(&list);
                    for(int i=0;i<list.size();++i)
                    {
                        if(!FileIsHot(list[i]));
                        {
                            LOG(INFO,"There is a NonHotUncompress file ---")<<list[i] <<std::endl;
                            std::string src_name = list[i];  //源文件名称
                            std::string dst_name = list[i] + ".gz";
                            std::string src_path = BuDir_ + src_name;  //源文件路径+名称
                            std::string dst_path = GzDir_ + dst_name;

                            if(CompressUtil::Compress(src_path, dst_path))
                            {
                                data_manage.Insert(src_name, dst_name);  //更新数据信息，不带路径
                                unlink(src_path.c_str());  //删除源文件
                            }
                        }
                    }
                    sleep(INTERVAL_TIME);
                }
                return true;
            }

        private:
            bool FileIsHot(const std::string &Name) //判断文件是否是热点文件
            {
                time_t cur_t = time(NULL);
                struct stat st;
                if(stat(Name.c_str(),&st) < 0)
                {
                    LOG(ERROR,"get file star failed ---")<< Name <<std::endl;
                    return false;
                }
                if((cur_t - st.st_atime) > NONHOT_TIME)
                {
                    return false;
                }
                return true;
            }

        private:
            std::string BuDir_;
            std::string GzDir_; //压缩后的文件存储路径
    };

    class Server
    {
        public:
            Server()
            {

            }

            ~Server()
            {

            }

            bool Start()
            {
                Server_.Put("/(.*)",UpLoad);
                Server_.Get("/list",List);
                Server_.Get("/download/(.*)",DownLoad);

                Server_.listen("0.0.0.0",9000);
                return true;
            }

        private:
            static void UpLoad(const httplib::Request &Req, httplib::Response &Rsp)//上传
            {
                std::string filename = Req.matches[1];
                std::string pathname = BACKUP_PATH + filename;
                FileUtil::Write(pathname,Req.body);
                data_manage.Insert(filename,filename);
                Rsp.status = 200;
                return;
            }

            static void List(const httplib::Request &Req, httplib::Response &Rsp)  //列表
            {
                std::vector<std::string> list;
                data_manage.GetAllName(&list);
                std::stringstream tmp;
                tmp << "<html><body><hr />";
                for(int i = 0;i<list.size();++i)
                {
                    tmp << "<a href='/download/" << list[i] << "'>" << list[i] << "</a>";
                    tmp << "<hr />";
                }
                tmp << "<hr /></body></html>";
                
                Rsp.set_content(tmp.str().c_str(),tmp.str().size(),"text/html");
                Rsp.status = 200;
                return;
            }

            static void DownLoad(const httplib::Request &Req, httplib::Response &Rsp)  //下载
            {
                std::string filename = Req.matches[1];
                if(!data_manage.Exists(filename))
                {
                    Rsp.status = 404;
                    LOG(ERROR,"download is failed!")<<std::endl;
                    return;
                }

                std::string file_path = BACKUP_PATH + filename; 
                if(data_manage.IsCompress(filename))
                {
                    std::string gzname;
                    data_manage.GetGzName(filename, &gzname);  //获取压缩包文件名称
                    std::string gzfile_path = GZFILE_PATH + gzname;
                    CompressUtil::UnCompress(gzfile_path, file_path);  //解压缩
                    unlink(gzfile_path.c_str());  //删除压缩包
                    data_manage.Insert(filename, filename);  //更新文件状态
                }
                FileUtil::Read(file_path, &Rsp.body);
                Rsp.set_header("Content-Type", "application/octet-stream");
                Rsp.status = 200;
                return;
            }

        private:
            std::string FileDir_;
            httplib::Server Server_;

    };

}


















