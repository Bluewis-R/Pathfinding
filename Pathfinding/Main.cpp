#include <iostream>
#include "GeneticAlgorithm.h"
#include "FileReader.h"
#include "Maps.h"

#include "AStar.h"

int main()
{
	//setting up the maps
	Maps* maps = new Maps();
	
	FileReader levelLoader("Path2.txt");
	levelLoader.ReadFile("Path2.txt", maps->NewMap(0));

	GeneticAlgorithm* GAlgorithm = new GeneticAlgorithm(maps->getMaps());
	GAlgorithm->CreateChromosomes();
	
	//temp testing chromo
	chromosome c;
	c.m_instructions = { 0, 2, 2, 3, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2 }; //*/
	//GAlgorithm.GetChromosome(0)

	std::cout << "Enter either (a) or (g) : ";
	char inpt;
	std::cin >> inpt;

	for (bool exit = false; exit != true;)
	{
		if (inpt == 'a' || inpt == 'A')
		{
			steve(maps->GetMap(0));
		}
		else if (inpt == 'g' || inpt == 'G' || inpt == 'ga' || inpt == 'GA')
		{
			int itteration = 0;
			//	to stop bug
			GAlgorithm->FitnessMethod1();
			while (GAlgorithm->GeneticAlgorithm1())
			{
				itteration++;
				if (!(itteration % 200))
				{
					std::cout << "itteration : " << itteration << std::endl;
					std::vector<chromosome>* c = new std::vector<chromosome>();
					c = GAlgorithm->GetChromosomes();
					for (int i = 0; i < c->size(); i++)
					{
						std::cout << c->at(i).m_fitness << std::endl;
					}
				}
			}
		}
		exit = true;
	}







	

	//GAlgorithm->FitnessMethod1(c);

	delete GAlgorithm;
	delete maps;
	
	char p;
	std::cin >> p;
	return 0;
}






















































































































