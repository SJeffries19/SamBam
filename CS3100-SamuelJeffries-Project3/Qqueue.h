//Name: Samuel Jeffries 
//Email: jeffries.39@wright.edu
//Course Number : CS3100
//Course Title : Data Structuresand their Algorithms
//Name : Samuel Jeffries
//Prof Name : Meilin Liu
//Date : 3 / 14 / 2021
//Project Name : Project 3

/*
* Qqueue.h given by Meilin. Functionality is implemented in Qqueue.cpp.
* Also decided to add the includes I use throughout my program in the .h so I can include them everywhere else with one line of code.
*/


#ifndef _QueueClass_
#define  _QueueClass_

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "assert.h"
#include <limits>
#include "Qqueue.h"
using namespace std;

class Qqueue
{
        public:
                // Constructor
                Qqueue(int cap );

                // Copy Constructor
                Qqueue(const Qqueue& s);

                ~Qqueue(); //destructor
				
		// The member function enqueue: Precondition:  the queue is not full.  If the queue is full, this function signals an error.
                //add value to the end of the queue
		void enqueue ( const string&  s); 

				
		// The member function dequeue: Precondition:  the queue is not empty. If the queue is empty, this function signals an error.
		// Removes and returns the first item in the queue.
        string dequeue ();

		// The member function front: Precondition: the queue is not empty.
        string&  getfront () const;
				
		// The member function back: Precondition: the queue is not empty.
        string&  getback () const;

        bool IsEmpty () const;

		//printing all the elements in the queue
		void print() const;

        int size() const;

		int getCapacity() const;

		//Returns true if the two queues contain exactly the same element values in the same order. Identical in behavior to the == operator.
		bool equals(const Qqueue& q) const;  
		// Usage: if (q.equals(q2)) ...

        private:
                int capacity; // Capacity is the maximum number of items that a queue can hold
                string* dynamicQueue; 
                int num; // How many items are stored in the queue
                int front;
                int back;
};	
#endif
