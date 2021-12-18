/*TortoiseAndHareLab.cpp - the race of tortoise and hare. Using random, the tortoise and hare does random move which determines
*					if they get to move foward of backward. The goal is 70 squares, and if they are on the same square tortoise bites the hare
* Jaesung Yoo
* C++ programming
* 7/14/21
*/

#include <iostream>
#include <cstdlib>  //for srand
#include <ctime>
using namespace std;

int main(int argc, char* argv[])
{
	bool end = false;
	int tor = 0;
	int hare = 0;

	cout << "BANG!!!!!" << endl << "AND THEY'RE OFF!!!!!" << endl << endl;
	srand((unsigned int)time(0));
	while (!end)
	{
		cout << endl;
		int randRes = rand() % 11;
		if (randRes < 5)
			tor += 3;
		else if (randRes < 7)
			tor -= 1;
		else
			tor += 1;

		if (randRes < 2)
			hare += 9;
		else if (randRes < 3)
			hare -= 12;
		else if (randRes < 6)
			hare += 1;
		else if (randRes < 8)
			hare -= 2;
		//else sleep = nothing

		if (tor < hare) {
			for (int i = 1; i < tor; i++)
				cout << '=';
			cout << 'T';

			for (int i = 1; i < hare - tor; i++)
				cout << '=';

			cout << 'H';

			for (int i = 1; i < 70 - hare; i++)
				cout << '=';

			cout << endl;
		}
		else if (hare < tor) {
			for (int i = 1; i < hare; i++)
				cout << '=';
			cout << 'H';

			for (int i = 1; i < tor - hare; i++)
				cout << '=';

			cout << 'T';

			for (int i = 1; i < 70 - tor; i++)
				cout << '=';

			cout << endl;
		}
		else {
			for (int i = 1; i < hare; i++)
				cout << '=';
			cout << 'B';

			for (int i = 1; i < 70 - hare; i++)
				cout << '=';

			cout << endl << "OUCH !!!" << endl;
		}

		if (hare >= 70)
		{
			cout << "Hare wins!";
			end = true;
		}
		else if (tor >= 70)
		{
			cout << "Tortoise wins!";
			end = true;
		}
	}
}
