#include <vector>


class Maps
{
private:
	std::vector<std::vector<std::vector<int>>*> m_maps;

public:
	void SetVector();
	std::vector<std::vector<int>>* GetMaps(int _i){ return m_maps.at(_i); }

};