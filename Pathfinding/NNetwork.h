#include <vector>
#include <string>

struct chromosome
{
	std::string m_instructions;
	float m_fitness;
	int m_x= 0;
	int m_y = 0;
};

class NNetwork
{
private:
	std::vector<chromosome> chromosomes;

public:
	NNetwork();
	void CreateChromosomes();
	float CalculateFitnessMethod1(chromosome _chromo);


};



