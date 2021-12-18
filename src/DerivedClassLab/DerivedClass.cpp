// Derived-Class.cpp : Derived classes from the base class called Person. Contains classes Student, Teacher, and Employee
//						Saves information needed for each class then prints out the information needed
//Jaesung Yoo 
//CIS54 - C++ programming
//7/12/21
//
#include <iostream>
#include <cstring>
using namespace std;

////////////// Person class Definition /////////////////
class Person {
protected:  // A derived class can access protected data
	char Name[20];
public:
	Person(const char* n)
	{
		// choose the version of strcpy for your compiler
		// comment out the other 
		strcpy_s(Name, n);  // for Microsoft
		//strcpy(Name, n);  // for everywhere except Microsoft
	}
	virtual void print() const
	{
		cout << "Person:  " << Name << endl;
	}
};

///////////// Student class Definition //////////////
class Student : public Person {
private:
	int    units;
public:
	// Student constructor gets name from Person class
	Student(const char* n, int u) : Person(n)
	{
		units = u;
	}
	virtual void print() const
	{
		cout << "Student: " << Name << "  Units: " << units << endl;
	}
};

//////////// Teacher class Definition /////////////////
class Teacher : public Person {
private:
	int    numberOfStudents;
	int	   numberOfClasses;
public:
	// Teacher constructor gets 'name' from the Person class
	Teacher(const char* n, int s, int c) : Person(n)
	{
		numberOfStudents = s;
		numberOfClasses = c;
	}
	virtual void print() const
	{
		cout << "Teacher: " << Name
			<< "  Students: " << numberOfStudents
			<< "  Classes: " << numberOfClasses << endl;
	}
};

//////////// Employee class Definition /////////////////
class Employee : public Person {
private:
	int EmpNo;	//employee number
	double Hours;
	double PayRate;
	double Pay;
public:
	// Employee constructor gets name from Person class
	Employee(const char* n, int e, double h, double p) : Person(n)
	{
		EmpNo = e;
		Hours = h;
		PayRate = p;
		Pay = Hours * PayRate;
	}
	virtual void print() const
	{
		cout << "Employee: " << Name
			<< " Pay: " << Pay << endl;
	}
};

/////////// main program ///////////////////////
int main(int argc, char* argv[])
{
	// create objects from several different types of classes
	Student s1("Joe Williams", 12);
	Student s2("Mary Smith  ", 9);
	Student s3("Tam  Nguyen ", 10);
	Student s4("Jose Chavez ", 11);
	Teacher t1("Dan McElroy ", 28, 3);
	Teacher t3("Fred Jones  ", 18, 2);
	Employee e1("John Smith", 102, 40, 17);
	Employee e2("Steve Rogers", 132, 30, 15);
	Employee e3("King Qwer", 68, 10, 20);

	// Create an array of pointers to different people
	// NOTE: The array of pointers is not in the same order as the above list
	Person* List[] = { &t1, &s2, &s3, &s4, &s2, &t3, &e1, &e2, &e3};
	int SizeOfList = sizeof(List) / sizeof(Person*);

	for (int i = 0; i < SizeOfList; i++)
	{
		// call the appropriate virtual print routine based
		// on the type of object being pointed to
		List[i]->print();
	}
	return 0;
}
