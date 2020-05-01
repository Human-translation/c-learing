#pragma once
#include <io.h>
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

void searchDir(const std::string& path, std::unordered_set<std::string>& subFiles);

void deleteFile(const char* filename);
