#include "fileManager.h"
#include "fileutil.h"


void FileManager::getCopyList()
{
	_md5toFiles.clear();
	
	auto it = _md5toFiles.begin();
	while (it != _md5toFiles.end())
	{
		if (_md5toFiles.count(it->first) > 1)
		{
			auto paitIt = _md5toFiles.equal_range(it->first);
			auto begin = paitIt.first;
			while (begin != paitIt.second)
			{
				_filestoMd5.insert(make_pair(begin->second, begin->first));
				++begin;
			}
			it = paitIt.second;
		}
		else
		{
			_files.erase(it->second);
			it = _md5toFiles.erase(it);	
		}
	}
}

void FileManager::getMd5toFiles()
{
	_filestoMd5.clear();
	for (const auto& f : _files)
	{
		_md5.reset();
		_md5toFiles.insert(make_pair(_md5.getFileMD5(f.c_str()), f));
	}
}

void FileManager::scannerDir(const std::string& path)
{
	_files.clear();
	std::cout << "all file" << std::endl;
	searchDir(path, _files);
	showAllFile();
	getMd5toFiles();
	showCopyList();
	getCopyList();
	std::cout << "copy list" << std::endl;

	showCopyList();
	showAllFile();
}

void FileManager::deleteByName(const std::string& name)
{

}

void FileManager::deleteByMD5(const std::string& md5)
{

}

void FileManager::deleteAllCopy()
{

}

void FileManager::deleteByMatchName(const std::string& matchName)
{

}

void FileManager::showCopyList()
{
	auto it = _md5toFiles.begin();
	int total = _md5toFiles.size();
	int count = 0;
	while (it != _md5toFiles.end())
	{
		int idx = 1;
		auto paitIt = _md5toFiles.equal_range(it->first);
		auto cutIt = paitIt.first;
		std::cout << "cut MD5:" << it->first << std::endl;
		while (cutIt != paitIt.second)
		{
			std::cout << "\t第" << idx << "个文件";
			std::cout << cutIt->second << std::endl;
			++cutIt;
			++idx;
			count++;
		}
		it = paitIt.second;
	}
	std::cout << "文件大小" << total << "\t" << count << std::endl;
}
void FileManager::showAllFile()
{
	for (const auto& f : _files)
	{
		std::cout << f << std::endl;
	}
	std::cout << "file count:" << _files.size() << std::endl;
}
void FileManager::showMD5Map()
{

}