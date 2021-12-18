/*
ElectricBill.cpp - computes the electric bill with a lower rate 
for the baseline kWh and a higher rate for kWh over the baseline
Input : kWh
Output : Electric Bill
CIS54 : C/C++ programming
Jaesung Yoo 
June 21 2021
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//define constant
const double TIER1_RATE = 0.23;
const double TIER2_RATE = 0.29;
const double TIER3_RATE = 0.45;
const double TAX = 0.20;
const double TIER1_ALLOWANCE = 350;
const double TIER2_ALLOWANCE = 1450;

//define public variables
string kWh;
double tier1;
double tier2;
double tier3;

bool isNumber(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}

void asdf(void)
{
	cin >> kWh;

	if (isNumber(kWh)) {
		int kWhTemp = stoi(kWh);
		if (kWhTemp < TIER1_ALLOWANCE) //use if and else ifs to apply corresponding changes to tier usages
		{
			tier1 = kWhTemp;
			tier2 = 0;
			tier3 = 0;
		}
		else if (kWhTemp < TIER2_ALLOWANCE)
		{
			tier1 = TIER1_ALLOWANCE;
			tier2 = kWhTemp - TIER1_ALLOWANCE;
			tier3 = 0;
		}
		else if (kWhTemp >= TIER2_ALLOWANCE)
		{
			tier1 = TIER1_ALLOWANCE;
			tier2 = TIER2_ALLOWANCE - TIER1_ALLOWANCE;
			tier3 = kWhTemp - TIER2_ALLOWANCE;
		}
	}
	else
		throw(0);
}

int main(int argc, char* argv[])
{
	//define variable 
	double electricBill;
	cout << "Enter kWh used: ";
	try {
		asdf();
		electricBill = tier1 * TIER1_RATE + tier2 * TIER2_RATE + tier3 * TIER3_RATE + TAX; //calculate the whole thing

		cout << setiosflags(ios::fixed | ios::showpoint);	// C++ setup for display past decimal
		cout << setprecision(2);	// 2 digits past the decimal 
		cout << "Tier 1 Usage " << tier1 << " kWh $" << tier1 * TIER1_RATE << endl;
		cout << "Tier 2 Usage " << tier2 << " kWh $" << tier2 * TIER2_RATE << endl;
		cout << "Tier 3 Usage " << tier2 << " kWh $" << tier2 * TIER3_RATE << endl;
		cout << "Energy Commision Tax $" << TAX << endl; 
		cout << "Total Electric Charges $" << electricBill << endl << endl; //print every information
	}
	catch (int errID) {
		cout << "Invalid input" << endl;
		return 1;
	}
	return 0;
}