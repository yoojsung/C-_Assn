// Student_Class.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
#include "Student.h"
using namespace std;

// define an array of students
Student CIS054[] = {
    Student("Joe Williams", 44536, 3.4, "CIS"),
    Student("Sally Washington", 55458, 3.7, "Math"),
    Student("Fred MacIntosh", 66587, 2.9, "English"),
    Student("Jose De La Cruz", 67892, 3.5, "Physics"),
    Student("777 Dan McElroy", 77777, 4.0, "CIS"),
    Student("Thinh Nguyen", 173657, 3.6, "Math")
};


int main(int argc, char* argv[])
{
    int NumberOfStudents = sizeof(CIS054) / sizeof(Student);

    // Display the header line
     // List all the students in the course
    cout << "ID #      NAME                MAJOR" << endl << "==============================================" << endl;
    for (int i = 0; i < NumberOfStudents; i++)
        cout << left << setw(10) << CIS054[i].getIdNumber() << left << setw(20) << CIS054[i].getName() << CIS054[i].getMajor() << endl;
    cout << endl;   // blank line after displaying the student names

    // compute the average gpa of all the students
    double total = 0;
    for (int i = 0; i < NumberOfStudents; i++)
        total += CIS054[i].getGpa();
    double average = total / NumberOfStudents;
    cout << "  " << "The average GPA of all the students is " << average << endl << endl;
    return 0;
}
