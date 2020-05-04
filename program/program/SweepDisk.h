#pragma once
#include <io.h>
#include <string>
#include <unordered_set>
#include <iostream>

void SearchDir(const std::string& Path, std::unordered_set<std::string>& SubFiles);
void DeleteFile(const char* FileName);
