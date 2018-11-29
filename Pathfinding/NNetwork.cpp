#include "NNetwork.h"

#include "Maps.h"

NNetwork::NNetwork()
{
	srand(time((unsigned)NULL));
}

//	This fucntion creates the four chromosomes
//	needed and randomises the instruction data
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
float CalculateFitnessMethod1(chromosome _chromo)
{
	for (int i = 0; i < 16; i+2)
	{

	}

	// find the differance between start and final.
	//_chromo. = (chromo.m_x + chromo.m_y);


	return 0.0f;
}

float NNetwork::FitnessMethod1(chromosome _chromo)
{









	return 0.0f;
}




/*
if (_chromo.m_instructions[i + 1])	// if the second value is one 
{
	_chromo.m_x = (-1)*i;
}
else
{
	_chromo.m_y = (-1)*i;
}

*/