#include "fileutil.h"

void searchDir(const std::string& path, std::unordered_set<std::string>& subFiles)
{
	std::string matchFile = path + "\\" + "*.*";
	_finddata_t fileAttr;
	long handle = _findfirst(matchFile.c_str(), &fileAttr);
	if (handle == -1)
	{
		perror("search failed !");
		std::cout << matchFile << std::endl;
		return;
	}
	do
	{
		if (fileAttr.attrib & _A_SUBDIR)
		{
			if (strcmp(fileAttr.name, ".") != 0 && strcmp(fileAttr.name, "..") != 0)
				searchDir(path + "\\" + fileAttr.name, subFiles);
		}
		else
		{
			subFiles.insert(path + "\\" + fileAttr.name);
		}
	} while (_findnext(handle, &fileAttr) == 0);
	_findclose(handle);
}

void deleteFile(const char* filename)
{
	if (remove(filename) == 0)
	{
		std::cout << "delete file:" << filename << "success!" << std::endl;
	}
	else
	{
		perror("delete file failed!");
	}
}