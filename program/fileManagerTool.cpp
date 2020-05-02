#include "fileManagerTool.h"

void FileManagerTool::scanner()
{
	cout << "请输入要扫描的文件夹:" << endl;
	std::string path;
	getline(cin, path);
	_fm.scannerDir(path);
}

void FileManagerTool::deletebymd5()
{
	cout << "请输入要删除的文件夹:" << endl;
	std::string md5;
	cin >> md5;
	_fm.deleteByMD5(md5);
}

void FileManagerTool::deletebyname()
{
	cout << "请输入要删除的文件夹:" << endl;
	std::string filename;
	getline(cin, filename);
	_fm.deleteByName(filename);
}

void FileManagerTool::deleteAllCopy()
{
	_fm.deleteAllCopy();
}

void FileManagerTool::deleteFuzzyMatchCopy()
{
	cout << "请输入匹配文件名:" << endl;
	std::string match;
	getline(cin, match);
	_fm.deleteByMatchName(match);
}

void FileManagerTool::showCopy()
{
	_fm.showCopyList();
}

void FileManagerTool::showAllFile()
{
	_fm.showAllFile();
}