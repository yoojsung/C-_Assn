// Student_Class.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Student.h"
using namespace std;

// define an array of students
Student CIS054[] = {
    Student("Joe Williams", 44536, 3.4),
    Student("Sally Washington", 55458, 3.7),
    Student("Fred MacIntosh", 66587, 2.9),
    Student("Jose De La Cruz", 67892, 3.5),
    Student("777 Dan McElroy", 77777, 4.0),
    Student("Thinh Nguyen", 73657, 3.6)
};


int main(int argc, char* argv[])
{
    int NumberOfStudents = sizeof(CIS054) / sizeof(Student);

    // Display the header line
     // List all the students in the course
    for (int i = 0; i < NumberOfStudents; i++)
        cout << "  " << CIS054[i].getIdNumber() << "  " << CIS054[i].getName() << endl;
    cout << endl;   // blank line after displaying the student names

    // compute the average gpa of all the students
    double total = 0;
    for (int i = 0; i < NumberOfStudents; i++)
        total += CIS054[i].getGpa();
    double average = total / NumberOfStudents;
    cout << "  " << "The average GPA of all the students is " << average << endl << endl;
    return 0;
}
