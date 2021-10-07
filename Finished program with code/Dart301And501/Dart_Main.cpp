#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "GameMode.h"


using namespace std;


int main()
{
	srand(time(0));
	GameMode game;
	

	//section below is all used for choosing the gamemode and playing the games
	int choose = 0;
	
	cout << "Please choose a gamemode\n 1. 301\n 2. 501\n 3. 501 interactive\n";
	cin >> choose;

	switch (choose) {


	case 1:
			game.Game301();
		break;

	case 2:
		game.Game501();
		break;

	case 3:
		game.Game501Interactive();
		break;

	default: 
		cout << "No game mode selected, ending program\n" << endl;
		break;


	}

}