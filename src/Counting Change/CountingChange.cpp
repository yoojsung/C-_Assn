/*C++ Counting Change: calculates the change by counting the coins
* Jaesung Yoo
* CIS054
* Inputs: Numbers of penny, nickel, dime, and quarter
*/

#include <iostream>
#include <iomanip>
using namespace std;

// define the constants 
const double QUARTER_VALUE = 0.25; // 25 cents
const double DIME_VALUE = 0.1; // 10 cents
const double NICKEL_VALUE = 0.05; // 5 cents
const double PENNY_VALUE = 0.01; // 1 cent
int main(int argc, char* argv[])
{
	// define the variables 
	int pennies, nickels, dimes, quarters;
	double total;	// total should be in double because it will be additions of multiplications of the constant values which are double

	cout << "Jaesung's coin counting program: " << endl << endl; 
	//INPUT : number of quarters, dimes, nickels, pennies
	cout << "How many quarters do you have? "; //prompt
	cin >> quarters;
	if (cin.fail())			// gives an error message if the input is invalid 
	{
		cout << "Illegal entry for number of quaters" << endl;
		return 1;
	}
	if (quarters < 0)		// gives an error message if the input is negative (can be 0)
	{
		cout << "Negative values are not allowed" << endl;
	}
	cout << "How many dimes do you have? ";
	cin >> dimes;
	if (cin.fail())			// gives an error message if the input is invalid 
	{
		cout << "Illegal entry for number of dimes" << endl;
		return 1;
	}
	if (dimes < 0)			// gives an error message if the input is negative (can be 0)
	{
		cout << "Negative values are not allowed" << endl;
	}	cout << "How many nickels do you have? ";
	cin >> nickels;
	if (cin.fail())			// gives an error message if the input is invalid 
	{
		cout << "Illegal entry for number of nickels" << endl;
		return 1;
	}
	if (nickels < 0)		// gives an error message if the input is negative (can be 0)		
	{
		cout << "Negative values are not allowed" << endl;
	}
	cout << "How many pennies do you have? ";
	cin >> pennies;
	if (cin.fail())			// gives an error message if the input is invalid 
	{
		cout << "Illegal entry for number of pennies" << endl;
		return 1;
	}
	if (pennies < 0)		// gives an error message if the input is negative (can be 0)
	{
		cout << "Negative values are not allowed" << endl;
	}

	//PROCESS: computes the total amount using the information 
	//multiplies the number of coins to its corresponding values that were defined as constants above the main function
	//adds them up
	//total should be in double
	total = quarters * QUARTER_VALUE + dimes * DIME_VALUE + nickels * NICKEL_VALUE + pennies * PENNY_VALUE;

	//OUTPUT: displays the message with the total amount that was calculated in the PROCESS stage
	cout << endl << "Your total is $" << total;
	return 0;
}