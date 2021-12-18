// FINAL
// NameSearch.cpp - reads the names from the file, then saves them into arrays for boys and girls separately
//                      asks to user which name they want to search for, then searches for them sequentially using for loops
//Jaesung Yoo
// CIS C/C++ Programming
// 7/20/21
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#define debug_messages 1

// define the max number of records in the file
const int LIST_LENGTH = 1000;

// define the lengths of each character array
const int NAME_SIZE = 40;
//const int NUMBER_SIZE = 13;
const int LINE_SIZE = 80;

bool searchName = false;
// define the structure for the array of records
typedef struct S_REC {
    char boys[NAME_SIZE];
    char girls[NAME_SIZE];
}Names;

int main(int argc, char* argv[])
{
    Names List[LIST_LENGTH];     // [length][width]
    char line[LINE_SIZE];           // line of text from the disk
    char filename[] = "/Users/jaesu/Desktop/FirstNames.txt"; //location and name of the file
    char* ptr;

    int boyRank = -1;
    int girlRank = -1;

    //Read the file into the List[ ] array
    ifstream NameFile(filename);

    if (!NameFile) {
        cerr << "Unable to open " << filename << endl;
        return 1;
    }

    int listsize = 0;
    line[0] = 0;                            // clear the line buffer
    NameFile.getline(line, LINE_SIZE);     // read the first line in the file
    while (!NameFile.eof() && listsize < LIST_LENGTH && line[0]) {
        if (strlen(line) > 1) {
            // pick a version of strtok and strcpy that works with your compiler

            // VERSION-1
            // These 5 lines work for Microsoft Visual Studio. Comment them out if using Version-2
            char* nextToken = NULL;                             // used only by strtok_s
            ptr = strtok_s(line, " ", &nextToken);              // find name, separated by space
            strcpy_s(List[listsize].boys, NAME_SIZE, ptr);     // copy name to array, position listsize
            ptr = strtok_s(NULL, ".\r\n", &nextToken);          // find naame
            strcpy_s(List[listsize].girls, NAME_SIZE, ptr); // copy to array, position listsize
            listsize++;
        }
        line[0] = 0;                            // clear the buffer
        NameFile.getline(line, LINE_SIZE);     // read next line
    }
#if debug_messages == 1		
    cout << "There are " << listsize << " lines in the file." << endl;
#endif
    while (true) //loops the same process forever, but there is an if statement that ends the program
    {
        /////////// request a search string, then find it //////////
        char searchString[80];
        cout << "Enter a name to search (quit to exit): ";
        // cin >> searchString;  // works fine for the phone number, but not the name
        // This is because the names have space characters. cin >> searchString stops
        // reading the input as soon as it sees a space and part of the name is lost
        // Use cin.getline(searchString,80);   instead to read a fill line from the keyboard.
        cin.getline(searchString, 80);

        if (_strcmpi("quit", searchString) == 0) //if quit is entered, the program ends
            return 0;
        //sequential search
        bool found = false;
        int  index;
        for (index = 0; index < listsize; index++)
        {
            if (_strcmpi(List[index].boys, searchString) == 0)
            {
                boyRank = index + 1;
                break;
            }
        }
        for (index = 0; index < listsize; index++)
        {
            if (_strcmpi(List[index].girls, searchString) == 0)
            {
                girlRank = index + 1;
                break;
            }
        }
        //OUTPUT: displaying the results, the rank will be -1 the name is not found
        //so checking if the rank is -1  or not tells if the name was found or not
        if (boyRank != -1)
            cout << searchString << " is ranked " << boyRank << " for boy names" << endl;
        if (girlRank != -1)
            cout << searchString << " is ranked " << girlRank << " for girl names" << endl;
        if (boyRank == -1)
            cout << searchString << " was not found for boys" << endl;
        if (girlRank == -1)
            cout << searchString << " was not found for girls" << endl;
        //resets ranks
        boyRank = -1;
        girlRank = -1;
    }
    return 0;
} //end of main
