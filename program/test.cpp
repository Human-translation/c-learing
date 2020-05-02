#include <iostream>
#include "md5.h"
#include "fileutil.h"
#include "fileManager.h"
#include "fileManagerTool.h"
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
	std::string path = "C:\\Users\\Administrator\\Desktop\\ÍøÒ³";
	fm.scannerDir(path);
}

void menu()
{
	cout << "*********************************************" << endl;
	cout << "1:scanner        2:show all      3:show copy" << endl;
	cout << "4:delete name    5:delete md5    6:delete all" << endl;
	cout << "7:delete match   0:exit" << endl;
	cout << "*********************************************" << endl;
}

void testFileManagerTool()
{
	FileManagerTool fmt;
	int input;
	do 
	{
		menu();
		std::string garbage;
		cout << "ÇëÊäÈëÑ¡Ïî:" << endl;
		cin >> input;
		getline(cin, garbage);
		switch (input)
		{
		case 1:
			fmt.scanner();
			break;
		case 2:
			fmt.showAllFile();
			break;
		case 3:
			fmt.showCopy();
			break;
		case 4:
			fmt.deletebyname();
			break;
		case 5:
			fmt.deletebymd5();
			break;
		case 6:
			fmt.deleteAllCopy();
			break;
		case 7:
			fmt.deleteFuzzyMatchCopy();
			break;
		case 0:
		default:
			break;
		}
	} while (input != 0);
}

int main()
{
	testFileManagerTool();
	return 0;
}