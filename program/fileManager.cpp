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
	//std::cout << "all file" << std::endl;
	searchDir(path, _files);
	//showAllFile();
	getMd5toFiles();
	//showCopyList();
	getCopyList();
	//std::cout << "copy list" << std::endl;

	//showCopyList();
	//showAllFile();
}

void FileManager::deleteByName(const std::string& name)
{
	if (_filestoMd5.count(name) == 0)
	{
		std::cout << name << "not exist!" << std::endl;
		return;
	}
	std::string curMD5 = _filestoMd5[name];
	std::cout << name << "---->" << _md5toFiles.count(curMD5) << std::endl;
	auto pairIt = _md5toFiles.equal_range(curMD5);
	auto curIt = pairIt.first;
	int count = 0;
	while (curIt != pairIt.second)
	{
		if (curIt->second != name)
		{
			_files.erase(curIt->second);
			_filestoMd5.erase(curIt->second);
			deleteFile(curIt->second.c_str());
			++count;
		}
		++curIt;
	}
	curIt = pairIt.first;
	while (curIt != pairIt.second)
	{
		if (curIt->second != name)
		{
			_md5toFiles.erase(curIt);
			pairIt = _md5toFiles.equal_range(curMD5);
			curIt = pairIt.first;
		}
		++curIt;
	}
	std::cout << "delete files number :" << count << std::endl;
}

void FileManager::deleteByMD5(const std::string& md5)
{
	if (_md5toFiles.count(md5) == 0)
	{
		std::cout << md5 << "not exist!" << std::endl;
		return;
	}
	auto pairIt = _md5toFiles.equal_range(md5);
	std::cout << md5 << "---->" << _md5toFiles.count(md5) << std::endl;
	auto curIt = pairIt.first;
	++curIt;
	int count = 0;
	while (curIt != pairIt.second)
	{
		_files.erase(curIt->second);
		_filestoMd5.erase(curIt->second);
		deleteFile(curIt->second.c_str());
		++count;
		++curIt;
	}
	curIt = pairIt.first;
	++curIt;
	_md5toFiles.erase(curIt, pairIt.second);
	std::cout<<"delete files number :"<< count << std::endl;
}

void FileManager::deleteByMD5V2(const std::string& md5)
{
	if (_md5toFiles.count(md5) == 0)
	{
		std::cout << md5 << "not exist!" << std::endl;
		return;
	}
	auto it = _md5toFiles.find(md5);
	deleteByName(it->second);
}

void FileManager::deleteAllCopy()
{
	std::unordered_set<std::string> md5Set;
	for (const auto& p : _md5toFiles)
	{
		md5Set.insert(p.first);
	}
	for (const auto& md5 : md5Set)
	{
		deleteByMD5(md5);
	}
}

void FileManager::deleteByMatchName(const std::string& matchName)
{
	std::unordered_set<std::string> allFiles;
	for (const auto& f : _files)
	{
		if (f.find(matchName) != std::string::npos)
		{
			allFiles.insert(f);
		}
	}
	for (const auto& f : allFiles)
	{
		if (_filestoMd5.count(f) != 0)
		{
			deleteByName(f);
		}
	}
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