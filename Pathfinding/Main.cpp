#include <iostream>
#include "NNetwork.h"
#include "FileReader.h"
#include "Maps.h"


int main()
{
	//setting up the maps
	Maps maps;
	
	FileReader levelLoader("path1.txt");
	levelLoader.ReadFile("path1.txt", maps.NewMap(0));

	NNetwork network;
	network.CreateChromosomes();
	network.FitnessMethod1(network.GetChromosome(0), maps.GetMap(0));


	//delete maps;
	
	char p;
	std::cin >> p;
	return 0;
}






















































































































