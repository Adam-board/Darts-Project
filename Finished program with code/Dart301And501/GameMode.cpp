#include "GameMode.h"
#include "DartBoard.h"
#include "Player.h"
#include "Dart501.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

GameMode::GameMode()
{
}

GameMode::~GameMode()
{
}

void GameMode::Game301()
{
	//declares the variables
	int getToBull = 0;
	int choice = 0;
	int numOfGames = 0;
	int gamemode = 0;
	int currentScore = 0;


	//dedicated for 501 seperately 
	double frequency[14] = { 0 };
	

	//sets up the pointers for the player 
	Player* P1 = new Player;
	Player* P2 = new Player;
	Player* PlayerTurn = P1;

	//sets up the objects
	DartBoard game301;

	P1->SetPlayerDetails();
	P2->SetPlayerDetails();

	//allows the user choose how many games to simulate
	cout << "Number of games?\n";
	cin >> numOfGames;

	//has validation and allows the users to choose who goes first
	do {
		cout << "Who goes first? (enter number)\n" << endl << "1. " << P1->GetName() << endl << "2. " << P2->GetName() << endl;
		cin >> choice;
	} while (choice != 1 && choice != 2);


	//This section is for the 301 simulation

		//runs the game for the amount of times that the user has chosen above
	for (int i = 0; i < numOfGames; i++) {
		cout << "301 is the default starting score for this gamemode\n";


		//resets the score to 301 for everygame
		P1->Setup301Score();
		P2->Setup301Score();

		


		//connects the pointer to which player will be playing this turn
		while (P1->GetScore() != 0 || P2->GetScore() != 0) {

			if (choice == 1) {

				PlayerTurn = P1;

			}
			else if (choice == 2) {

				PlayerTurn = P2;

			}

			currentScore = PlayerTurn->GetScore();

			//will keep throwing for bullseyes while over 100
			if (currentScore >= 100)
			{
				cout << endl;
				game301.SetThrow(game301.bullThrow(PlayerTurn->GetBullAccuracy()));

				if (game301.GetThrow() == 50) { PlayerTurn->SetBullHit();  PlayerTurn->SetBullHitPerGame(); }

				PlayerTurn->SetScore(game301.GetThrow());




			}


			//will throw for 20 whilst in the range of 99 and 70
			else if (currentScore <= 99 && currentScore >= 70)

			{
				cout << endl;
				game301.SetThrow(game301.SingleThrow(PlayerTurn->GetSingleAccuracy(), 20));
				PlayerTurn->SetScore(game301.GetThrow());


			}


			//once in the range of 69 and 51 will throw to get down to 50
			else if (currentScore < 70 && currentScore > 50) {
				cout << endl;
				getToBull = PlayerTurn->GetScore() - 50;

				game301.SetThrow(game301.SingleThrow(PlayerTurn->GetSingleAccuracy(), getToBull));
				PlayerTurn->SetScore(game301.GetThrow());



			}

			//will throw for bullseye now that the score is 50 to end on a bullseye
			else if (currentScore == 50)
			{
				cout << endl;
				//takes P1s accuracy and does a bullseye throw and sets whatever value it gets as the set throw value
				game301.SetThrow(game301.bullThrow(PlayerTurn->GetBullAccuracy()));

				PlayerTurn->SetScore(game301.GetThrow());

				if (game301.GetThrow() == 50) { PlayerTurn->SetBullHit(); PlayerTurn->SetBullHitPerGame(); }


			}
			PlayerTurn->SetTotalThrows();
			PlayerTurn->SetThrowPerGame();

			//changes the player to the other player
			if (P1->GetScore() != 0 || P2->GetScore() != 0) {

				if (choice == 1) {

					choice = 2;
				}
				else if (choice == 2) {

					choice = 1;

				}
			}
			else { break; }


			//breaks the overall loop of the 301 game
			if (P1->GetScore() == 0 || P2->GetScore() == 0)
			{
				break;
			}


		}
		//sets the current player to the winner of that round
		if (P1->GetScore() == 0) {

			PlayerTurn = P1;

		}
		else if (P2->GetScore() == 0) {

			PlayerTurn = P2;
		}

		//inputs the throws the winner had to win for the frequency
		switch (PlayerTurn->GetThrowPerGame()) {

		case 7:
			frequency[0] += 1;

			break;

		case 8:
			frequency[1] += 1;

			break;

		case 9:
			frequency[2] += 1;

			break;

		case 10:
			frequency[3] += 1;

			break;

		case 11:
			frequency[4] += 1;

			break;

		case 12:
			frequency[5] += 1;

			break;

		case 13:
			frequency[6] += 1;

			break;

		case 14:
			frequency[7] += 1;

			break;

		case 15:
			frequency[8] += 1;

			break;

		case 16:
			frequency[9] += 1;

			break;

		case 17:
			frequency[10] += 1;

			break;
		}



		//uses the winner function to increase wincount
		if (P1->GetScore() == 0 && P2->GetScore() > 0)
		{

			P1->Winner();
			P1->SetWin();
			cout << endl;

		}
		else if (P2->GetScore() == 0 && P1->GetScore() > 0)
		{

			P2->Winner();
			P2->SetWin();
			cout << endl;


		}
		//resests throws for that game but not the total throws from all games
		P1->ResetBullHitPerGame();
		P1->ResetThrowPerGame();
		P2->ResetBullHitPerGame();
		P2->ResetThrowPerGame();

		//end of for loop
	}
	//prints out the throw frequencies
	cout << "game length frequencies\n" << endl;
	for (int j = 0; j < 11; j++) {


		cout << j + 7 << " throws: " << setprecision(3) << ((double)frequency[j] / numOfGames) * 100 << "%" << endl;

	}




	//returns the win rate of the players
	P1->Setwinrate(((double)P1->GetWin()) / ((double)numOfGames));
	P2->Setwinrate(((double)P2->GetWin()) / ((double)numOfGames));


	cout << "Winrate of players\n";
	cout << endl;

	cout << "the winrate of " << P1->GetName() << " is " << setprecision(3) << P1->GetWinrate() << "%" << endl;

	cout << "the winrate of " << P2->GetName() << " is " << setprecision(3) << P2->GetWinrate() << "%" << endl;


	cout << "simulation of 301 darts finished\n" << endl;

	cout << " " << flush;
	system("PAUSE");
	system("CLS");


}





