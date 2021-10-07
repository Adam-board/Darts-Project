#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

#pragma once
class Player
{

private:
	int score;
	string name;
	int bullAccuracy;
	int trebleAccuracy;
	int doubleAccuracy;
	int singleAccuracy;
	int totalThrows;
	int throwsPerGame;
	int totalbullHit;
	int bullhitPerGame;
	int wins;
	double winrate;
	int roundWinner;
	int setsWinner;

public:

	Player();
	~Player();
	int GetScore();
	void SetScore(int);
	void SetScore501(int);
	void Setup301Score();
	void Setup501Score();
	
	void SetPlayerDetails();
	int GetBullAccuracy();
	void SetBullAccuracy();
	int GetTrebleAccuracy();
	void SetTrebleAccuracy();
	int GetDoubleAccuracy();
	void SetDoubleAccuracy();
	int GetSingleAccuracy();
	void SetSingleAccuracy();

	int GetThrowPerGame();
	void SetThrowPerGame();
	void ResetThrowPerGame();
	int GetTotalThrows();
	void SetTotalThrows();
	

	string GetName();
	void SetName();

	int GetBullHit();
	void SetBullHit();
	void SetBullHitPerGame();
	int GetBullHitPerGame();
	void ResetBullHitPerGame();

	void SetWin();
	int GetWin();

	void Setwinrate(double);
	double GetWinrate();
	void Winner();
	void SetroundWinner();
	int GetroundWinner();
	void ResetroundWinner();
	void SetSetwinner();
	int GetSetWinner();
	void ResetSetWinner();
};

