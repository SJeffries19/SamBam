//Name: Samuel Jeffries 
//Email: jeffries.39@wright.edu
//Course Number : CS3100
//Course Title : Data Structuresand their Algorithms
//Name : Samuel Jeffries
//Prof Name : Meilin Liu
//Date : 1 / 27 / 2021
//Project Name : Project 1

/*Project works as intended but it does have a few issues I've found. However, to my knowledge none of these errors interfere with the project write-up. Also should be noted that I did look up the c++ library for
*help with things I didn't know what to do with. This is why I have a couple extra includes at the top of my file. Finally I tried my best to make everything easy to read, if there are any issues please let me know!
*Known concerns: 
*getline(ofstream, name) skips the first line in the all.last.txt file for some reason. I tried to google some fixes and couldn't find anything that worked.
*When the user is prompted for a number and they instead insert a string, the program freaks out a little bit. However I believe we were allowed to assume a perfect user unless otherwise specified.
*/

#include <iostream>
#include <string>
#include <fstream>
#include "assert.h"
#include <limits>
using namespace std;

//Method declarations
void call1();
void call2();
void call3();

//Main method is basically used as the menu. The while loop is used to prompt the user and gather input and only terminates when asked to quit.
int main()
{
	bool cont = true;

	while (cont)
	{
		//User prompt message.
		cout << "What would you like to do?" << endl;
		cout << "(1) Read a specified number of strings (last names) from the keyboard, and display them on the screen, and write them to the output file simultaneously." << endl;
		cout << "(2) Read a specified number of  strings (last names) from the input file, and display them on the screen, and write them to the output file simultaneously (The number of strings read should be specified from the keyboard (in the range of 10 - 99))." << endl;
		cout << "(3) Read two strings (last names) from the keyboard and test if these two strings are the same." << endl;
		cout << "(4) Quit. " << endl;

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
		else if (choice == 3)
		{
			call3();
		}
		else if (choice == 4)
		{
			cont = false;
			cout << "Thanks for using the program!" << endl;
		}
		else 
		{
			cout << "Error! Must be a valid input!" << endl << endl;
		}
	}
	system("pause"); //Allows me to see the results before the window closes.
	return 0;
}

/*
Method call1 corresponds with prompt message 1, "Read a specified number of strings (last names) from the keyboard, and display them on the screen, and write them to the output file simultaneously."
Gathers user input and outputs them both to the console and appends newFile that way I can add new names without erasing the old ones.
*/
void call1()
{
	//Declaration block
	ofstream out;
	out.open("newList.txt", ofstream::app);
	assert(!out.fail());
	int loop;
	int counter = 1;
	string name;
	//end

	//Expecting a integer, tends to freak out if given a string.
	cout << "Please specify the amount of strings you'd like to enter." << endl;
	cin >> loop;

	//Based on the integer given previously, this loops that many times to gather last names.
	cout << "Please enter the name(s) you wish to write to the file." << endl;
	for (int i = 0; i < loop; i++)
	{
		cin >> name;
		cout << "Name " << counter << ": " << name << endl;
		out << name << endl;
		counter++;
	}
	cout << endl;
	out.close();
}

/*
Method call2 corresponds with prompt message 2, "Read a specified number of  strings (last names) from the input file, and display them on the screen, and write them to the output file simultaneously 
(The number of strings read should be specified from the keyboard (in the range of 10 - 99))."
Gathers strings from the input file and outputs them both to the console and appends newFile that way I can add new names without erasing the old ones.
*/
void call2()
{
	//Declaration block
	ifstream in;
	in.open("all.last.txt");
	assert(!in.fail());
	ofstream out;
	out.open("newList.txt", ofstream::app);
	assert(!out.fail());
	int loop;
	int counter = 1;
	string name;
	bool cont = true;
	//end

	//Expecting a integer, tends to freak out if given a string.
	cout << "Please specify the amount of strings you'd like to read. (Between 10 & 99)" << endl;
	while (cont) 
	{
		cin >> loop;

		if (loop < 10 || loop > 99) //Check if input is valid
		{
			cout << "Invalid! Must be between 10 & 99! Please try again." << endl;
		}
		else //If so continue
		{
			cont = false;
		}
	}

	//Based on the integer given previously, this loops that many times to gather last names.
	for (int i = 0; i < loop; i++)
	{
		getline(in, name) >> name;
		cout << "Name " << counter << ": " << name << endl;
		out << name << endl;
		counter++;
	}
	cout << endl;
	out.close();
	in.close();
}

/*
Method call3 corresponds with prompt message 3, "Read two strings (last names) from the keyboard and test if these two strings are the same."
Gathers user inputs and outputs them both to the console. Then compares the strings to each other to see if they are the same name.
*/
void call3()
{
	string lastName1;
	string lastName2;

	cout << "Please enter last name #1." << endl;
	cin >> lastName1;
	cout << "Please enter last name #2." << endl;
	cin >> lastName2;

	if(lastName1.compare(lastName2) == 0) //Used compare method to check if the strings are the same.
	{
		cout << "Those two last names are the same!" << endl << endl;
	}
	else 
	{
		cout << "Those two last names are not the same!" << endl << endl;
	}
}