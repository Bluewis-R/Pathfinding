#include <fstream>
#include <string>
#include <iostream>
#include <vector>

class Maps;

class FileReader
{
private:
	std::fstream m_file;
	std::string m_filePath;
	std::vector<std::vector<int>> m_layout;

public:
	FileReader(std::string _path);
	void ReadFile(std::string _path, std::vector<std::vector<int>>* _map);
	
	

};