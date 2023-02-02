//Name: Samuel Jeffries 
//Email: jeffries.39@wright.edu
//Course Number : CS3100
//Course Title : Data Structuresand their Algorithms
//Name : Samuel Jeffries
//Prof Name : Meilin Liu
//Date : 2 / 11 / 2021
//Project Name : Project 2

/*
* Employee.h given by Meilin. Functionality is implemented in employee.cpp.
* Also decided to add the includes I use throughout my program in the .h so I can include them everywhere else with one line of code.
*/



//Employee.h provided by Dr. Meilin Liu in Fall 2020, and you can modify it if you want. 

//Definitions
#ifndef _Employee_
#define _Employee_

//Includes
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "assert.h"
#include <limits>
#include "Employee.h"
using namespace std;

//Declaration of methods used in employee.cpp
class Employee {

public:
	Employee(int IdNum = 11111, string last = "lastname", string first = "firstname");
	Employee(const Employee& person);
	~Employee();

	void setFirstName(string first);
	void setLastName(string last);
	void setID(int IdNum);
	int getID() const;
	string getFirstName() const;
	string getLastName() const;

	friend istream& operator>>(istream& ins, Employee& person);

private:
	int ID;
	string lastname;
	string firstname;
};

ostream& operator<<(ostream &outs, const Employee &person);
bool operator==(const Employee& p1, const Employee& p2); // test if two employees are the same. 
bool operator<(const Employee& p1, const Employee& p2); // test if one employee's last name is less than another employee's. 

#endif