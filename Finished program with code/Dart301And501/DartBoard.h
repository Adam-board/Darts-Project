#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>



#pragma once
class DartBoard
{

private:
	
	int Throw;


protected:

	//is the values next to the value you are throwing for
	
	int boardNeighbours[2][21]{
		{0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
		{0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1}
	};



public:

	DartBoard();
	~DartBoard();
	int SingleThrow(int, int);
	int bullThrow(int);
	int GetThrow();
	void SetThrow(int);

	




};

