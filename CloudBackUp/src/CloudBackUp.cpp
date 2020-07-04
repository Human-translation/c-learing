#include <thread>
#include "CloudBackUp.hpp"


void CompressTest(char* argv[])
{
    /*
    argv[1]源文件名称
    argv[2]压缩包名称
    */
    _cloud_sys::CompressUtil::Compress(argv[1],argv[2]);
    std::string file = argv[2];
    file += ".txt";
    _cloud_sys::CompressUtil::UnCompress(argv[2],file.c_str());
}

void DatamanagerTest()
{
    _cloud_sys::DataManager data_manage("./test.txt");
    
    data_manage.InitLoad();
    data_manage.Insert("c.txt","c.txt.gz");
    std::vector<std::string> list;
    data_manage.GetAllName(&list);
    for(auto i : list)
    {
        printf("%s\n",i.c_str());
    }
    printf("------------------------\n");
    list.clear();
    data_manage.NonCompressList(&list);
    for(auto i : list)
    {
        printf("%s\n",i.c_str());
    }

    /*
    data_manage.Insert("a.txt","a.txt");
    data_manage.Insert("b.txt","b.txt.gz");
    data_manage.Insert("c.txt","c.txt");
    data_manage.Insert("d.txt","d.txt.gz");
    data_manage.Storage();
    */
}

void NonCompress()
{
    _cloud_sys::NonHotCompress ncom(BACKUP_PATH,GZFILE_PATH);
    ncom.Start();
    return;
}

void NonHotCompressTest()
{
    if(!boost::filesystem::exists(GZFILE_PATH))
    {
        boost::filesystem::create_directory(GZFILE_PATH);
    }

    if(!boost::filesystem::exists(BACKUP_PATH))
    {
        boost::filesystem::create_directory(BACKUP_PATH);
    }

    _cloud_sys::data_manage.Insert("mao.docx","mao.docx");
    std::thread thr(NonCompress);
    thr.join();
}

void ThrHttpServer()
{
    _cloud_sys::Server server;
    server.Start();
}

void Project()
{
    
    if(!boost::filesystem::exists(GZFILE_PATH))
    {
        boost::filesystem::create_directory(GZFILE_PATH);
    }

    if(!boost::filesystem::exists(BACKUP_PATH))
    {
        boost::filesystem::create_directory(BACKUP_PATH);
    }

    std::thread thr_compress(NonCompress);  //压缩线程 启动非热点压缩模块
    std::thread thr_server(ThrHttpServer);  //通信线程 网络通信服务端启动

    thr_compress.join();  //线程等待 
    thr_server.join();
}

int main(int argc,char* argv[])
{   
    Project();
    return 0;
}













