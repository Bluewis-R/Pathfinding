#include "FileReader.h"
#include "Maps.h"

FileReader::FileReader(std::string _path)
{
	m_filePath = _path;
}

void FileReader::ReadFile(std::string _path, std::vector<std::vector<int>>* _map)			//	FILEREADER
{																							//	
	m_file.open(_path);																		//	This function take the path of the file
	// error checking needed?																//	and the pointer to the vector it is to
																							//	
																							//	be stored in.
	char tempChar;																			//	The File is opened and is dumped into
	int tempSize[2]{ 0, 0 };																//	a temporary vector.
																							//	
	std::vector<char> data;																	//	The size of the map's x and y are stored
	std::vector<int> map;																	//	in an array and the starting point of
	//	importing the raw data																//	the map data is recorded.
	while (m_file.get(tempChar))															//	
	{																						//	Finaly the intergers are pushed back into a
		data.push_back(tempChar - 48);														//	a temporary vector that is pushed back into
	}																						//	Pointer of the loctaion of the Maps class.
	m_file.close();

	int k = 0;
	for (int i = 0; i < 2; i++)
	{
		if ((int)data[k + 1] >= 0)
		{
			tempSize[k + i] += data[k] * 10;
			tempSize[k + i] += data[k + 1];
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
}