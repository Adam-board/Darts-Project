#include "Dart501.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

Dart501::Dart501()
{
	int boardNeighbours[2][21]{
		{0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
		{0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1}
	};


}

Dart501::~Dart501()
{
}


//throws for a single value but has a chance to hit a treble of the value, double of the value or it can hit a random value around your value.
int Dart501::SingleThrow501(int accuracy, int throwValue)
{

	cout << "aiming for single " << throwValue << endl;
	int randomvalue;
	int random = rand() % 100 + 1;


	if (random < accuracy) {
		cout << "you hit " << throwValue << endl;
		return throwValue;
	}
	else if (random < accuracy + 8) {
		cout << "you hit " << boardNeighbours[0][throwValue] << endl;
		return boardNeighbours[0][throwValue];
	}
	else if (random < accuracy + 10 ) {
		cout << "you hit " << boardNeighbours[1][throwValue] << endl;
		return boardNeighbours[1][throwValue];
	}
	else if (random < accuracy + 12) {

		cout << "you hit a treble " << throwValue * 3 << endl;
		return throwValue * 3;
	}
	else if (random < accuracy + 14) {

		cout << "you hit a double " << throwValue * 2 << endl;
		return throwValue * 2;

	}
	else if (random < accuracy + 16) {

		cout << "you hit a treble " << boardNeighbours[0][throwValue] * 3 << endl;
		return boardNeighbours[0][throwValue] * 3;

	}
	else if (random < accuracy + 18) {

		cout << "you hit a double " << boardNeighbours[1][throwValue] * 2 << endl;
		
		return boardNeighbours[1][throwValue] * 2;
	}
	else if(random < accuracy + 20){ 
	
		cout << "you hit the outer ring" << endl;
		
		return 25;
	}
	else {
		randomvalue = 1 + rand() % 20;
		cout << "you hit " << randomvalue << std::endl;
		return randomvalue;
	}
}


//aims for a double but can hit a value around it instead based on a dartboard so it will hit the value next to your target on a random chance
int Dart501::DoubleThrow(int accuracy, int throwValue)
{
	cout << "aiming for double " << throwValue << endl;

	int random = rand() % 100 + 1;

	if (random < accuracy) {
		cout << "you hit your target: " << throwValue * 2 << endl;
		
		return 2 * throwValue;
	}
	else if (random < accuracy + 5) {
	cout << "you missed the board entirely, you suck!\n";
	return 0;
    }
	else if (random < accuracy + 10) {
		cout << "you hit the single of your target: " << throwValue << endl;;
		
		return throwValue;
	}
	else if (random < accuracy + 13) {
		cout << "you hit: " << boardNeighbours[0][throwValue] * 2 << endl;
		
		return boardNeighbours[0][throwValue] * 2 ;
	}
	else if (random < accuracy + 16) {
		cout << "you hit: " << boardNeighbours[1][throwValue] * 2 << endl;
		return boardNeighbours[1][throwValue] * 2;
	}
	else if (random < accuracy + 18) {
		cout << "you hit: " << boardNeighbours[0][throwValue] << endl;
		
		return boardNeighbours[0][throwValue];
	}
	else {
		cout << "you hit: " << boardNeighbours[1][throwValue] << endl;
		
		return boardNeighbours[1][throwValue];
	}




}


//throws for a treble value and can hit a value around it depending on the accuracy of the player for treble throws
int Dart501::TrebleThrow(int accuracy, int throwValue)
{
	cout << "aiming for Treble " << throwValue << endl;

	int random = rand() % 100 + 1;

	if (random < accuracy) {
		cout << "you hit your target: " << 3 * throwValue << endl;
		return 3 * throwValue;
	}
	else if (random < accuracy +10) {
		cout << "you hit: " << throwValue << endl;
		return throwValue;
	}
	else if (random < accuracy + 13) {
		cout << "you hit: " << 3 * boardNeighbours[0][throwValue] << endl;
		return 3 * boardNeighbours[0][throwValue];
	}
	else if (random < accuracy + 16) {
		cout << "you hit: " << 3 * boardNeighbours[1][throwValue] << endl;
		return 3 * boardNeighbours[1][throwValue];
	}
	else if (random < accuracy + 18) {
		cout << "you hit: " << boardNeighbours[0][throwValue] << endl;
		return boardNeighbours[0][throwValue];
	}
	else {
		cout << "you hit: " << boardNeighbours[1][throwValue] << endl;
		return boardNeighbours[1][throwValue];
	}
}


//aims for the bullseye and has a chance to hit the outer ring or a number of random based on the players accuracy
int Dart501::BullThrow501(int accuracy, int throwValue)
{


	int random = rand() % 100 + 1;
	int missed;
	while (throwValue == 50) {

		cout << "aiming for bullseye "<< endl;

		if (random < accuracy - 20)
		{
			cout << "you hit the bullseye" << endl;

			return 50;
		}
		else if (random < accuracy + 5)
		{
			cout << "you hit the outer ring of the bullseye" << endl;

			return 25;
		}
		else
		{
			missed = rand() % 20 + 1;
			cout << "you missed the bullseye but you hit " << missed << endl;
			return missed;
		}
	}

	while (throwValue == 25) {
	
		cout << "aiming for outer ring of bullseye " << endl;

	 if (random < accuracy + 5)
	{
		cout << "you hit the outer ring of the bullseye" << endl;

		return 25;
	}
	else if (random < accuracy - 20)
		{
			cout << "you hit the bullseye" << endl;

			return 50;
		}
		
		else
		{
			missed = rand() % 20 + 1;
			cout << "you missed the outer ring but you hit " << missed << endl;
			return missed;
		}
	
	
	
	
	
	
	
	}



}


