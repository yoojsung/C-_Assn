/*MetricToEnglish.cpp - Converts either metric to english unit or english to metric unit using a menu using do loop
* CIS54 C/C++ programming
* Jaesung Yoo
* July 1st, 2021
*/

#include <iostream>	//for cin and cout
#include <cctype>	//for upper function
#include <iomanip>
char menuSelect();	//returns 'E' or 'M'
using namespace std;

int main(int argc, char* argv[])
{
	double inches; 
	double centimeters;
	char select;

	cout << setiosflags(ios::fixed | ios::showpoint);	// C++ setup for display past decimal
	cout << setprecision(1);	// 1 digits past the decimal 

	do {
		select = menuSelect();
		try
		{
			if (select == 'E')
			{
				cout << "Enter the number of inches: ";
				//INPUT: number of inches
				cin >> inches;
				if (cin.fail()) //error check
					throw(1);
				else if (inches < 0)
					throw(0);
				//PROCESSING: computes into centimeters
				centimeters = inches * 2.54;
				//OUTPUT: prints out the message with 2 units
				cout << inches << " inches is equal to " << centimeters << " centimeters" << endl;
			}
			else if (select == 'M')
			{
				cout << "Enter the number of centimeters: ";
				//INPUT: number of centimeters
				cin >> centimeters;
				if (cin.fail()) //error check
					throw(1);
				else if (centimeters < 0)
					throw(0);
				//PROCESSING: computes into inches
				inches = centimeters / 2.54;
				//OUTPUT: prints out the message with 2 units
				cout << centimeters << " centimeters is equal to " << inches << " inches" << endl;
			}
		}
		catch (int errId) {
			if (errId == 0)
				cout << "Negative input error" << endl;
			else
				cout << "Invalid input" << endl;
			return 1;
		}
	} while (select != 'Q');
	return 0;
}

char menuSelect()
{
	char selection;
	do {
		cout << endl;
		cout << "Enter E to convert English to Metric, or M to convert Metric to English or Q to quit: ";
		cin >> selection;
		selection = toupper(selection);		//convert to uppercase for easier check
	} while (selection != 'E' && selection != 'M' && selection != 'Q');		//verify legal selection
	return selection;
}