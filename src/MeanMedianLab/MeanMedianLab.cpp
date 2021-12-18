// MeanAndMedianOfDataFile.cpp - takes in an input file using fstream then computes the mean and median of the numbers from the file
//
// Jaesung Yoo
// C++ programming
// 7/16/21
//
#include <iostream>
#include <fstream>
#include <cstdlib>  // used by the exit() functiona
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
    // variables to control the disk file
    ifstream infile;
    char filename[200];
    int  recordCount = 0;
    int  recordsToSkip = 0;
    // variables for fields of each record in the file
    int    AcctNo = 0;
    char   Name[100] = "";
    double AcctBal = 0.0;
    // varible used to determine the median
    double median = 0.0;
    double mean = 0.0;
    double total = 0.0;
    bool even = false;

    cout << setiosflags(ios::fixed | ios::showpoint);	// C++ setup for display past decimal
    cout << setprecision(3);	// 3 digits past the decimal 
    cout << "Enter the name of the data file: ";
    cin.getline(filename, 200);

    // ---- PART 1, Count the number of records in the file
    //      Determine the mean when you know the record count and the total of all balances
    infile.open(filename);
    if (infile.fail())
    {
        cerr << "Unable to open --" << filename << "--, first pass" << endl;
        exit(1);
    }
    while (!infile.eof())   // while not end of file
    {
        AcctBal = 0;
        Name[0] = 0;        // initialize to 0 to test for empty records/
        infile >> AcctNo >> Name >> AcctBal;
        total += AcctBal;
        if (Name[0] != 0)   // ignore empty records
            recordCount++;
    }
    infile.close();
    cout << "There are " << recordCount << " records in " << filename << endl;
    mean = total / recordCount;

    // ---- PART 2, Determine the number of records to skip
    if (recordCount % 2 == 1)
        recordsToSkip = recordCount / 2;      // Odd number of records
    else
    {
        recordsToSkip = recordCount / 2 - 1;  // Even number of records
        even = true;
    }

    // ---- PART 3, open the file, skip leading records, determine the median
    infile.open(filename);
    if (infile.fail())
    {
        cerr << "Unable to open --" << filename << "--, first pass" << endl;
        exit(1);
    }
    recordCount = 0;
    while (!infile.eof())   // while not end of file
    {
        Name[0] = 0;        // initialize to 0 to test for empty records/
        infile >> AcctNo >> Name >> AcctBal;
        
        if (recordCount == recordsToSkip)
        {
            if (even)
            {
                double temp = AcctBal;
                infile >> AcctNo >> Name >> AcctBal;
                median = (temp + AcctBal) / 2;
            }
            else
                median = AcctBal;
            break;
        }
        if (Name[0] != 0)   // ignore empty records
            recordCount++;
    }
    infile.close();

    // Display the results
    cout << "The mean of " << filename << " is " << mean << endl << endl;
    cout << "The median of " << filename << " is " << median << endl << endl;
    
    return 0;
}
