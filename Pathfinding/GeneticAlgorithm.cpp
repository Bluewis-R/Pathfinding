#include "GeneticAlgorithm.h"
#include "Maps.h"



GeneticAlgorithm::GeneticAlgorithm(std::vector<std::vector<std::vector<int>>*>* _maps)
{
	srand(time((unsigned)NULL));

	m_maps = _maps;
	m_currentMap = m_maps->at(0);
}

void GeneticAlgorithm::GeneticAlgorithm1()
{
	for (int i = 0; i < m_chromosomes.size(); i++)																											//	loops through all _choromosomes and
	{																																																		//	creates calculates there fitness value
		FitnessMethod1(m_chromosomes.at(i));
	}
	Breed();
	//IncreaseChromosomes();

}

void GeneticAlgorithm::CreateChromosomes()																														//	This fucntion creates the four chromosomes
{																																																			//	needed and randomises the instruction data	
	for (int i = 0; i < 4; i++)																																					//	
	{																																																		//	
		chromosome temp;																																									//	
		m_chromosomes.push_back(temp);																																		//	
																																																			//	
		for (int j = 0; j < m_chromosomes.at(i).m_instructions.size(); j++)																//	
		{																																																	//	
			m_chromosomes.at(i).m_instructions.at(j) = rand() % 4;																					//	
		}
	}
}

void GeneticAlgorithm::FitnessMethod1(chromosome &_chromo)																						//	CALCULATING FITNESS
{																																																			//
	for (int i = 0; i < m_currentMap->size(); i++)																											//	Cycling through the mpa to find start and end point.
	{																																																		//	
		for (int j = 0; j < m_currentMap->at(i).size(); j++)																							//	
		{																																																	//	
			if (m_currentMap->at(i).at(j) == 2)																															//	
			{																																																//	
				m_startPoint.x = i;																																						//	
				m_startPoint.y = j;																																						//	
			}																																																//	
			if (m_currentMap->at(i).at(j) == 3)																															//	
			{																																																//	
				m_endPoint.x = i;																																							//	
				m_endPoint.y = j;																																							//	
			}																																																//	
		}																																																	//	
	}


	_chromo.m_currentPos = m_startPoint;																																//	This section calculates the next position 
																																																			//	and then checks and rejects positions
	for (int i = 0; i < _chromo.m_instructions.size(); i++)																							//	that collide with "walls"
	{																																																		//	
		//calculating m_nextPos
		_chromo.m_nextPos = _chromo.m_currentPos;
		switch (_chromo.m_instructions.at(i))
		{
		case 0:			//	UP
		{
			_chromo.m_nextPos.x--;
		}
		break;
		case 1:			//	RIGHT
		{
			_chromo.m_nextPos.y++;
		}
		break;
		case 2:			//	DOWN
		{
			_chromo.m_nextPos.x++;
		}
		break;
		case 3:			//	LEFT
		{
			_chromo.m_nextPos.y--;
		}
		break;
		}


		// is the next pos in a wall

		if (_chromo.m_nextPos.x >= 0 && _chromo.m_nextPos.y >= 0 &&																								//	Checking the bounds of the map vector
			_chromo.m_nextPos.x < m_currentMap->size() && _chromo.m_nextPos.y < m_currentMap->at(0).size())					//	to prvent access violations
		{
			if (m_currentMap->at(_chromo.m_nextPos.x).at(_chromo.m_nextPos.y) == 0)																	//	"Wall checking" 
			{
				_chromo.m_currentPos = _chromo.m_nextPos;
			}
		}
		/*
		for (int i = 0; i < _chromo.m_instructions.size(); i++)
		{
			std::cout << _chromo.m_instructions.at(i);
		}
		*/
		// BUG TESTING
		//std::cout << "Instruction(" << i << ") : " << _chromo.m_instructions.at(i) << std::endl;
		//std::cout << "Current pos : " << _chromo.m_currentPos.x << ", " << _chromo.m_currentPos.y << std::endl;
		//std::cout << "Next pos : " << _chromo.m_nextPos.x << ", " << _chromo.m_nextPos.y;
		//Draw(_map, _chromo);
		//std::cout << std::endl;
	}
		//	calculating fitness
		_chromo.m_fitness = 1.0f / (float)(abs(_chromo.m_currentPos.x - (float)m_endPoint.x) + abs((_chromo.m_currentPos.y - (float)m_endPoint.y) + 1));
		std::cout << "m_fitness : " << _chromo.m_fitness;

	
}

