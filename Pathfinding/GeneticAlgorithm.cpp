#include "GeneticAlgorithm.h"
#include "Maps.h"



GeneticAlgorithm::GeneticAlgorithm(std::vector<std::vector<std::vector<int>>*>* _maps)
{
	// Seeds time.
	srand(time((unsigned)NULL));

	m_maps = _maps;
	m_currentMap = m_maps->at(0);
}

bool GeneticAlgorithm::GeneticAlgorithm1()
{
	Breed();
	CreateNewGenes();
	PurgeGenes();
	FitnessMethod1();

	if (m_goal)
	{
		return false;
	}
	return true;
}

//	This randomly generates four random genes
//	needed and randomises the instruction data.
void GeneticAlgorithm::CreateGenes()
{
	for (int i = 0; i < 4; i++)
	{
		gene temp;
		m_genes.push_back(temp);

		for (int j = 0; j < 16; j++)
		{
			m_genes.at(i).m_instructions.push_back(rand() % 4);	
		}
	}
}

void GeneticAlgorithm::FitnessMethod1()																						//	CALCULATING FITNESS
{
	//	For every gene in gene.
	for (int g = 0; g < m_genes.size(); g++)
	{
		//	Cycling through the map to find start and end point.
		for (int i = 0; i < m_currentMap->size(); i++)		//	y
		{
			for (int j = 0; j < m_currentMap->at(i).size(); j++)	//	x
			{
				//	Starting Point.
				if (m_currentMap->at(i).at(j) == 2)
				{
					m_startPoint.y = i;
					m_startPoint.x = j;
				}
				//	Ending Point.
				if (m_currentMap->at(i).at(j) == 3)
				{
					m_endPoint.y = i;
					m_endPoint.x = j;
				}
			}																																																	
		}

		//	Taking the next position from the chromosomes
		//	and the setting next position.
		m_genes.at(g).m_currentPos = m_startPoint;

		for (int i = 0; i < m_genes.at(g).m_instructions.size(); i++)
		{
			m_genes.at(g).m_nextPos = m_genes.at(g).m_currentPos;
			switch (m_genes.at(g).m_instructions.at(i))
			{
			case 0:			//	UP
			{
				m_genes.at(g).m_nextPos.y--;
			}
			break;
			case 1:			//	RIGHT
			{
				m_genes.at(g).m_nextPos.x++;
			}
			break;
			case 2:			//	DOWN
			{
				m_genes.at(g).m_nextPos.y++;
			}
			break;
			case 3:			//	LEFT
			{
				m_genes.at(g).m_nextPos.x--;
			}
			break;
			}
			// Checking if the next position is in a wall or out side of the map.
			if (m_genes.at(g).m_nextPos.x >= 0 && m_genes.at(g).m_nextPos.y >= 0 &&
				m_genes.at(g).m_nextPos.y < m_currentMap->size() && m_genes.at(g).m_nextPos.x < m_currentMap->at(0).size())
			{
				if (m_currentMap->at(m_genes.at(g).m_nextPos.y).at(m_genes.at(g).m_nextPos.x) == 0 || 
						m_currentMap->at(m_genes.at(g).m_nextPos.y).at(m_genes.at(g).m_nextPos.x) == 2 ||
						m_currentMap->at(m_genes.at(g).m_nextPos.y).at(m_genes.at(g).m_nextPos.x) == 3)

				{
					m_genes.at(g).m_currentPos = m_genes.at(g).m_nextPos;
				}
			}
		}
		//	Calculates fitness.
		float a = fabs(m_genes.at(g).m_currentPos.x - (float)m_endPoint.x);
		float b = fabs(m_genes.at(g).m_currentPos.y - (float)m_endPoint.y);
		m_genes.at(g).m_fitness = 1.0f / ((float)a + (float)b + 1.0f);

		if (m_genes.at(g).m_fitness == 1)
		{
			m_goal = true;
			m_endGene = m_genes.at(g);
		}
	}
	
}