void GameMode::Game501()
{

	int numOfGames = 0;
	int gamemode = 0;
	int currentScore = 0;
	int choice = 0;
	double frequency[14] = { 0 };
	int dartValues501[3] = { 0 };
	int FreqNum;
	int Display = 7;

	//sets up the pointers for the player 
	Player* P1 = new Player;
	Player* P2 = new Player;
	Player* PlayerTurn = P1;

	Dart501 game501;

	P1->SetPlayerDetails();
	P2->SetPlayerDetails();

	//allows the user choose how many games to simulate
	cout << "Number of games?\n";
	cin >> numOfGames;

	cout << "501 is the default starting score for this gamemode\n";

	for (int i = 0; i < numOfGames; i++) {

		//flipping the coin for which player is going first
		choice = rand() % 2 + 1;

		//runs the game for the sets of a match in an actual championship game
		for (int matches = 0; matches < 13; matches++) {



			P1->ResetroundWinner();
			P2->ResetroundWinner();



			for (int sets = 0; sets < 5; sets++) {

				P1->Setup501Score();
				P2->Setup501Score();


				//resets the score to 501 for everygame
				cout << "player " << choice << " will go first for this game" << endl;
				cout << endl;

				//changes the players turn
				while (P1->GetScore() != 0 || P2->GetScore() != 0) {

					if (choice == 1) {

						PlayerTurn = P1;
						cout << endl;
						cout << P1->GetName() << "'s turn\n";
						cout << endl;
					}
					else if (choice == 2) {

						PlayerTurn = P2;
						cout << endl;
						cout << P2->GetName() << "'s turn\n";
						cout << endl;
					}

					//runs the 3 darts for the player 

					for (int darts = 0; darts < 3; darts++) {

						currentScore = PlayerTurn->GetScore();

						//while the score is above 62 then it will throw for highest value, however if it is odd it will throw 19
						if (currentScore >= 62) {
							if (currentScore % 2 != 0) {


								game501.SetThrow(game501.TrebleThrow(PlayerTurn->GetTrebleAccuracy(), 19));
								PlayerTurn->SetScore501(game501.GetThrow());



							}
							else
							{
								game501.SetThrow(game501.TrebleThrow(PlayerTurn->GetTrebleAccuracy(), 20));
								PlayerTurn->SetScore501(game501.GetThrow());

							}
						}
						// will try to get the score to 50 so they can end on a bullseye
						else if (currentScore < 62 && currentScore > 50) {

							game501.SetThrow(game501.SingleThrow501(PlayerTurn->GetSingleAccuracy(), ((PlayerTurn->GetScore() - 50))));
							PlayerTurn->SetScore501(game501.GetThrow());

						}

						else if (currentScore == 50) {

							game501.SetThrow(game501.BullThrow501(PlayerTurn->GetBullAccuracy(), 50));
							PlayerTurn->SetScore501(game501.GetThrow());

						}

						//if the players score is below 50 but it isn't 40 or below the it will throw for a 10
						else if (currentScore < 50 && currentScore > 40) {

							game501.SetThrow(game501.SingleThrow501(PlayerTurn->GetSingleAccuracy(), 10));
							PlayerTurn->SetScore501(game501.GetThrow());



						}
						// will try to finish the game on a double and will make the score even if the score is odd
						else if (currentScore <= 40 && currentScore > 3) {
							//ensures the player can finish on a double
							if (currentScore % 2 != 0) {


								game501.SetThrow(game501.SingleThrow501(PlayerTurn->GetSingleAccuracy(), 3));
								PlayerTurn->SetScore501(game501.GetThrow());

							}

							else {
								game501.SetThrow(game501.DoubleThrow(PlayerTurn->GetDoubleAccuracy(), (PlayerTurn->GetScore() / 2)));
								PlayerTurn->SetScore501(game501.GetThrow());


							}
						}
						// of the score is equal to one then it will throw for one double to end the game
						else if (PlayerTurn->GetScore() == 2) {

							game501.SetThrow(game501.DoubleThrow(PlayerTurn->GetDoubleAccuracy(), 1));
							PlayerTurn->SetScore501(game501.GetThrow());

						}
						//holds the values until the end of the turn
						dartValues501[darts] = game501.GetThrow();


						if (PlayerTurn->GetScore() == 1 || PlayerTurn->GetScore() < 0) {

							cout << "Sorry you must finish on a double or a bullseye\n";
							cout << endl;

							for (int R = 0; R < 3; R++) {
								//if the darts equate to one or go under the finishing value then the game is ended
								PlayerTurn->SetScore501((-dartValues501[R]));
							}
						}


					}

					//changes the players turn around
					if (P1->GetScore() != 0 || P2->GetScore() != 0) {

						if (choice == 1) {

							choice = 2;
						}
						else if (choice == 2) {

							choice = 1;

						}
					}
					else { break; }


					if (P1->GetScore() == 0 || P2->GetScore() == 0)
					{
						break;
					}



				}


				//sets the winner for the round and sets depending on if 3/5 rounds have been one or if 7/13 rounds have been won
				if (P1->GetScore() == 0 && P2->GetScore() > 0)
				{

					P1->SetroundWinner();
					cout << P1->GetName() << " won the round\n";
					cout << "you have won " << P1->GetroundWinner() << " out of 5 rounds\n";
					cout << endl;
					cout << endl;

				}
				else if (P2->GetScore() == 0 && P1->GetScore() > 0)
				{

					P2->SetroundWinner();
					cout << P2->GetName() << " won the round\n";
					cout << "you have won " << P2->GetroundWinner() << " out of 5 rounds\n";
					cout << endl;
					cout << endl;


				}

				if (P1->GetroundWinner() == 3 || P2->GetroundWinner() == 3) {


					if (P1->GetroundWinner() == 3) {

						P1->SetSetwinner();
						cout << "Congrats you have won this set " << P1->GetName();
						cout << endl;
						cout << "you have won " << P1->GetSetWinner() << " out of 13 matches\n";

						break;


					}
					else if (P2->GetroundWinner() == 3) {

						P2->SetSetwinner();
						cout << "Congrats you have won this set " << P2->GetName();
						cout << endl;
						cout << "you have won " << P2->GetSetWinner() << " out of 13 matches\n";
						break;

					}
				}
			}
			//end of 5 games



			if (P1->GetSetWinner() == 7 || P2->GetSetWinner() == 7) {

				if (P1->GetSetWinner() == 7) {

					P1->ResetroundWinner();
					cout << endl;
					cout << "yay, you won the overall match" << P1->GetName() << endl;
					cout << endl;
					break;


				}
				else if (P2->GetSetWinner() == 7) {

					P2->ResetroundWinner();
					cout << endl;
					cout << "yay you win the overall match" << P2->GetName() << endl;
					cout << endl;
					break;

				}
			}
		}
		//end of 13 sets
		cout << endl;
		cout << endl;
		//calculates the frequncies of the win ratio for both the players by checking how the win ration was that game and adds one onto the slot that it fits
		FreqNum = -1;
		for (int i = 6; i > -1; i--) {
			FreqNum += 1;
			if (P1->GetSetWinner() == 7 && P2->GetSetWinner() == i) { frequency[FreqNum] += 1; }
		}

		for (int i = 6; i > -1; i--) {
			FreqNum += 1;
			if (P1->GetSetWinner() == i && P2->GetSetWinner() == 7) { frequency[FreqNum] += 1; }
		}


		P1->ResetSetWinner();
		P2->ResetSetWinner();
	}


	//displays the win ratios 
	cout << P1->GetName() << " : " << P2->GetName() << "                           Frequencies" << endl;
	cout << endl;

	 Display = 7;

	 for (int i = 0; i < 7; i++) {

		 Display -= 1;
		 cout << "7" << " : " << Display << "                    " << setprecision(3) << (double)(frequency[i] / numOfGames) * 100 << "%" << endl;
	 }

	 Display += 7;

	 for (int i = 7; i < 14; i++) {

		 Display -= 1;
		 cout << Display << " : " << "7" << "                    " << setprecision(3) << (double)(frequency[i] / numOfGames) * 100 << "%" << endl;
	 }

	cout << "simulation finished for 501\n";
	

	cout << " " << flush;
	system("PAUSE");
	system("CLS");


}





