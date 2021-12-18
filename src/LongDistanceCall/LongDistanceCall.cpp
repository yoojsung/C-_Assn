/*LongDistanceCall.cpp - computes the cost of a long distance call. The cost of the call is
*					determined according to the given rate schedule: 
*					Any call started between 8:00 am and 6:00 pm, Monday through Friday, is billed at a rate of $0.40 per minute.
*					Any call starting before 8:00 am or after 6:00 pm, Monday through Friday, is charged at a rate of $0.25 per minute.
*					Any call started on a Saturday or Sunday is charged at a rate of $0.15 per minute.
*CIS54 - C/C++ programming
* Jaesung Yoo
* June 28th, 2021
*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main(int arvc, char* argv[])
{
	//list of variables and constants
	const double WEEKEND_RATE = 0.15; //$0.15 per minute
	const double EVENING_RATE = 0.25; //$0.25 per minute
	const double DAY_RATE = 0.40; //$0.40 per minute
	char day1;		//first character of DayOfWeek
	char day2;		//second character of DayOfWeek
	int hour;		//Start time: hour
	char separator;	//Start time: between hour and minutes
	int minute;		//Start time: minutes
	int LengthOfCall;	//Length of call in minutes

	// used internally by the program
	char again;		//for loop control
	int TimeStarted;	//Time in 24hour clock
	double billingRate; //determined by day and time of call
	double CostofCall;  //computed and displayed

	do
	{
		//input the day of week
		cout << "Enter the day (Mo Tu We Th Fr Sa Su): ";
		cin >> day1 >> day2;	//input 2 characters to know which day of week it is
		day1 = toupper(day1); //convert to uppercase
		day2 = toupper(day2);

		//input the time the call was started
		cout << "Enter the time started (HH:MM): ";
		cin >> hour >> separator >> minute; // input time for start
		TimeStarted = hour * 100 + minute;

		//input the length of the call
		cout << "Enter the length of the call in minutes: ";
		cin >> LengthOfCall;

		//process : determine billingRate, then CostofCall
		if (day1 == 'S' && day2 == 'A')			//check if it is saturday
			billingRate = WEEKEND_RATE;
		else if (day1 == 'S' && day2 == 'U')	//check if it is sunday
			billingRate = WEEKEND_RATE;
		else	//then weekday
		{
			if (TimeStarted >= 800 && TimeStarted <= 1800)
				billingRate = DAY_RATE;
			else
				billingRate = EVENING_RATE;
		}
		CostofCall = LengthOfCall * billingRate;

		//output : display the output
		cout << setiosflags(ios::fixed | ios::showpoint);	// C++ setup for display past decimal
		cout << setprecision(2);	// 2 digits past the decimal 
		cout << "The cost of the call would be $" << CostofCall << endl;

		//loop control
		cout << "Another call (Y/N)? ";
		cin >> again;
		again = toupper(again);
	} while (again == 'Y');
	return 0;
}	//end of main