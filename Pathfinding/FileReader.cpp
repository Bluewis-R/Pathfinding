#include "FileReader.h"
#include "Maps.h"

FileReader::FileReader(std::string _path)
{
	m_filePath = _path;
}

void FileReader::ReadFile(std::string _path, std::vector<std::vector<int>>* _map)
{
	m_file.open(_path);
	// error checking needed?


	char tempChar;
	int tempSize[2]{ 0, 0 };

	std::vector<char> data;
	std::vector<int> map;
	//	importing the raw data
	while (m_file.get(tempChar))
	{
		data.push_back(tempChar-48);
	}

	//	Find the size of the data set and
	//	the postion that the data starts from
	int k = 0;
	for (int i = 0; i < 2; i++)
	{
		if ((int)data[k+1] >= 0)
		{
			tempSize[k+i] += data[k] * 10;
			tempSize[k+i] += data[k + 1];
			k += 3;
		}
		else
		{
			tempSize[i] += data[k];
			k += 2;
		}
	}

	for (; k < data.size(); k++)
	{
		if ((int)data[k] >= 0)
		{
			map.push_back((int)data[k]);
		}
	}

	//	itterating though the data and formating
	//	it into a vector that is push back into a vector
	for (int i = 0; i < tempSize[0]; i++)
	{
		std::vector<int> temp;
		for (int j = 0; j < tempSize[1]; j++)
		{
			temp.push_back(map[(i*tempSize[0]) + j]);
			k++;
		}
		_map->push_back(temp);
	}

	std::cout << "hello" << std::endl;
}
