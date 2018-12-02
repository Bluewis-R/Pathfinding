#include "Maps.h"


std::vector<std::vector<int>>* Maps::NewMap(int _i)
{
	std::vector<std::vector<int>>* tempMap = new std::vector<std::vector<int>>();
	m_maps.push_back(tempMap);
	delete tempMap;
	return m_maps.back();
}
