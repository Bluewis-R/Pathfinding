#include <vector>
#include <string>
#include <random>
#include <time.h>
#include <vector>

class Maps;

struct coord
{
	int x = 0;
	int y = 0;
};

struct chromosome							//		STUCTURE OF m_instructions	
{											/*										*/		
	std::vector<int> m_instructions;		/*				    /|\					*/
	float m_fitness;						/*					 0					*/
	int m_x= 0;								/*				<-3		1->				*/
	int m_y = 0;							/*					 2					*/
};											/*				    \|/					*/

// this is the structure for the nodes in the open and closed lists
struct node
{
	float m_value;
	node* m_next;
};

class NNetwork
{
private:
	std::vector<chromosome> chromosomes;
	coord m_startPoint;
	coord m_endPoint;
	coord m_currentPos;


public:
	NNetwork();
	void CreateChromosomes();
	float CalculateFitnessMethod1(chromosome _chromo);
	float FitnessMethod1(chromosome _chromo, std::vector<std::vector<int>>* _map);

};



