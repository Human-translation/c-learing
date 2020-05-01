#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "md5.h"


class FileManager
{
public:
	void getCopyList();
	void getMd5toFiles();
	void scannerDir(const std::string& path);
	void deleteByName(const std::string& name);
	void deleteByMD5(const std::string& md5);
	void deleteAllCopy();
	void deleteByMatchName(const std::string& matchName);

	void showCopyList();
	void showAllFile();
	void showMD5Map();
private:
	std::unordered_set<std::string> _files;
	std::unordered_multimap<std::string,std::string> _md5toFiles;
	std::unordered_map<std::string, std::string> _filestoMd5;
	MD5 _md5;
};