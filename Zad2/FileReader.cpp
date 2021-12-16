#include "FileReader.h"

std::vector<int> FileReader::readDataFromFileMST(std::string filename)
{
	std::ifstream file;
	//std::cout << "Wszedlem do funkcji" << std::endl;
	int tab[3];
	file.open(filename);
	//std::cout << "Otworzylem plik";
	fileInfo.clear();
	if (file.is_open())
	{
		if (fileReadLine(file, tab, 2))
		{
			fileInfo.push_back(tab[0]);
			fileInfo.push_back(tab[1]);
			//std::cout << "Zczytalem linijke 1 " << std::endl;
			//std::cout << "zczytalem linijke: " << tab[0] << tab[1] << tab[2] << std::endl;
			int numOfEdges = tab[0];
			for (int i = 0; i < numOfEdges; i++) {
				if (fileReadLine(file, tab, 3))
				{
					fileInfo.push_back(tab[0]);
					fileInfo.push_back(tab[1]);
					fileInfo.push_back(tab[2]);
				}
			}
		}
		else {
			file.close();
		}
	}
	file.close();
	return fileInfo;
}
std::vector<int> FileReader::readDataFromFileSP(std::string filename)
{
	std::ifstream file;
	//std::cout << "Wszedlem do funkcji" << std::endl;
	int tab[3];
	file.open(filename);
	//std::cout << "Otworzylem plik";
	fileInfo.clear();
	if (file.is_open())
	{
		if (fileReadLine(file, tab, 3))
		{
			fileInfo.push_back(tab[0]);
			fileInfo.push_back(tab[1]);
			fileInfo.push_back(tab[2]);
			int numOfEdges = tab[0];
			for (int i = 0; i < numOfEdges; i++) {
				if (fileReadLine(file, tab, 3))
				{
					fileInfo.push_back(tab[0]);
					fileInfo.push_back(tab[1]);
					fileInfo.push_back(tab[2]);
				}
			}
		}
		else {
			file.close();
		}
	}
	file.close();
	return fileInfo;
}
bool FileReader::fileReadLine(std::ifstream& file, int tab[], int size)
{
	std::string s;
	getline(file, s);

	if (file.fail() || s.empty())
		return(false);

	std::istringstream in_ss(s);

	for (int i = 0; i < size; i++)
	{
		in_ss >> tab[i];
		if (in_ss.fail())
			return(false);
	}
	return(true);
}
