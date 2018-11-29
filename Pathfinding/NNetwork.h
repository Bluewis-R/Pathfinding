#include <vector>
#include <string>
#include <random>
#include <time.h>

class Maps;

struct chromosome
{
	std::string m_instructions;
	float m_fitness;
	int m_x= 0;
	int m_y = 0;
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
	std::vector<chromosome> chromosomes;
	Maps* m_map;

public:
	NNetwork();
	void CreateChromosomes();
	float CalculateFitnessMethod1(chromosome _chromo);
	float FitnessMethod1(chromosome _chromo);

};



