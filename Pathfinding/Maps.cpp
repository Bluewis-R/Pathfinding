#include "Maps.h"


std::vector<std::vector<int>> Maps::NewMap(int _i)
{
	std::vector<std::vector<int>> tempMap;
	m_maps.push_back(tempMap);
	return m_maps.back();
}
