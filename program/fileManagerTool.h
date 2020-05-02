#pragma once
#include "fileManager.h"
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

class FileManagerTool
{
public:
	void scanner();

	void deletebymd5();

	void deletebyname();

	void deleteAllCopy();

	void deleteFuzzyMatchCopy();

	void showCopy();

	void showAllFile();

private:
	FileManager _fm;
};