#pragma once
#include <unordered_set>
#include <unordered_map>
#include <string>
#include "MD5.h"

class FileManage
{
public:

private:
	std::unordered_set<std::string> _File;
	std::unordered_multimap<std::string, std::string> _Md5ToFile;
	std::unordered_map<std::string, std::string> _FileToMd5;
	MD5 md5;
};