//	this is a function for debugging purposes that draws the currecnt pos
//	for every int in a chromosomes instruction
void GeneticAlgorithm::Draw(std::vector<std::vector<int>>* _map, chromosome _chromo)
{
	std::cout << std::endl;
	for (int i = 0; i < m_currentMap->size(); i++)
	{
		for (int j = 0; j < m_currentMap->at(0).size(); j++)
		{
			if (_chromo.m_currentPos.x == i && _chromo.m_currentPos.y == j)
			{
				std::cout << "* ";
				
				//priting current pos
			}
			else
			{
				//pritn wall or empty
				std::cout << m_currentMap->at(i).at(j) << " ";
			}
		}
		std::cout << std::endl;
	}
}


//	the chromosomes are then breed																															//
void GeneticAlgorithm::Breed()																							
{
	std::vector<chromosome> offspring;																														//	creatiing an temporary array chro
	for (int i = 0; i < m_chromosomes.size(); i++)
	{
		chromosome c;
		offspring.push_back(c);
	}
																																																//	selecting indiviuals 
	for (int i = 0; i < m_chromosomes.size(); i += 2)																							//	this cycles through all of the chromosomes
	{
			
		chromosome parent1 = CalculateIndividual();
		chromosome parent2 = CalculateIndividual();

			
		if ((double)rand() / (RAND_MAX + 1.0) < 0.7)																								//	The cross overrate is hard coded at this point in time
		{																																														//	
			for (int o = 0; o < 8; o++)																																//	
			{																																													//	This section takes the first half of both parents 
				offspring.at(i).m_instructions.at(o) = parent1.m_instructions.at(o);										//	and applies them to the first half of two offspring,
				offspring.at(i+1).m_instructions.at(o) = parent2.m_instructions.at(o);									//	then applies the second half of the first parent
			}																																													//	and aplies it to the SECOND ofspring and
			for (int o = 7; o < 15; o++)																															//	vice versa of ofpring2
			{																																													//
				offspring.at(i).m_instructions.at(o) = parent2.m_instructions.at(o);										//	
				offspring.at(i + 1).m_instructions.at(o) = parent1.m_instructions.at(o);								//	
			}																																													//	
		}																																														//
		else
		{
			offspring.at(i).m_instructions = parent1.m_instructions;
			offspring.at(i+1).m_instructions = parent2.m_instructions;
		}

		
		for (int j = 0; j < m_chromosomes.size(); j++)																							//	Setting Offsprings
		{																																														//	
			m_chromosomes.at(j) = offspring.at(i);																										//	
		}																																														//	

		for (int j = 0; j < m_chromosomes.at(i).m_instructions.size(); j++)
		{	
			if ((double)rand() / (RAND_MAX + 1.0) < 0.001)
			{	
				m_chromosomes.at(i).m_instructions.at(j) = rand()%4;																		//	Mutation
			}																																													//
		}
	}
}

chromosome GeneticAlgorithm::CalculateIndividual()
{
	std::vector<float> indiviuals;
	for (int i = 0; i < m_chromosomes.size(); i++)
	{
		float tempFloat = 0;
		for (int j = 0; j < i; j++)
		{
			tempFloat += m_chromosomes.at(j).m_fitness;
		}
		indiviuals.push_back(tempFloat);
	}
	float totalFitness = 0;																																				//	calculating all of the fitnessess
	for (int i = 0; i < m_chromosomes.size(); i++)															
	{
		totalFitness += m_chromosomes.at(i).m_fitness;
	}
	float t = (totalFitness / abs(rand()));									// BUG HERE*


	for (int i = 0; i < m_chromosomes.size(); i++)																								// calculating the idiviual
	{
		if (t < indiviuals.at(i))
		{
			return m_chromosomes.at(i);
		}
	}
}	

/*
float t = (totalFitness / abs(rand()));
if (t <= 0 && t >)
{

}
	*/