void GameMode::Game501Interactive()
{

	int ChoiceThrows = 0;
	int ValueForThrow = 0;
	int numOfGames = 0;
	int gamemode = 0;
	int currentScore = 0;
	int choice = 0;
	double frequency[14] = { 0 };
	int dartValues501[3] = { 0 };
	int FreqNum;
	int Display = 7;
	

	//sets up the pointers for the player 
	Player* P1 = new Player;
	Player* P2 = new Player;
	Player* PlayerTurn = P1;

	Dart501 game501;


	P1->SetPlayerDetails();
	P2->SetPlayerDetails();

	//allows the user choose how many games to simulate
	cout << "Number of games?\n";
	cin >> numOfGames;
	
	cout << R"(______  ______  ______  ______  ______  ______  ______ 
|______||______||______||______||______||______||______|
                                                        )" << endl;

	cout << R"(______               _          _____  _____  __  
|  _  \             | |        |  ___||  _  |/  | 
| | | |  __ _  _ __ | |_  ___  |___ \ | |/' |`| | 
| | | | / _` || '__|| __|/ __|     \ \|  /| | | | 
| |/ / | (_| || |   | |_ \__ \ /\__/ /\ |_/ /_| |_
|___/   \__,_||_|    \__||___/ \____/  \___/ \___/
)" << endl;


	cout << R"(______  ______  ______  ______  ______  ______  ______ 
|______||______||______||______||______||______||______|
                                                        )" << endl;


	cout << " is the default starting score for this gamemode\n" << endl << "You must end the game on a double or a bullseye so if you reach one you will have to go back up to the number you had when you started your turn\n";

	

	for (int i = 0; i < numOfGames; i++) {
		

		choice = rand() % 2 + 1;

		//runs the game for the sets of a match in an actual championship game
		for (int matches = 0; matches < 13; matches++) {



			P1->ResetroundWinner();
			P2->ResetroundWinner();



			for (int sets = 0; sets < 5; sets++) {

				P1->Setup501Score();
				P2->Setup501Score();


				//resets the score to 501 for everygame
				cout << "player " << choice << " will go first for this game" << endl;
				cout << endl;

				//Empties the console
				cout << " " << flush;
				system("PAUSE");
				system("CLS");

				do {


					if (choice == 1) {

						PlayerTurn = P1;
						cout << endl;
						cout << R"(______ _                         __    _____                
| ___ \ |                       /  |  |_   _|               
| |_/ / | __ _ _   _  ___ _ __  `| |    | |_   _ _ __ _ __  
|  __/| |/ _` | | | |/ _ \ '__|  | |    | | | | | '__| '_ \ 
| |   | | (_| | |_| |  __/ |    _| |_   | | |_| | |  | | | |
\_|   |_|\__,_|\__, |\___|_|    \___/   \_/\__,_|_|  |_| |_|
                __/ |                                       
               |___/                                        )" << endl << endl;
						cout << endl;
					}
					else if (choice == 2) {

						PlayerTurn = P2;
						cout << endl;
						cout << R"(______ _                         _____   _____                
| ___ \ |                       / __  \ |_   _|               
| |_/ / | __ _ _   _  ___ _ __  `' / /'   | |_   _ _ __ _ __  
|  __/| |/ _` | | | |/ _ \ '__|   / /     | | | | | '__| '_ \ 
| |   | | (_| | |_| |  __/ |    ./ /___   | | |_| | |  | | | |
\_|   |_|\__,_|\__, |\___|_|    \_____/   \_/\__,_|_|  |_| |_|
                __/ |                                         
               |___/                                          )" << endl << endl;
						cout << endl;
					}

					

					for (int darts = 0; darts < 3; darts++) {
					
						cout << " " << flush;
						system("PAUSE");
						system("CLS");

						cout << endl << endl << endl << endl;

						if (PlayerTurn == P1) {

							ValueForThrow = 0;
							ChoiceThrows = 0;

							cout << "Current Score:" << PlayerTurn->GetScore() << endl << endl;


							do {
								cout << "What value would you like to throw for between 1-20 or 25 or 50 the last two are for the bullseye\n";
								cin >> ValueForThrow;

								if (ValueForThrow == 50 || ValueForThrow == 25) { break; }


							} while (ValueForThrow < 1 || ValueForThrow > 20);
							if (ValueForThrow != 25 && ValueForThrow != 50) {
								cout << "What would you like to throw for:\n" << endl << "1. Single Throw" << endl << "2. Double Throw" << endl << "3. Treble Throw" << endl;
								cin >> ChoiceThrows;
							}
							else {


								cout << R"(______       _ _                                    _____       _             ______ _             _ 
| ___ \     | | |                                  |  _  |     | |            | ___ (_)           | |
| |_/ /_   _| | |___  ___ _   _  ___    ___  _ __  | | | |_   _| |_ ___ _ __  | |_/ /_ _ __   __ _| |
| ___ \ | | | | / __|/ _ \ | | |/ _ \  / _ \| '__| | | | | | | | __/ _ \ '__| |    /| | '_ \ / _` | |
| |_/ / |_| | | \__ \  __/ |_| |  __/ | (_) | |    \ \_/ / |_| | ||  __/ |    | |\ \| | | | | (_| |_|
\____/ \__,_|_|_|___/\___|\__, |\___|  \___/|_|     \___/ \__,_|\__\___|_|    \_| \_|_|_| |_|\__, (_)
                           __/ |                                                              __/ |  
                          |___/                                                              |___/   )" << endl << endl << endl;

								game501.SetThrow(game501.BullThrow501(PlayerTurn->GetBullAccuracy(), ValueForThrow));
								PlayerTurn->SetScore501(game501.GetThrow());




							}

							switch (ChoiceThrows)
							{
								//used for single throws
							case 1:


								cout << R"(     _             _      
    (_)           | |     
 ___ _ _ __   __ _| | ___ 
/ __| | '_ \ / _` | |/ _ \
\__ \ | | | | (_| | |  __/
|___/_|_| |_|\__, |_|\___|
              __/ |       
             |___/    )" << endl << endl << endl;
								game501.SetThrow(game501.SingleThrow501(PlayerTurn->GetSingleAccuracy(), ValueForThrow));
								PlayerTurn->SetScore501(game501.GetThrow());


								//validation to stop players ending on a single
								if (PlayerTurn->GetScore() == 0) {


									PlayerTurn->SetScore501(-1);

								}

								break;
								//used for double throws
							case 2:

								cout << R"(______            _     _      
