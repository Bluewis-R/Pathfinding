#include <iostream>
#include "GeneticAlgorithm.h"
#include "FileReader.h"
#include "Maps.h"

#include "AStar.h"

int main()
{
	//setting up the maps
	Maps* maps = new Maps();
	
	FileReader levelLoader("Path1.txt");
	levelLoader.ReadFile("Path1.txt", maps->NewMap(0));

	GeneticAlgorithm* GAlgorithm = new GeneticAlgorithm(maps->getMaps());
	GAlgorithm->CreateGenes();
	
	gene c;
	c.m_instructions = { 0, 2, 2, 3, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2 }; 
	std::cout << "Hi, the the A* code may not work  but the GA should." << std::endl << "If the Program tries to access unavalible memory, just restart the program." << std::endl;
	std::cout << "Enter either (a) or (g) : ";
	char inpt;
	std::cin >> inpt;

	for (bool exit = false; exit != true;)
	{
		//	A* 
		if (inpt == 'a' || inpt == 'A' || inpt == 'a*' || inpt == 'A*')
		{
			steve(maps->GetMap(0));
		}

		//	Genetic Algorithm
		else if (inpt == 'g' || inpt == 'G' || inpt == 'ga' || inpt == 'GA')
		{
			//	Doing initial fitness to be able
			//	to display genes in the console.
			GAlgorithm->FitnessMethod1();

			int itteration = 0;
			while (GAlgorithm->GeneticAlgorithm1())
			{
				itteration++;
				if (!(itteration % 200))
				{
					std::cout << "itteration : " << itteration << std::endl;
					std::vector<gene>* c = new std::vector<gene>();
					c = GAlgorithm->GetGenes();
					for (int i = 0; i < c->size(); i++)
					{
						std::cout << c->at(i).m_fitness << std::endl;
					}
				}
			}
			std::cout << "Path found!" << std::endl << "Path : ";
			gene endGene = GAlgorithm->GetEndGene();
			for (int i = 0; i < endGene.m_instructions.size(); i++)
			{
				std::cout << endGene.m_instructions.at(i);
			}
			std::cout << std::endl;
			for (int i = 0; i < endGene.m_instructions.size(); i++)
			{
				if (endGene.m_instructions.at(i) == 0) { std::cout << "U "; }
				if (endGene.m_instructions.at(i) == 1) { std::cout << "R "; }
				if (endGene.m_instructions.at(i) == 2) { std::cout << "D "; }
				if (endGene.m_instructions.at(i) == 3) { std::cout << "L "; }
				;
			}


		}
		exit = true;
	}







	//	Cleaning up Pointers
	delete GAlgorithm;
	delete maps;
	
	char p;
	std::cin >> p;
	return 0;
}