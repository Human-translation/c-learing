#include "SweepDisk.h"

void SearchDir(const std::string& Path, std::unordered_set<std::string>& SubFiles)
{
	std::string FilePath = Path + "\\" + "*.*";
	_finddata_t FileAttr;
	long handle = _findfirst(FilePath.c_str(), &FileAttr);
	if (handle == -1)
	{
		std::cout << "Search not find!" << std::endl;
		return;
	}
	do
	{
		if (FileAttr.attrib & _A_SUBDIR)
		{
			if (strcmp(FileAttr.name, ".") != 0 || strcmp(FileAttr.name, "..") != 0)
				SearchDir(Path + "\\" + FileAttr.name, SubFiles);
		}
		else
		{
			SubFiles.insert(Path + "\\" + FileAttr.name);
		}
	} while (_findnext(handle, &FileAttr));
	_findclose(handle);
}


void DeleteFile(const char* FileName)
{
	if (remove(FileName) == 0)
	{
		std::cout << "delete file:" << FileName << "success!" << std::endl;
	}
	else
	{
		perror("delete file failed!");
	}
}