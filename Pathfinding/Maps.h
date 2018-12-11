#include <vector>


class Maps
{
private:
	std::vector<std::vector<std::vector<int>>*>* m_maps = new std::vector<std::vector<std::vector<int>>*>();

public:
	void SetVector();
	std::vector<std::vector<int>>* NewMap(int _i);
	std::vector<std::vector<int>>* GetMap(int _i){ return m_maps->at(_i); }
	std::vector<std::vector<std::vector<int>>*>* getMaps() {	return m_maps;	}

};