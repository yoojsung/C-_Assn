/*RollDice.cpp - rolls a pair of dice 1000 times and record the results 2-12, 
*				Displays the results after 1000 times
* Jaesung Yoo
* CIS54-C/C++ programming
* Output : results of 1000 rolls
* 7/2/2021
*/

#include <iostream>
#include <ctime>
using namespace std;

int rollDice();

int main(int argc, char* argv[])
{
	//initialize array for counter
	int counter[11] { 0 };
	for (int i = 0; i < 1000; i++) //adds the counters for the values
		counter[rollDice() - 2]++;
	for (int i = 2; i < 13; i++) //output: displays the results
		cout << i << " = " << counter[i-2] << endl;
}

int roll()
{
	//A static variable keeps its same memory location from the 
	//time the program starts until it exits
	static bool randomInitialized = false;
	//A local variable gets a new memory location and needs to be 
	//initialized each time the program enters a block of code {...}
	int points;

	if (!randomInitialized)
	{
		srand((unsigned int)time(NULL));
		randomInitialized = true;
	}
	//rand returns a value from 0 to the largest possible integer
	points = (rand() % 6 + 1);
	return points;
}

int rollDice()
{
	return roll() + roll();
}