#include "GeneticAlgorithm.h"
#include "Maps.h"



GeneticAlgorithm::GeneticAlgorithm(std::vector<std::vector<std::vector<int>>*>* _maps)
{
	srand(time((unsigned)NULL));

	m_maps = _maps;
	m_currentMap = m_maps->at(0);
}

bool GeneticAlgorithm::GeneticAlgorithm1()
{
	//for (int i = 0; i < m_chromosomes.size(); i++)																											//	loops through all _choromosomes and
	//{																																																		//	creates calculates there fitness value
	
	//}
	Breed();
	CreateNewChromosomes();
	DeleteChromosomes();
	FitnessMethod1();

	if (m_goal)
	{
		return false;
	}
	return true;
}

void GeneticAlgorithm::CreateChromosomes()																														//	This fucntion creates the four chromosomes
{																																																			//	needed and randomises the instruction data	
	for (int i = 0; i < 4; i++)																																					//	
	{																																																		//	
		chromosome temp;																																									//	
		m_chromosomes.push_back(temp);																																		//	
																																																			//	
		for (int j = 0; j < 16; j++)																//	
		{																																																	//	
			m_chromosomes.at(i).m_instructions.push_back(rand() % 4);																					//	
		}
	}
}

void GeneticAlgorithm::FitnessMethod1()																						//	CALCULATING FITNESS
{							
	for (int c = 0; c < m_chromosomes.size(); c++)
	{
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


		m_chromosomes.at(c).m_currentPos = m_startPoint;																																//	This section calculates the next position 
																																																				//	and then checks and rejects positions
		for (int i = 0; i < m_chromosomes.at(c).m_instructions.size(); i++)																							//	that collide with "walls"
		{																																																		//	
																																																				//calculating m_nextPos
			m_chromosomes.at(c).m_nextPos = m_chromosomes.at(c).m_currentPos;
			switch (m_chromosomes.at(c).m_instructions.at(i))
			{
			case 0:			//	UP
			{
				m_chromosomes.at(c).m_nextPos.x--;
			}
			break;
			case 1:			//	RIGHT
			{
				m_chromosomes.at(c).m_nextPos.y++;
			}
			break;
			case 2:			//	DOWN
			{
				m_chromosomes.at(c).m_nextPos.x++;
			}
			break;
			case 3:			//	LEFT
			{
				m_chromosomes.at(c).m_nextPos.y--;
			}
			break;
			}
			// is the next pos in a wall

			if (m_chromosomes.at(c).m_nextPos.x >= 0 && m_chromosomes.at(c).m_nextPos.y >= 0 &&																								//	Checking the bounds of the map vector
				m_chromosomes.at(c).m_nextPos.x < m_currentMap->size() && m_chromosomes.at(c).m_nextPos.y < m_currentMap->at(0).size())					//	to prvent access violations
			{
				if (m_currentMap->at(m_chromosomes.at(c).m_nextPos.x).at(m_chromosomes.at(c).m_nextPos.y) == 0)																	//	"Wall checking" 
				{
					m_chromosomes.at(c).m_currentPos = m_chromosomes.at(c).m_nextPos;
				}
			}

		}
		//	calculating fitness
		float a = fabs(m_chromosomes.at(c).m_currentPos.x - (float)m_endPoint.x);
		float b = fabs(m_chromosomes.at(c).m_currentPos.y - (float)m_endPoint.y);
		m_chromosomes.at(c).m_fitness = 1.0f / ((float)a + (float)b + 1.0f);

		if (m_chromosomes.at(c).m_fitness == 1)
		{
			m_goal = true;
			m_endChromosome = m_chromosomes.at(c);
		}
	}
	
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


//	the chromosomes are then breed
void GeneticAlgorithm::Breed()																							
{
	//	creating an empty offsprings
	std::vector<chromosome> offspring;																													
	for (int i = 0; i < m_chromosomes.size(); i++)
	{
		chromosome c;
		offspring.push_back(c);
	}

	//	filling up offspring vector with the 'bred' ofspring
	for (int i = 0; i < m_chromosomes.size(); i += 2)
	{



		chromosome parent1, parent2;
		parent1 = CalculateIndividual();
		parent2 = CalculateIndividual();

		
			
		if ((double)rand() / (RAND_MAX + 1.0) < 0.9)
		{	
			//	finding the smaller size
			int k1 = (m_chromosomes.at(i).m_instructions.size())/2;
			int k2 = (m_chromosomes.at(i+1).m_instructions.size()) / 2;

			//	first section of the chromo
			for (int o = 0; o < k1; o++)
			{
				offspring.at(i).m_instructions.push_back(parent1.m_instructions.at(o));
			}
			for (int o = 0; o < k2; o++)
			{
				offspring.at(i+1).m_instructions.push_back(parent2.m_instructions.at(o));
			}
			//	second section of the chromo
			for (int o = k1; o < parent2.m_instructions.size(); o++)
			{
				offspring.at(i).m_instructions.push_back(parent2.m_instructions.at(o));
			}
			for (int o = k2; o < parent1.m_instructions.size(); o++)
			{
				offspring.at(i + 1).m_instructions.push_back(parent1.m_instructions.at(o));
			}	
		}
		else
		{
			offspring.at(i).m_instructions = parent1.m_instructions;
			offspring.at(i+1).m_instructions = parent2.m_instructions;
		}



	}




	//	setting offspring to chromosomes
	for (int i = 0; i < m_chromosomes.size(); i++)
	{
		m_chromosomes.at(i) = offspring.at(i);
	}
	//dsjhbd
	for (int q = 0; q < m_chromosomes.size(); q++)
	{
		if (m_chromosomes.at(q).m_instructions.size() < 8)
		{
			std::cout << "error";
		}
	}




	//	chance to add to the length of the chromosome
	for (int i = 0; i < m_chromosomes.size(); i++)
	{
		if ((double)rand() / (RAND_MAX + 1.0) < 0.0001)
		{
			m_chromosomes.at(i).m_instructions.push_back(rand() % 4);
			m_chromosomes.at(i).m_instructions.push_back(rand() % 4);
		}
	}



	//	mustation
	for (int i = 0; i < m_chromosomes.size(); i++)
	{
		for (int j = 0; j < m_chromosomes.at(i).m_instructions.size(); j++)
		{
			if ((double)rand() / (RAND_MAX + 1.0) < 0.1)
			{
				if (m_chromosomes.at(i).m_instructions.at(j) == 0 || m_chromosomes.at(i).m_instructions.at(j) == 1)
				{
					m_chromosomes.at(i).m_instructions.at(j) -= 2;
				}
				else
				{
					m_chromosomes.at(i).m_instructions.at(j) += 2;
				}
				
				//std::cout << "mutation of direction";
			}
		}
	}
}

chromosome GeneticAlgorithm::CalculateIndividual()
{
	std::vector<float> indiviuals;
	for (int i = 0; i < m_chromosomes.size(); i++)
	{
		float tempFloat = 0;
		for (int j = 0; j < i+1; j++)
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
	//(double)rand() / (RAND_MAX + 1.0) < 0.001);

	//float t = (totalFitness / abs(rand()));																											// BUG HERE*
	float t = totalFitness * (double)rand() / (RAND_MAX + 1.0);

	for (int i = 0; i < m_chromosomes.size(); i++)																								// calculating the idiviual
	{
		if (indiviuals.at(i) > t)
		{
			return m_chromosomes.at(i);
		}
	}
		throw std::exception();	
}	

//	randomly decides to create two new chromosomes or not
void GeneticAlgorithm::CreateNewChromosomes()
{
	if (((double)rand() / (RAND_MAX + 1.0)) < 0.0000001)
	{
		chromosome tempChromo;
		for (int j = 0; j < 16; j++)																//	
		{																																																	//	
			tempChromo.m_instructions.push_back(rand() % 4);																					//	
		}
		m_chromosomes.push_back(tempChromo);
		m_chromosomes.push_back(tempChromo);
	}
}

//	deletes a fraction of the chromosomes	('thanos' function)
void GeneticAlgorithm::DeleteChromosomes()
{
	if ((double)rand() / (RAND_MAX + 1.0) < 0.1)																						//	1/ (4 + 80) = 0.03125
	{
		for (int i = 0; i < m_chromosomes.size(); i++)
		{
			if (i%2)
			{
				for (int j = 0; j < m_chromosomes.at(i).m_instructions.size(); j++)
				{
					m_chromosomes.at(i).m_instructions.at(j) = rand() % 4;
				}
			}
		}
		//std::cout << "m_chromosomes.size()" << m_chromosomes.size() << std::endl;
	}
	

}