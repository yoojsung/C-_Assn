/*
* C++ SumAverageRange.cpp
* CIS54 C/C++ programming
* Jaesung Yoo
* 
* Inputs: 10 numbers
* Outputs: sum of odd numbers, sum of even numbers, sum of all numbers,
*			lowest and highest numbers
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int NUMBER_COUNT = 10;

int main(int argc, char* argv[])
{
	int sumOfOddNumbers = 0;
	int sumOfEvenNumbers = 0;
	int sumOfAllNumbers = 0;
	int minValue = 0;
	int maxValue = 0;
	int number;
	int inputCounter = 1;
	double averageOfAllNumbers = 0;

	//Input : numbers 
	while (inputCounter <= NUMBER_COUNT) // while loops NUMBER_COUNT times using inputCounter from 1
	{
		cout << "Enter a number: ";
		cin >> number;

		if (cin.fail() || number < 0)
		{
			cout << "Illegal input for number";
			return 1;
		}

		// determine if the number is odd or even
		if (number % 2 == 1)
			sumOfOddNumbers += number;
		else
			sumOfEvenNumbers += number;

		//add the total of all numbers
		sumOfAllNumbers += number;

		//determine the range of the input by saving the max and min value
		if (inputCounter == 1)
		{
			minValue = number;	//initialize the max and min to the fist value on the first loop
			maxValue = number;
		}
		else
		{
			if (number < minValue)	//only update if current number is less than the minValue that is saved
				minValue = number;
			if (number > maxValue)  //only update if current number is greater than the maxValue that is saved
				maxValue = number;
		}

		inputCounter++; // counter for while loop condition
	} //end of while loop

	averageOfAllNumbers = (double) sumOfAllNumbers / NUMBER_COUNT; // sumOfAllNumbers casts into double since average is double

	//OUTPUT: display the results 
	cout << setiosflags(ios::fixed | ios::showpoint);	// C++ setup for display past decimal
	cout << setprecision(2);	// 2 digits past the decimal 
	cout << endl;
	cout << "Sum of Odd Numbers:           " << sumOfOddNumbers << endl;
	cout << "Sum of Even Numbers:          " << sumOfEvenNumbers << endl;
	cout << "Sum of All Numbers:           " << sumOfAllNumbers << endl;
	cout << "The lowest value is:          " << minValue << endl;
	cout << "The highest value is:         " << maxValue << endl;
	cout << "The average of all number is: " << averageOfAllNumbers << endl << endl;
	return 0;
}