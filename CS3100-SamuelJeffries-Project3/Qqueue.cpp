//Name: Samuel Jeffries 
//Email: jeffries.39@wright.edu
//Course Number : CS3100
//Course Title : Data Structuresand their Algorithms
//Name : Samuel Jeffries
//Prof Name : Meilin Liu
//Date : 3 / 14 / 2021
//Project Name : Project 3

/*
* The following file is the implementation of Meilin's given Qqueue.h
* All functionality is implemented correctly with no known errors.
* enqueue and dequeue were a bit of a challenge as I kept running into errors where my queue's had null's in them. All fixed now though and I learned a bunch in the process.
*/

#include "Qqueue.h"
using namespace std;

//Default constructor needed to create the queue.
Qqueue::Qqueue(int cap) 
{
	capacity = cap;
	dynamicQueue = new string[capacity];
}

//Copy constructor copies the object passed in to make a new object with the same parameters as the old one.
Qqueue::Qqueue(const Qqueue& s) 
{
	dynamicQueue = s.dynamicQueue;
	capacity = s.capacity;
}

//Destructor frees up allocated space.
Qqueue::~Qqueue() { delete[] dynamicQueue; }

//Enqueue adds a string to the end of the queue if the queue is not already full. Also checks for an empty input which was originally giving me an issue where my queue had a null in it.
void Qqueue::enqueue(const string& s) 
{
	if (IsEmpty()) 
	{
		dynamicQueue[back] = s;
		back = (back + 1);
		num++;
	}
	else if(size() == capacity)
	{
		cout << "Enqueue error: Queue full!" << endl;
	}
	else 
	{
		dynamicQueue[back] = s; 
		back = (back + 1);
		num++;
	}
}

//Dequeue removes a string from the front of the queue if the queue is not empty. Returns empty string if queue is empty.
string Qqueue::dequeue()
{
	if (IsEmpty())
	{
		cout << "Dequeue error: Queue empty!" << endl;
		return "";
	}
	else
	{
		string o = dynamicQueue[front]; 
		front = (front + 1);
		num--;
		cout << "Dequeue: " << o << endl;
		return o;
	}
}

//getfront simply returns the string at position "front" if the queue is not empty.
string& Qqueue::getfront() const 
{
	if (IsEmpty())
	{
		cout << "getFront error: Queue empty!" << endl;
	}
	else 
	{
		cout << "Front: " << dynamicQueue[front] << endl; //[front + 1] weird fix to pass the null at the front
		return dynamicQueue[front]; //[front + 1] weird fix to pass the null at the front
	}
} 

//getfront simply returns the string at position "back" if the queue is not empty.
string& Qqueue::getback() const 
{
	if (IsEmpty())
	{
		cout << "getBack error: Queue empty!" << endl;
	}
	else
	{
		cout << "Back: " << dynamicQueue[back - 1] << endl;
		return dynamicQueue[back - 1];
	}
}

//Tets if the queue is empty and then returns a boolean.
bool Qqueue::IsEmpty() const 
{
	return (num == 0);
}

//Prints every value in the queue unless the queue is empty.
void Qqueue::print() const 
{
	int temp = front;
	if (IsEmpty())
	{
		cout << "Print error: Queue empty!" << endl;
	}
	while (temp < back) 
	{
		cout << "Print: " << dynamicQueue[temp] << endl;
		temp++;
	}
}

//Returns "num"/ the size of the queue
int Qqueue::size() const 
{
	return num;
}

//Getter for capacity
int Qqueue::getCapacity() const 
{
	return capacity;
}

//Tests if the this queue is equal to the queue passed in. Checks both of their sizes and then checks the individuals in order to see if they are the same queue. 
bool Qqueue::equals(const Qqueue& q) const 
{
	bool cont = true;
	int temp = 0;

	if (this->size() != q.size()) 
	{
		return false;
	}

	while(cont) 
	{
		if (dynamicQueue[temp] == q.dynamicQueue[temp]) 
		{
			if (size() == temp) 
			{
				return true;
			}
			temp++;
		}
		else 
		{
			return false;
		}
	}
}