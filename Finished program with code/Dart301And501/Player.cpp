#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>


//constructor
Player::Player()
{

	//sets up the values for the beginning of the program
	score = 0;
	name = "default user";
	bullAccuracy = 70;
	singleAccuracy = 80;
	totalThrows = 0;
	totalbullHit = 0;
	bullhitPerGame = 0;
	throwsPerGame = 0;
	wins = 0;
	winrate = 0;
	setsWinner = 0;

}

Player::~Player()
{
}

int Player::GetScore()
{
	return score;
}

//ensures the game doesn't end on a throw that is below a bullseye
void Player::SetScore(int throwScore)
{
	score = score - throwScore;

	cout << name << "'s new score is: " << score << endl;

	if (score < 50 && score > 0) {


		cout << "sorry you must end on a bullseye\n";
		score = score + throwScore;
	}

}


//removes the score but for 501 rather than 301
void Player::SetScore501(int throwScore)
{

	score = score - throwScore;

	cout << name << "'s new score is: " << score << endl;


}

void Player::Setup301Score()
{

	score = 301;

}

void Player::Setup501Score()
{

	score = 501;

}


//sets up the players details for both players
void Player::SetPlayerDetails()
{
	cout << endl;
	cout << "what is the name of this player\n";

	cin >> name;
	cout << endl;
	cout << name << " is the players name\n";
	cout << endl;

	cout << endl;
	cout << "what is the single success rate of " << name << "?" << endl;
	cin >> singleAccuracy;

	cout << endl;
	cout << "what is the double success rate of " << name << "?" << endl;
	cin >> doubleAccuracy;

	cout << endl;
	cout << "what is the treble success rate of " << name << "?" << endl;
	cin >> trebleAccuracy;

	cout << endl;
	cout << "what is the bullseye success rate of " << name << "?" << endl;
	cin >> bullAccuracy;
}

int Player::GetBullAccuracy()
{
	return bullAccuracy;
}



int Player::GetTrebleAccuracy()
{
	return trebleAccuracy;
}



int Player::GetDoubleAccuracy()
{
	return doubleAccuracy;
}



int Player::GetSingleAccuracy()
{
	return singleAccuracy;
}



int Player::GetThrowPerGame()
{
	return throwsPerGame;
}

void Player::SetThrowPerGame()
{

	throwsPerGame = throwsPerGame + 1;

}

void Player::ResetThrowPerGame()
{

	throwsPerGame = 0;

}

int Player::GetTotalThrows()
{
	return totalThrows;
}

void Player::SetTotalThrows()
{

	totalThrows = totalThrows + 1;

}

string Player::GetName()
{
	return name;
}


int Player::GetBullHit()
{
	return totalbullHit;
}

void Player::SetBullHit()
{

	totalbullHit = totalbullHit + 1;

}

void Player::SetBullHitPerGame()
{

	bullhitPerGame = bullhitPerGame + 1;

}

int Player::GetBullHitPerGame()
{
	return bullhitPerGame;
}

void Player::ResetBullHitPerGame()
{

	bullhitPerGame = 0;

}

void Player::SetWin()
{

	wins = wins + 1;

}

int Player::GetWin()
{
	return wins;
}

void Player::Setwinrate(double newwinrate)
{

	winrate = newwinrate;

}

double Player::GetWinrate()
{
	return winrate * 100;
}


//shows the winner for 301 game
void Player::Winner()
{

	cout << "congrats " << name << " you have won and it took " << throwsPerGame << " number of throws and you hit " << bullhitPerGame << " bullseyes this game\n ";
	cout << endl;
	cout << "total throws throughout all games is " << totalThrows << " and total bullseyes for whole game is " << totalbullHit << endl;


}

void Player::SetroundWinner()
{
	roundWinner += 1;


}

int Player::GetroundWinner()
{
	return roundWinner;
}

void Player::ResetroundWinner()
{

	roundWinner = 0;

}

void Player::SetSetwinner()
{

	setsWinner += 1;

}

int Player::GetSetWinner()
{
	return setsWinner;
}

void Player::ResetSetWinner()
{
	setsWinner = 0;

}
