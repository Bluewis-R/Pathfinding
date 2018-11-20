#include "NNetwork.h"
#include <random>
#include <time.h>

NNetwork::NNetwork()
{
	srand(time((unsigned)NULL));
}

//	This fucntion creates the four chromosomes
//	needed and randomises the incstruction data
void NNetwork::CreateChromosomes()
{
	for (int i = 0; i < 4; i++)
	{
		chromosome temp;
		chromosomes.push_back(temp);

		for (int j = 0; j < 16; j++)
		{
			if (rand() % 2)
			{
				chromosomes[i].m_instructions[j] = 0;
			}
			else
			{
				chromosomes[i].m_instructions[j] = 1;
			}
		}
	}
}

//	this adds to the m_x and m_y value of the 
float CalculateFitnessMethod1(chromosome chromo)
{
	for (int i = 0; i < 16; i+2)
	{
		if (chromo.m_instructions[i+1])	// if the second value is one 
		{
			chromo.m_x = (-1)*i;
		}
		else
		{
			chromo.m_y = (-1)*i;
		}
	}

	// find the differance between start and final.






}