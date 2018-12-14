#include "FileReader.h"
#include "Maps.h"


FileReader::FileReader(std::string _path)
{
	m_filePath = _path;
}

//	FILEREADER
//	This function take the path of the file
//	and the pointer to the vector it is to
//	be stored in.
void FileReader::ReadFile(std::string _path, std::vector<std::vector<int>>* _map)
{
	m_file.open(_path);
	if (m_file.is_open() == false)
	{
		throw std::exception();
	}

	char tempChar;
	std::array<int, 2> tempSize = { 0,0 };
	
	std::vector<char> data;
	std::vector<int> map;

	//	Getting data from the file.
	while (m_file.get(tempChar))
	{
		data.push_back(tempChar - 48);
	}
	m_file.close();


	//	The size of the map's x and y are checked
	//	for shitespace betweeen them and stored
	//	in an array.
	int k = 0;
	for (int i = 0; i < 2; i++)
	{
		if (k < data.size())
		{
			if ((int)data.at(k + 1) >= 0)
			{
				tempSize.at(i) += data.at(k) * 10;
				tempSize.at(i) += data.at(k + 1);
				k += 3;
			}
			else
			{
				tempSize.at(i) += data.at(k);
				k += 2;
			}
		}
	}
	//	The data is put into a temporary vector
	//	without whitespace.
	for (; k < data.size(); k++)
	{
		if ((int)data.at(k) >= 0)
		{
			map.push_back((int)data.at(k));
		}
	}

	//	Itterating though the data and formating it into
	//	a vector that is push back into a vector.
	for (int i = 0, k = 0; i < tempSize.at(1); i++)	//	y
	{
		std::vector<int> temp;
		for (int j = 0; j < tempSize.at(0); j++)	//	x
		{
			temp.push_back(map.at(k));
			k++;
		}
		_map->push_back(temp);
	}
}