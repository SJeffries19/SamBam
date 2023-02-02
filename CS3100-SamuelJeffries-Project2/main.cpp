//Name: Samuel Jeffries 
//Email: jeffries.39@wright.edu
//Course Number : CS3100
//Course Title : Data Structuresand their Algorithms
//Name : Samuel Jeffries
//Prof Name : Meilin Liu
//Date : 2 / 11 / 2021
//Project Name : Project 2

/*
* This project is very similar to the previous project so I actually used the same menu layout to save me time.
* All functionality is tested correctly in this main file and the only known issue is that when reading from the file is skips the first line.
* See the header comment before each method the understand the individual pieces of functionality.
*/

#include "Employee.h"
using namespace std;

//Declaring my methods
void call1();
void call2();
void call3OptionA();
void call3OptionB();

/* Main method is basically used as the menu. The while loop is used to prompt the user and gather input and only terminates when asked to quit.
* Also added the creation of the "myself" test employee with my personal credentials in menu option 4. 
* I did this in multiple different ways to show my understanding of setter methods, getter methods, overload operators, destructor, and the copy constructor.
*/
int main()
{
	bool cont = true; //cont for while loop

	while (cont)
	{
		//User prompt message.
		cout << "\nWhat would you like to do?" << endl;
		cout << "(1) Read an employee record from the keyboard, and display it on the screen, and write it to the output file simultaneously." << endl;
		cout << "(2) Read a specified number of the employee records from the input file, and display them on the screen, and write them to the output file simultaneously (in the range of 1 to 99)." << endl;
		cout << "(3) Read two employee records and test if these two employees are the same." << endl;
		cout << "(4) Test the employee.cpp classes for fun (Uses my credentials to make an Employee object)" << endl;
		cout << "(5) Quit. " << endl;

		int choice;
		cin >> choice;
		//Determines what method to call based on user input.
		if (choice == 1) 
		{
			call1();
		}
		else if (choice == 2) 
		{
			call2();
		}
		else if (choice == 3) //This if statment has sub sections to test the 2 different ways of comparing employees.
		{
			cout << " \nPlease choose one of the following." << endl;
			cout << "Option A: Read two employee records from the input file, and test if these two employees are the same." << endl;
			cout << "Option B: Read two employee records from the keyboard, and test if one employees last name is less than another employees last name." << endl;

			char option;
			cin >> option;

			if (option == 'A' || option == 'a')
			{
				call3OptionA();
			}
			else if (option == 'B' || option == 'b')
			{
				call3OptionB();
			}
			else 
			{
				cout << "Error: Next time enter either the character A or B" << endl;
			}

		}
		else if (choice == 4) 
		{
			Employee myself(0, "blank", "blank"); // <- Normal way to construct an object.
			cout << "\nYour default name is " << myself.getID() << " "<< myself.getLastName() << " " << myself.getFirstName() << endl; //Showing off the use of the getter methods.

			myself.setID(947865);
			myself.setLastName("Jeffries");
			myself.setFirstName("Samuel");
			//Using the setter methods to change the values.

			Employee myselfCopy(myself); //This is proof that my copy constructor works.
			cout << "Your new name is " << myselfCopy << endl; //Print statement to show that all of the testing done with my Employee object works.
			myselfCopy.~Employee(); //Shows off use of destructor in main.
		}
		else if (choice == 5)
		{
			cont = false;
			cout << "Thanks for using the program!";
		}
		else 
		{
			cout << "Error! Must be a valid input!" << endl;
		}
	}
	return 0;
}

/*
* Method call1 corresponds with prompt message 1, "Read an employee record from the keyboard, and display it on the screen, and write it to the output file simultaneously."
* Gathers user input and outputs the created employee both to the console and appends NewDatabase.txt that way I can add new employees without erasing the old ones.
*/
void call1()
{
	//Declaration block
	ofstream out;
	out.open("NewDatabase.txt", ofstream::app);
	assert(!out.fail());
	Employee temp;
	//end

	cout << "\nPlease enter a valid employee! (Lastname, Firstname, ID (From 0 to 9999999)" << endl;
	cin >> temp;
	if (temp.getID() < 0 || temp.getID() > 9999999) 
	{
		cout << "Next time please enter a valid employee ID!(From 0 to 9999999)" << endl;
	}
	else 
	{
		out << temp << endl;
		cout << temp << endl;
	}
	out.close();
}

