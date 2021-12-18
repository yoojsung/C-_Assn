// falafel.cpp : asks what the user wants from falafel, soda, extras, then calculates the total
//              then displays the result                

// CIS054 C/C++ Programming
// Jaesung Yoo
// INPUT F, S, X, or T
// OUTPUT how many items for each, subtotals for each, total subtotal, tax, and total

#include <iostream>
#include <cctype>
#include <iomanip>
void DisplayMenu();        // display the menu
using namespace std;

const double TAX_RATE = 0.087;

int main(int argc, char* argv[])
{
    //declare variables for subtotal, price for each, tax, total, and selection for the menu
    double subtotal = 0.00;
    double price;
    double tax;
    double total;
    char selection;
    int fCount = 0;
    int sCount = 0;
    int xCount = 0;

    cout << setiosflags(ios::fixed | ios::showpoint);	// C++ setup for display past decimal
    cout << setprecision(2);	// 2 digits past the decimal 

    DisplayMenu();
    do
    {
        price = 0;
        cout << "Make your selection (FSXT): ";
        cin >> selection;       //input: user chooses char for the menu
        switch (toupper(selection))     //uses switch case to determine which menu the user chose
        {
        case 'F':       //falafel
            price = 5.15;
            fCount++;   //increase count for falafel
            break;
        case 'S':       //soda
            price = 2.24;
            sCount++;   //increase count for soda
            break;
        case 'X':       //extra
            price = 1.57;
            xCount++;   //increase count for extra
            break;
        case 'T':       //calculate total
            break;
        default:        //otherwise, input is invalid
            cout << "Illegal selection, try again." << endl;
        }
        subtotal += price;//adds up the price to subtotal every loop
    } while (selection != 'T' && selection != 't');

    //process computes tax and total
    tax = subtotal * TAX_RATE; //computes the tax
    total = subtotal + tax; //cubputes the total by adding subtotal and tax
    //output: prints how many items for each, subtotals for each, total subtotal, tax, and total
    cout << fCount << " falafels: $" << fCount * 5.15 << endl;
    cout << sCount << " sodas: $" << sCount * 2.24 << endl;
    cout << xCount << " extras: $" << xCount * 1.57 << endl;
    cout << "   Subtotal $" << subtotal << endl;
    cout << "   Tax $" << tax << endl;
    cout << "   Total $" << total << endl;
    return 0;
}

void DisplayMenu()
{
    cout << endl;   // blank line before start of menu
    cout << "F = falafel  $5.15" << endl;
    cout << "S = soda     $2.24" << endl;
    cout << "X = extras   $1.57" << endl;
    cout << "T = total" << endl;
}

