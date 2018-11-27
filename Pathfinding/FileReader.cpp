#include "FileReader.h"

FileReader::FileReader(std::string _path)
{
	m_filePath = _path;

}

void FileReader::ReadFile(std::string _path)
{
	m_file.open(_path);
	// error checking needed?


	char tempChar;
	int tempSize[2]{ 0, 0 };

	std::vector<char> data;
	while (m_file.get(tempChar))
	{
		data.push_back(tempChar-48);
	}

	//finding the size of the layout
	for (int i = 0,k = 0; i < 2; i++)
	{
		if ((int)data[k+1] > 0)
		{
			tempSize[k+i] += data[k] * 10;
			tempSize[k+i] += data[k + 1];
			k += 3;
		}
		else
		{
			tempSize[k+i] += data[k];
			k += 2;
		}
	}


	tempSize[0] = (int)data[0];
	tempSize[1] = (int)data[1];

	for (int i = 2; i < tempSize[0]; i++)
	{
		for (int j = 0; j < tempSize[1]; j++)
		{
			m_layout[i].push_back(data[(i*tempSize[1])+j]);
		}
	}
	std::cout << "tesy" << std::endl;

	/*
	for (int i = 0; i< ; i++)
	{

	}
	*/

}
