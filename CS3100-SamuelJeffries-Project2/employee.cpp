//Name: Samuel Jeffries 
//Email: jeffries.39@wright.edu
//Course Number : CS3100
//Course Title : Data Structuresand their Algorithms
//Name : Samuel Jeffries
//Prof Name : Meilin Liu
//Date : 2 / 11 / 2021
//Project Name : Project 2

/*
* The following file is the implementation of Meilin's given Employee.h
* All functionality is implemented correctly with no known errors. 
* It was certainly weird learning about how to contruct an object class when using a corresponding header file but I found success by using the employee name space.
* PRINT STATEMENTS ARE INCLUDED BUT COMMENTED OUT TO KEEP THE MENU FROM LOOKING MESSY.
* As you can see there are "cout" statements in every method. Just uncomment and test away!
*/

#include "Employee.h"
using namespace std;

//Default constructor needed to create the object.
Employee::Employee(int IdNum, string last, string first) 
{
	ID = IdNum;
	firstname = first;
	lastname = last;
	//cout << "Constructor has been called" << endl;
}

//Copy constructor copies the object passed in to make a new object with the same parameters as the old one.
Employee::Employee(const Employee& person)
{
	ID = person.ID;
	firstname = person.firstname;
	lastname = person.lastname;
	//cout << "Copy constructor has been called" << endl;
}

//Destructor frees up allocated space.
Employee::~Employee() { /*cout << "Destructor has been called" << endl;*/ }

//Setters (Needed to set the fields of a private variable)
void Employee::setFirstName(string first)
{
	firstname = first;
	//cout << "setFirstName() has been called" << endl;
}
void Employee::setLastName(string last)
{
	lastname = last;
	//cout << "setLastName() has been called" << endl;
}
void Employee::setID(int IdNum)
{
	ID = IdNum;
	//cout << "setID() has been called" << endl;
}

//Getters (Needed to access the fields of a private variable)
int Employee::getID() const
{
	//cout << "getID() has been called" << endl;
	return ID;
}
string Employee::getFirstName() const
{
	//cout << "getFirstName() has been called" << endl;
	return firstname;
}
string Employee::getLastName() const
{
	//cout << "getLastName() has been called" << endl;
	return lastname;
}

//Input stream operator (Extremely handy).
istream& operator>>(istream& ins, Employee& person)
{
	ins >> person.lastname >> person.firstname >> person.ID;
	//cout << "Overloading input stream operation has been called" << endl;
	return ins;
}

//Output stream operator (Kind've like a JAVA toString method).
ostream& operator<<(ostream& outs, const Employee& person) 
{
	outs << person.getLastName() << " " << person.getFirstName() << " " << person.getID();
	//cout << "Overloading output stream operation has been called" << endl;
	return outs;
}

//Boolean comparison overload operator using "==".
bool operator==(const Employee& p1, const Employee& p2)
{
	//cout << "Boolean '==' operation has been called" << endl;
	return
		(p1.getLastName() == p2.getLastName())
		&&
		(p1.getFirstName() == p2.getFirstName())
		&&
		(p1.getID() == p2.getID());
}

//Boolean comparison overload operator using "<".
bool operator<(const Employee& p1, const Employee& p2) 
{
	//cout << "Boolean '<' operation has been called" << endl;
	return (p1.getLastName() < p2.getLastName());
}