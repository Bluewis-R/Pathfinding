#include <iostream>
#include "GeneticAlgorithm.h"
#include "FileReader.h"
#include "Maps.h"


int main()
{
	//setting up the maps
	Maps* maps = new Maps();
	
	FileReader levelLoader("Path1.txt");
	levelLoader.ReadFile("Path1.txt", maps->NewMap(0));

	GeneticAlgorithm* GAlgorithm = new GeneticAlgorithm(maps->getMaps());
	GAlgorithm->CreateChromosomes();
	
	//temp testing chromo
	chromosome c;
	c.m_instructions = { 0, 2, 2, 3, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2 }; //*/
	//GAlgorithm.GetChromosome(0)

	for (float exit = 0.0; exit < 0.999;)
	{
		std::cout << std::endl << exit << std::endl;
		GAlgorithm->GeneticAlgorithm1();
		exit += 0.001;
	}

	

	//GAlgorithm->FitnessMethod1(c);

	delete GAlgorithm;
	delete maps;
	
	char p;
	std::cin >> p;
	return 0;
}






















































































