|  _  \          | |   | |     
| | | |___  _   _| |__ | | ___ 
| | | / _ \| | | | '_ \| |/ _ \
| |/ / (_) | |_| | |_) | |  __/
|___/ \___/ \__,_|_.__/|_|\___|
                               )" << endl << endl << endl;

								game501.SetThrow(game501.DoubleThrow(PlayerTurn->GetDoubleAccuracy(), ValueForThrow));
								PlayerTurn->SetScore501(game501.GetThrow());



								break;
								//used for treble throws
							case 3:

								cout << R"( _____        _     _      
|_   _|      | |   | |     
  | |_ __ ___| |__ | | ___ 
  | | '__/ _ \ '_ \| |/ _ \
  | | | |  __/ |_) | |  __/
  \_/_|  \___|_.__/|_|\___|)" << endl << endl << endl;

								game501.SetThrow(game501.TrebleThrow(PlayerTurn->GetTrebleAccuracy(), ValueForThrow));
								PlayerTurn->SetScore501(game501.GetThrow());



								//validation to stop players ending on a Treble
								if (PlayerTurn->GetScore() == 0) {


									PlayerTurn->SetScore501(1);

								}

								break;

							default:

								break;
							}

						}

						//Player two follows the same rules as the 501 gamemode
						else if (PlayerTurn == P2) {


							if (PlayerTurn->GetScore() >= 62) {
								if (PlayerTurn->GetScore() % 2 != 0) {


									game501.SetThrow(game501.TrebleThrow(PlayerTurn->GetTrebleAccuracy(), 19));
									PlayerTurn->SetScore501(game501.GetThrow());



								}
								else
								{
									game501.SetThrow(game501.TrebleThrow(PlayerTurn->GetTrebleAccuracy(), 20));
									PlayerTurn->SetScore501(game501.GetThrow());


								}
							}
							else if (PlayerTurn->GetScore() < 62 && PlayerTurn->GetScore() > 50) {

								game501.SetThrow(game501.SingleThrow501(PlayerTurn->GetSingleAccuracy(), ((PlayerTurn->GetScore() - 50))));
								PlayerTurn->SetScore501(game501.GetThrow());




							}

							else if (PlayerTurn->GetScore() == 50) {

								game501.SetThrow(game501.BullThrow501(PlayerTurn->GetBullAccuracy(), 50));
								PlayerTurn->SetScore501(game501.GetThrow());
								if (game501.GetThrow() == 50) { PlayerTurn->SetBullHitPerGame();  PlayerTurn->SetBullHit(); }

							}
							else if (PlayerTurn->GetScore() < 50 && PlayerTurn->GetScore() > 40) {

								game501.SetThrow(game501.SingleThrow501(PlayerTurn->GetSingleAccuracy(), 10));
								PlayerTurn->SetScore501(game501.GetThrow());



							}

							else if (PlayerTurn->GetScore() <= 40 && PlayerTurn->GetScore() > 3) {
								//ensures the player can finish on a double
								if (PlayerTurn->GetScore() % 2 != 0) {


									game501.SetThrow(game501.SingleThrow501(PlayerTurn->GetSingleAccuracy(), 3));
									PlayerTurn->SetScore501(game501.GetThrow());





								}

								else {
									game501.SetThrow(game501.DoubleThrow(PlayerTurn->GetDoubleAccuracy(), (PlayerTurn->GetScore() / 2)));
									PlayerTurn->SetScore501(game501.GetThrow());




								}
							}
							else if (PlayerTurn->GetScore() == 2) {

								game501.SetThrow(game501.DoubleThrow(PlayerTurn->GetDoubleAccuracy(), 1));
								PlayerTurn->SetScore501(game501.GetThrow());



							}

						}

						dartValues501[darts] = game501.GetThrow();

						for (int i = 0; i < 3; i++) {

							cout << "Dart " << i + 1  << ":  "<< dartValues501[i] << endl;

						}

						if (PlayerTurn->GetScore() == 1 || PlayerTurn->GetScore() < 0) {

							cout << "Sorry you must finish on a double or a bullseye\n";
							cout << endl;


							for (int R = 0; R < darts; R++) {
								//if the darts equate to one or go under the finishing value then the game is ended
								PlayerTurn->SetScore501((-dartValues501[R]));

							}
							break;
						}


					}
					dartValues501[3] = { 0 };

					if (P1->GetScore() != 0 || P2->GetScore() != 0) {

						if (choice == 1) {

							choice = 2;
						}
						else if (choice == 2) {

							choice = 1;

						}
					}
					else { break; }


					if (P1->GetScore() == 0 || P2->GetScore() == 0)
					{
						break;
					}



				} while (P1->GetScore() != 0 || P2->GetScore() != 0);



				if (P1->GetScore() == 0 && P2->GetScore() > 0)
				{

					P1->SetroundWinner();
					cout << P1->GetName() << " won the first round\n";
					cout << "you have won " << P1->GetroundWinner() << " out of 5 rounds\n";
					cout << endl;
					cout << endl;

				}
				else if (P2->GetScore() == 0 && P1->GetScore() > 0)
				{

					P2->SetroundWinner();
					cout << P2->GetName() << " won the first round\n";
					cout << "you have won " << P2->GetroundWinner() << " out of 5 rounds\n";
					cout << endl;
					cout << endl;


				}

				if (P1->GetroundWinner() == 3 || P2->GetroundWinner() == 3) {


					if (P1->GetroundWinner() == 3) {

						P1->SetSetwinner();
						cout << "Congrats you have won this set " << P1->GetName();
						cout << endl;
						cout << "you have won " << P1->GetSetWinner() << " out of 13 matches\n";

						break;


					}
					else if (P2->GetroundWinner() == 3) {

						P2->SetSetwinner();
						cout << "Congrats you have won this set " << P2->GetName();
						cout << endl;
						cout << "you have won " << P2->GetSetWinner() << " out of 13 matches\n";
						break;

					}
				}
			}
			//end of 5 games



			if (P1->GetSetWinner() == 7 || P2->GetSetWinner() == 7) {

				if (P1->GetSetWinner() == 7) {

					P1->ResetroundWinner();
					cout << endl;
					cout << "yay, you won the overall match" << P1->GetName() << endl;
					cout << endl;
					break;


				}
				else if (P2->GetSetWinner() == 7) {

					P2->ResetroundWinner();
					cout << endl;
					cout << "yay you win the overall match" << P2->GetName() << endl;
					cout << endl;
					break;

				}
			}
		}
		//end of 13 sets
		cout << endl;
		cout << endl;

		FreqNum = -1;
		for (int i = 6; i > -1; i--) {
			FreqNum += 1;
			if (P1->GetSetWinner() == 7 && P2->GetSetWinner() == i) { frequency[FreqNum] += 1; }
		}

		for (int i = 6; i > -1; i--) {
			FreqNum += 1;
			if (P1->GetSetWinner() == i && P2->GetSetWinner() == 7) { frequency[FreqNum] += 1; }
		}


		P1->ResetSetWinner();
		P2->ResetSetWinner();
	}

	cout << P1->GetName() << " : " << P2->GetName() << "                           Frequencies" << endl;
	cout << endl;

     
	
	Display= 7;


	for (int i = 0; i < 7; i++) {

		Display -= 1;
		cout << "7" << " : " << Display << "                    " << setprecision(3) << (double)(frequency[i] / numOfGames) * 100 << "%" << endl;
	}

	Display +=  7;

	for (int i = 7; i < 14; i++) {

		Display -= 1;
		cout << Display << " : " << "7" << "                    " << setprecision(3) << (double)(frequency[i] / numOfGames) * 100 << "%" << endl;
	}
	cout << "interactive game finished for 501\n";
	

	cout << " " << flush;
	system("PAUSE");
	system("CLS");


}
//end of 501 simulated