/*
* Method call2 corresponds with prompt message 2, "Read a specified number of the employee records from the input file, and display them on the screen, and write them to the output file simultaneously (in the range of 1 to 99)."
* Gathers employees from the input file and outputs them both to the console and appends NewDatabase.txt that way I can add new names without erasing the old ones.
*/
void call2()
{
	//Declaration block
	ifstream in;
	in.open("Small-Database.txt");
	assert(!in.fail());
	ofstream out;
	out.open("NewDatabase.txt", ofstream::app);
	assert(!out.fail());
	int loop;
	string name;
	bool cont = true;
	Employee temp;
	//end

	//Expecting a integer, tends to freak out if given a string. If error implementation was required I would insert a try catch here.
	cout << " \nPlease specify the amount of employees you'd like to read. (Between 1 & 99)" << endl;
	while (cont) 
	{
		cin >> loop;

		if (loop < 1 || loop > 99) //Check if input is valid
		{
			cout << "Invalid! Must be between 1 & 99! Please try again." << endl;
		}
		else //If so continue
		{
			cont = false;
		}
	}

	//Based on the integer given previously, this loops that many times to gather last names.
	for (int i = 0; i < loop; i++)
	{
		getline(in, name) >> temp;
		cout << temp << endl;
		out << temp << endl;
	}
	cout << endl;
	out.close();
	in.close();
}

/*
* Method call3OptionA corresponds with prompt message 3, "Read two employee records and test if these two employees are the same."
* as well as sub message "Option A: Read two employee records from the input file, and test if these two employees are the same."
* Gathers an index from the user and then compares two employees at the given index to see if they are the same.
* I added the index functionality so you aren't always comparing the same two people at the beginning of the file.
*/
void call3OptionA()
{
	//Declaration block
	ifstream in;
	in.open("Small-Database.txt");
	assert(!in.fail());
	Employee temp1;
	Employee temp2;
	string name;
	int index;
	bool cont = true;
	//end

	cout << "\nWhich index would you like to test two employees?" << endl;
	cin >> index;

	//based on the index given, it skips through the database to start reading at the given postion.
	while (cont) 
	{
		if (index != 0) 
		{
			getline(in, name); //blank get line to skip lines in the file.
			index--;
		}
		else {
			getline(in, name) >> temp1; //Reading in the data from the file for real.
			getline(in, name) >> temp2;
			cont = false;
		}
	}

	if ((temp1 == temp2) == 0) //if false
	{
		cout << temp1 << " does not equal " << temp2 << "! (False)" << endl;
	}
	else //if true
	{
		cout << temp1 << " & " << temp2 << " are equal! (True)" << endl;
	}
}

/*
* Method call3OptionB corresponds with prompt message 3, "Read two employee records and test if these two employees are the same."
* as well as sub message "Option B: Read two employee records from the keyboard, and test if one employees last name is less than another employees last name."
*/
void call3OptionB()
{
	//Declaration block
	Employee temp1;
	Employee temp2;
	//end

	cout << "\nPlease enter employee 1 (Lastname, Firstname, ID)" << endl;
	cin >> temp1;
	if (temp1.getID() < 0 || temp1.getID() > 9999999)
	{
		cout << "Next time please enter a valid employee ID!(From 0 to 9999999)" << endl;
	}
	else 
	{
		cout << "\nPlease enter employee 2 (Lastname, Firstname, ID)" << endl;
		cin >> temp2;

		if (temp2.getID() < 0 || temp2.getID() > 9999999)
		{
			cout << "Next time please enter a valid employee ID!(From 0 to 9999999)" << endl;
		}
		else 
		{
			if ((temp1 < temp2) == 0) //if false
			{
				cout << temp1 << " is not less than " << temp2 << "! (False)" << endl;
			}
			else //if true
			{
				cout << temp1 << " is less than " << temp2 << "! (True)" << endl;
			}
		}
	}
}