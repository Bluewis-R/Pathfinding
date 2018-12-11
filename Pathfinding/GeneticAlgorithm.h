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

struct chromosome																																							//	STUCTURE OF m_instructions		
{																																															/*																	*/		
	std::vector<int> m_instructions = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };				/*							 /|\								*/
	float m_fitness = 0;																																						/*							  0									*/
	int m_x= 0;																																									/*						<-3		1->							*/
	int m_y = 0;																																								/*								2									*/
	coord m_currentPos;																																					/*							 \|/								*/
	coord m_nextPos;																																						//
};																		

// this is the structure for the nodes in the open and closed lists
struct node
{
	float m_value;
	node* m_next;
};  	

class GeneticAlgorithm
{
private:
	std::vector<std::vector<std::vector<int>>*>* m_maps;
	std::vector<std::vector<int>>* m_currentMap;
	std::vector<chromosome> m_chromosomes;
	coord m_startPoint;
	coord m_endPoint;


public:
	GeneticAlgorithm(std::vector<std::vector<std::vector<int>>*>* _map);
	void GeneticAlgorithm1();
	void CreateChromosomes();
	void FitnessMethod1(chromosome &_chromo);
	chromosome GetChromosome(int _i) { return m_chromosomes.at(_i); }
	void Draw(std::vector<std::vector<int>>* _map, chromosome _chromo);
	void Breed();
	chromosome CalculateIndividual();

};



