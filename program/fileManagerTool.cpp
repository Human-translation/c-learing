#include "fileManagerTool.h"

void FileManagerTool::scanner()
{
	cout << "������Ҫɨ����ļ���:" << endl;
	std::string path;
	getline(cin, path);
	_fm.scannerDir(path);
}

void FileManagerTool::deletebymd5()
{
	cout << "������Ҫɾ�����ļ���:" << endl;
	std::string md5;
	cin >> md5;
	_fm.deleteByMD5(md5);
}

void FileManagerTool::deletebyname()
{
	cout << "������Ҫɾ�����ļ���:" << endl;
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
	cout << "������ƥ���ļ���:" << endl;
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