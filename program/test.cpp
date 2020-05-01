#include <iostream>
#include "md5.h"
#include "fileutil.h"
#include "fileManager.h"
using std::cout;
using std::endl;

void testHex()
{
	MD5 md5;
	uint32 n = 0x23456789;
	cout << md5.changHex(n) << endl;
}

void testStringMD5()
{
	MD5 md5;
	std::string str1 = "123456789abcdefgh";
	std::string str2 = "123456789abcdefgi";
	std::cout << md5.getStringMD5(str1) << std::endl;
	std::cout << md5.getStringMD5(str2) << std::endl;
}

void testFileMD5()
{
	MD5 md5;
	const char* filepath1 = "123.txt";
	const char* filepath2 = "aaa";

	std::cout << md5.getFileMD5(filepath1) << std::endl;
	md5.reset();
	std::cout << md5.getFileMD5(filepath2) << std::endl;
}
/*
void testSearch()
{
	std::string path;
	cout << "Please input search dir:" << endl;
	getline(std::cin,path);
	std::vector<std::string> subFiles;
	searchDir(path, subFiles);
	for (const auto& f : subFiles)
	{
		cout << f << endl;
	}
}
*/


void testFM()
{
	FileManager fm;
	std::string path = "C:\\Users\\Administrator\\Desktop\\อ๘าณ";
	fm.scannerDir(path);
}

int main()
{
	testFM();
	return 0;
}