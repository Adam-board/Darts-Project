#include "DartBoard.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

DartBoard::DartBoard()
{


	Throw = 0;


}

DartBoard::~DartBoard()
{
}


//Single Throw is used to throw for the single values, it has a chance of hitting next to the spot your are aiming for or can hit a random value
int DartBoard::SingleThrow(int accuracy, int throwValue)
{
	
	int randomvalue;
	int random = rand() % 100;


	if (random < accuracy) {
		cout << "you hit " << throwValue << std::endl;
		return throwValue;
	}
	else if (random < accuracy + 10) {

		cout << "you hit " << boardNeighbours[0][throwValue] << std::endl;
		return boardNeighbours[0][throwValue];
	}
	else if (random < accuracy + 20) {
		cout << "you hit " << boardNeighbours[1][throwValue] << std::endl;
		return boardNeighbours[1][throwValue];
	}
	else  {
		randomvalue = 1 + rand() % 20;
		cout << "you hit " << randomvalue << std::endl;
		return randomvalue;
	}

}


//bullthrow is used for throwing bullseyes and has a hcance of hitting a random target instead
int DartBoard::bullThrow(int accuracy)
{

	int Hit;

	int random = rand() % 100;

	if (random < (accuracy - 20)) {
		cout << "you hit the bullseye\n";
		return 50;
	}
	else {
		Hit = 1 + rand() % 20;
		cout << "you missed bullseye but hit " << Hit << " instead!\n";

		return Hit;
	}

}

int DartBoard::GetThrow()
{
	return Throw;
}



void DartBoard::SetThrow(int throwValue)
{
	Throw = throwValue;
}
