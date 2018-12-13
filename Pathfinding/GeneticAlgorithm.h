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
//	struscture of the chromosome //0 = top, 1 = right, 2 = bottom, 3 = left
struct chromosome
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
	std::vector<chromosome> m_chromosomes;
	coord m_startPoint;
	coord m_endPoint;
	bool m_goal;
	chromosome m_endChromosome;


public:
	GeneticAlgorithm(std::vector<std::vector<std::vector<int>>*>* _map);
	bool GeneticAlgorithm1();
	void CreateChromosomes();
	std::vector<chromosome>* GetChromosomes() { return &m_chromosomes; }
	void FitnessMethod1();
	chromosome GetChromosome(int _i) { return m_chromosomes.at(_i); }
	void Draw(std::vector<std::vector<int>>* _map, chromosome _chromo);
	void Breed();
	chromosome CalculateIndividual();

	void CreateNewChromosomes();
	void DeleteChromosomes();

};



