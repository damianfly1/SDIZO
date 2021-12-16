#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
class FileReader
{
public:
	std::vector<int> fileInfo;
	std::vector<int> readDataFromFileMST(std::string filename);
	std::vector<int> readDataFromFileSP(std::string filename);
	bool fileReadLine(std::ifstream& file, int tab[], int size);
};

