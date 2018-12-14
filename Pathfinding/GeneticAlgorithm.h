#include <vector>
#include <string>
#include <random>
#include <time.h>
#include <vector>

#include <iostream>

#include <exception>


class Maps;

struct coord
{
	int x = 0;
	int y = 0;
};

//	struscture of the gene //0 = top, 1 = right, 2 = bottom, 3 = left
struct gene
{
	std::vector<int> m_instructions;
	float m_fitness = 0;
	int m_x = 0;
	int m_y = 0;
	coord m_currentPos;
	coord m_nextPos;
};																		

class GeneticAlgorithm
{
private:
	std::vector<std::vector<std::vector<int>>*>* m_maps;
	std::vector<std::vector<int>>* m_currentMap;
	std::vector<gene> m_genes;
	coord m_startPoint;
	coord m_endPoint;
	bool m_goal;
	gene m_endGene;


public:
	GeneticAlgorithm(std::vector<std::vector<std::vector<int>>*>* _map);
	bool GeneticAlgorithm1();
	void CreateGenes();
	std::vector<gene>* GetGenes() { return &m_genes; }
	void FitnessMethod1();
	gene GetGene(int _i) { return m_genes.at(_i); }
	void Draw(std::vector<std::vector<int>>* _map, gene _gene);
	void Breed();
	gene CalculateIndividual();

	void CreateNewGenes();
	void PurgeGenes();
	gene GetEndGene() { return m_endGene; }
};



