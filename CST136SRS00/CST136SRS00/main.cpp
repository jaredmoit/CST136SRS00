#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>
#include "LetsMakeADeal.h"

using namespace std;

//TODO: Better casting?

void invalidInput()
{

}

int main(int argc, char * argv[])
{
	unsigned numDoors = 3, numDoorsToPreDisclose = 1, numGames = 1;
	bool stay = true;
	string tempArg;

	LetsMakeADeal tempGame = LetsMakeADeal(numDoors, numDoorsToPreDisclose, stay);
	tempGame.getResult();

	/*
	//skip arg 1 because it's just the project directory
	for (int i = 1; i < argc; ++i) {
		switch (i)
		{
			tempArg = *argv[i];
			case 1:
				istringstream(tempArg) >> numDoors;
				if (numDoors < 3) invalidInput();
				break;
			case 2:
				istringstream(tempArg) >> numDoorsToPreDisclose;
				if (numDoorsToPreDisclose < 0 || numDoorsToPreDisclose > numDoors - 2) invalidInput();
				break;
			case 3:
				istringstream(tempArg) >> numGames;
				if (numGames < 0) invalidInput();
				break;
			case 4: //0 to switch, 1 to stay
				istringstream(tempArg) >> stay;
				break;
		}
	}

	cout << numDoors << endl;
	cout << numDoorsToPreDisclose << endl;
	cout << numGames << endl;
	cout << stay << endl;
	*/

	return 0;
}

