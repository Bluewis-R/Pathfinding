#include "Maps.h"

//	This make space for a map in the vector
//	and returns a pointer to the location.
std::vector<std::vector<int>>* Maps::NewMap(int _i)
{
	std::vector<std::vector<int>>* tempMap = new std::vector<std::vector<int>>();
	m_maps->push_back(tempMap);
	return m_maps->back();
}