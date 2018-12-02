#include "NNetwork.h"
#include "Maps.h"

NNetwork::NNetwork()
{
	srand(time((unsigned)NULL));
}

//	This fucntion creates the four chromosomes
//	needed and randomises the instruction data
void NNetwork::CreateChromosomes()																																		//	NNETWORK
{																																																			//	
	for (int i = 0; i < 4; i++)																																					//	
	{																																																		//	
		chromosome temp;																																									//	
		m_chromosomes.push_back(temp);																																		//	
		m_chromosomes.at(i).m_instructions = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };					//	
																																																			//	
		for (int j = 0; j < m_chromosomes.at(i).m_instructions.size(); j++)																//	
		{																																																	//	
			m_chromosomes.at(i).m_instructions.at(j) = rand() % 4;																					//	
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


float NNetwork::FitnessMethod1(chromosome _chromo, std::vector<std::vector<int>>* _map)								//	CALCULATING FITNESS
{																																																			//
	for (int i = 0; i < _map->size(); i++)																															//	Cycling through the mpa to find start and end point.
	{																																																		//	
		for (int j = 0; j < _map->at(i).size(); j++)																											//	
		{																																																	//	
			if (_map->at(i).at(j) = 2)																																			//	
			{																																																//	
				m_startPoint.x = i;																																						//	
				m_startPoint.y = j;																																						//	
			}																																																//	
			if (_map->at(i).at(j) = 3)																																			//	
			{																																																//	
				m_endPoint.x = i;																																							//	
				m_endPoint.y = j;																																							//	
			}																																																//	
		}																																																	//	
	}																																																		//	
	_chromo.m_currentPos = m_startPoint;																																				//	
																																																			//	
	for (int i = 0; i < _chromo.m_instructions.size(); i++)																							//	for every m_instruction in _chromo 
	{
		//calculating m_nextPos
		switch (_chromo.m_instructions.at(i))
		{
		case 0:			//	UP
		{
			_chromo.m_nextPos.y++;
		}	
		break;
		case 1:			//	RIGHT
		{
			_chromo.m_nextPos.x++;
		}
		break;
		case 2:			//	DOWN
		{
			_chromo.m_nextPos.y--;
		}
		break;
		case 3:			//	LEFT
		{
			_chromo.m_nextPos.x--;
		}
		break;
		}

		// is the next pos in a wall

		if (_map->at(_chromo.m_nextPos.x).at(_chromo.m_nextPos.y))
		{
			_chromo.m_currentPos = _chromo.m_nextPos;
		}
	}








	//	fitness = 1 / (leagalfitness(x+y) 1)


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