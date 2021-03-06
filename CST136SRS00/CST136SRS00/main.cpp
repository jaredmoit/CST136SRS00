#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "LetsMakeADeal.h"

void invalidInput(std::string message)
{
	std::cout << "Invalid Input: " << message << std::endl;
	std::exit(0);
}

int main(int argc, char * argv[])
{
	unsigned numDoors = 3, numDoorsToPreDisclose = 1, numGames = 10;
	auto stay = true;
	std::vector<LetsMakeADeal> games(numGames);

	//skip arg 1 because it's just the project directory
	for (int i = 1; i < argc; ++i) {
		std::istringstream iss(argv[i]);
		switch (i)
		{
		case 1:
			//NumDoors
			if (!(iss >> numDoors && numDoors >= 3)) invalidInput("Arg 1, Number of doors.");
			break;
		case 2:
			//NumDoorsToPreDisclose
			if (!(iss >> numDoorsToPreDisclose &&
				numDoorsToPreDisclose >= 0 &&
				numDoorsToPreDisclose <= numDoors - 2)) invalidInput("Arg 2, Number of doors to predisclose.");
			break;
		case 3:
			//NumGames
			if (!(iss >> numGames && numGames >= 1)) invalidInput("Arg 3, Number of games.");
			games.resize(numGames);
			break;
		case 4:
			//0 to switch, 1 to stay
			if (!(iss >> stay)) invalidInput("Arg 4, Stay (1) or switch (0).");
			break;
		default:
			break;
		}
	}

	//Calculate probability
	double totalWins = 0;
	for (int i = 0; i < numGames; i++)
	{
		games[i] = LetsMakeADeal(numDoors, numDoorsToPreDisclose, stay);
		if (games[i].getResult()) totalWins++;
	}
	const double probability = totalWins / numGames;
	std::cout << probability << std::endl;

	return 0;
}