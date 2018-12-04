#include <vector>
#include <string>
#include <random>
#include <time.h>
#include <vector>

#include <iostream>

class Maps;

struct coord
{
	int x = 0;
	int y = 0;
};							

struct chromosome															//	STUCTURE OF m_instructions	
{																							/*																	*/		
	std::vector<int> m_instructions;						/*							 /|\								*/
	float m_fitness;														/*								0									*/
	int m_x= 0;																	/*						<-3		1->							*/
	int m_y = 0;																/*								2									*/
	coord m_currentPos;													/*							 \|/								*/
	coord m_nextPos;														//
};																		

// this is the structure for the nodes in the open and closed lists
struct node
{
	float m_value;
	node* m_next;
};  	

class NNetwork
{
private:
	std::vector<chromosome> m_chromosomes;
	coord m_startPoint;
	coord m_endPoint;


public:
	NNetwork();
	void CreateChromosomes();
	float CalculateFitnessMethod1(chromosome _chromo);
	float FitnessMethod1(chromosome _chromo, std::vector<std::vector<int>>* _map);
	chromosome GetChromosome(int _i) { return m_chromosomes.at(_i); }
};



