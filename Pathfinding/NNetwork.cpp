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
	for (int i = 0; i < 16; i + 2)
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
			if (_map->at(i).at(j) == 2)																																			//	
			{																																																//	
				m_startPoint.x = i;																																						//	
				m_startPoint.y = j;																																						//	
			}																																																//	
			if (_map->at(i).at(j) == 3)																																			//	
			{																																																//	
				m_endPoint.x = i;																																							//	
				m_endPoint.y = j;																																							//	
			}																																																//	
		}																																																	//	
	}																																																		//	
	_chromo.m_currentPos = m_startPoint;																																//	

	std::cout << "start Coord" << _chromo.m_currentPos.x << _chromo.m_currentPos.y << std::endl;				//
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

		Draw(_map, _chromo);






		// is the next pos in a wall

		if (_chromo.m_nextPos.x >= 0 && _chromo.m_nextPos.y >= 0 &&																			//	Checking the bounds of the map vector
			_chromo.m_nextPos.x <= _map->size() && _chromo.m_nextPos.y <= _map->at(0).size())							//	to prvent access violations
		{
			if (_map->at(_chromo.m_nextPos.x).at(_chromo.m_nextPos.y))																			//	"Wall checking" 
			{
				_chromo.m_currentPos = _chromo.m_nextPos;
			}
		}
	}
	std::cout << "End Coord" << _chromo.m_currentPos.x << _chromo.m_currentPos.y << std::endl;
		//	calculate fitness

		_chromo.m_fitness = 1.0f / (float)(abs(_chromo.m_currentPos.x - (float)m_endPoint.x) + abs((_chromo.m_currentPos.y - (float)m_endPoint.y) + 1));
		std::cout << "m_fitness : " << _chromo.m_fitness;

	return 0.0f;
}




void NNetwork::Draw(std::vector<std::vector<int>>* _map, chromosome _chromo)
{
	system("CLS");
	for (int i = 0; i < _map->size(); i++)
	{
		for (int j = 0; j < _map->at(0).size(); j++)
		{
			if (_chromo.m_currentPos.x == i && _chromo.m_currentPos.y == j)
			{
				std::cout << "* ";
				
				//prtin curretn pos
			}
			else
			{
				//pritn wall or empty
				std::cout << _map->at(i).at(j) << " ";
			}
		}
		std::cout << std::endl;
	}
	Sleep(100);
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