//	This is a function for debugging purposes that draws the current pos
//	for every int in a genes instruction.
void GeneticAlgorithm::Draw(std::vector<std::vector<int>>* _map, gene _gene)
{
	std::cout << std::endl;
	for (int i = 0; i < m_currentMap->size(); i++)
	{
		for (int j = 0; j < m_currentMap->at(0).size(); j++)
		{
			if (_gene.m_currentPos.x == i && _gene.m_currentPos.y == j)
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


//	Breeding genes through a chanced crossover
//	and then have chances to extend gene length
//	and mutate.
void GeneticAlgorithm::Breed()																							
{
	//	creating an empty offsprings
	std::vector<gene> offspring;																													
	for (int i = 0; i < m_genes.size(); i++)
	{
		gene c;
		offspring.push_back(c);
	}

	//	Creating 'offspring' and calculated if genes 
	//	should go through a crossover operation at
	//	an increased by higher 'm_fitness' values.
	for (int i = 0; i < m_genes.size(); i += 2)
	{



		gene parent1, parent2;
		parent1 = CalculateIndividual();
		parent2 = CalculateIndividual();


		//	Calculating the size of the genes
		int k1 = (m_genes.at(i).m_instructions.size()) / 2;
		int k2 = (m_genes.at(i + 1).m_instructions.size()) / 2;

		if ((double)rand() / (RAND_MAX + 1.0) < 0.9 && !( k1 > k2*2 || k2 > k1 * 2))
		{
			//	First section of the gene
			for (int o = 0; o < k1; o++)
			{
				offspring.at(i).m_instructions.push_back(parent1.m_instructions.at(o));
			}
			for (int o = 0; o < k2; o++)
			{
				offspring.at(i + 1).m_instructions.push_back(parent2.m_instructions.at(o));
			}
			//	Reversed second section of the gene
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
			offspring.at(i + 1).m_instructions = parent2.m_instructions;
		}
	}
	//	Sets the temporary 'offspring' to the
	//	'm_genes' vector.
	for (int i = 0; i < m_genes.size(); i++)
	{
		m_genes.at(i) = offspring.at(i);
	}

	//	A chance to add two chromosome to the end a gene.
	//	This is done in twos to alleviate errros in 'Breed()'. 
	for (int i = 0; i < m_genes.size(); i++)
	{
		if ((double)rand() / (RAND_MAX + 1.0) < 0.00001)
		{
			m_genes.at(i).m_instructions.push_back(rand() % 4);
			m_genes.at(i).m_instructions.push_back(rand() % 4);
		}
	}
	
	//	This function deletes a chromosome in a gene randomly to 
	//	act as random mutation.
	for (int i = 0; i < m_genes.size(); i++)
	{
		for (int j = 0; j < m_genes.at(i).m_instructions.size(); j++)
		{
			if ((double)rand() / (RAND_MAX + 1.0) < 0.01)
			{
				if (m_genes.at(i).m_instructions.at(j) == 0 || m_genes.at(i).m_instructions.at(j) == 1)
				{
					m_genes.at(i).m_instructions.at(j) += 2;
				}
				else
				{
					m_genes.at(i).m_instructions.at(j) -= 2;
				}
			}
		}
	}
}

gene GeneticAlgorithm::CalculateIndividual()
{
	//	creating an vector of floats the then is
	//	filled out with CUMULATIVE total of the 
	//	m_fitness ratings
	std::vector<float> indiviuals;
	for (int i = 0; i < m_genes.size(); i++)
	{
		float tempFloat = 0;
		for (int j = 0; j < i+1; j++)
		{
			tempFloat += m_genes.at(j).m_fitness;
		}
		indiviuals.push_back(tempFloat);
	}
	//	Calculating total fitness.
	float totalFitness = 0;
	for (int i = 0; i < m_genes.size(); i++)															
	{
		totalFitness += m_genes.at(i).m_fitness;
	}
	
	float t = totalFitness * (double)rand() / (RAND_MAX + 1.0);

	// Returning the randomly selected gene
	for (int i = 0; i < m_genes.size(); i++)
	{
		if (indiviuals.at(i) > t)
		{
			return m_genes.at(i);
		}
	}
		throw std::exception();	
}	

//	Decides to create two new genes at a random rate. This
//	is done in twos to have limited error with the breeding 
//	fucntion.
void GeneticAlgorithm::CreateNewGenes()
{
	if (((double)rand() / (RAND_MAX + 1.0)) < 0.0000001)
	{
		gene tempChromo;
		for (int j = 0; j < 16; j++)
		{
			tempChromo.m_instructions.push_back(rand() % 4);
		}
		m_genes.push_back(tempChromo);
		m_genes.push_back(tempChromo);
	}
}

//	This function randomly sets all chromosomes
//	in a gene for half of the genes.
void GeneticAlgorithm::PurgeGenes()
{
	if ((double)rand() / (RAND_MAX + 1.0) < 0.00001)
	{
		for (int i = 0; i < m_genes.size(); i++)
		{
			if (i%2)
			{
				for (int j = 0; j < m_genes.at(i).m_instructions.size(); j++)
				{
					m_genes.at(i).m_instructions.at(j) = rand() % 4;
				}
			}
		}
	}
}