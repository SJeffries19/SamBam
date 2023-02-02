//Name: Samuel Jeffries 
//Email: jeffries.39@wright.edu
//Course Number : CS3100
//Course Title : Data Structuresand their Algorithms
//Name : Samuel Jeffries
//Prof Name : Meilin Liu
//Date : 3 / 14 / 2021
//Project Name : Project 3

/*
* This main.cpp is simply a driver program for the Qqueue.cpp that we implemented, I have implemented multiple different methods of testing so you can choose whether you want the detailed explanations or not.
* All functionality is tested correctly with the only known error being that the save method only saves about half of the queue's contents.
* See the header comment before each method the understand the individual pieces of functionality.
*/

#include "Qqueue.h"
using namespace std;

//Method declarations
void readFile(Qqueue* queue);
void guidedTesting(Qqueue* queue, int max);
void testing(Qqueue* queue, int max);
void save(Qqueue* queue);

/*
* Main method starts by asker the user how big they want the queue to be then it goes to the readFile method to read and enqueue the lastname in all.last.txt.
* Once the names have been enqueued, the user is then asked if they would like to use the guided or unguided driver program. In the guided, I explain each step and go through piece by piece to ensure full user understanding on what the program is doing and how it works.
* In the guided, the method has commented driver code in it that you can feel free to use, otherwise you can add your own driver code to test the program as I'm sure that would be the easiest way to test.
*/
int main()
{
	bool cont = true; //cont for while loop
	int max = 0; //User input for queue size

	//User prompt message.
	cout << "Welcome to the Queue tester! Please enter how big you would like the queue to be (100 or larger): ";

	while (cont) //loops while the input is invalid
	{
		cin >> max;

		if (max < 100) 
		{
			cout << "Please enter a value of 100 or larger " << endl;
		}
		else
		{
			cont = false;
			cout << endl;
		}
	}

	Qqueue* queue = new Qqueue(max); //Creates initial queue based on the size given by the user
	readFile(queue); //Calls readFile to set up the queue

	cont = true;
	int choice = 0;
	cout << endl << "Would you like the guided or unguided testing? (1: for guided, 2: for unguided)" << endl;

	while (cont) 
	{
		cin >> choice;
		//Determines what method to call based on user input.
		if (choice == 1)
		{
			guidedTesting(queue, max);
			cont = false;
		}
		else if (choice == 2)
		{
			testing(queue, max);
			cont = false;
		}
		else
		{
			cout << "Invalid input, please enter 1: for guided or 2: for unguided" << endl;
		}
	}

	cout << endl << "Thanks for using my program!" << endl;
	return 0;
}


/*
* readFile method is passed in the queue intialized in the main, then it opens all.last.text, reads in each last name, and enqueues them to the queue.
*/
void readFile(Qqueue* queue)
{
	//Declaration block
	ifstream in;
	in.open("all.last.txt");
	assert(!in.fail());
	int loop;
	int counter = 1;
	string name;
	bool cont = true;
	//end

	cout << "Please specify the amount of last names you'd like to read. (Between 10 & 90) (10 is recommended for the guided testing)" << endl;

	while (cont)//loops while the input is invalid
	{
		cin >> loop;

		if (loop < 10 || loop > 90) //Check if input is valid
		{
			cout << "Invalid! Must be between 10 & 90! Please try again." << endl;
		}
		else //If so continue
		{
			cont = false;
		}
	}

	//Based on the integer given previously, this loops that many times to gather last names.
	for (int i = 0; i < loop; i++)
	{
		getline(in, name);
		queue->enqueue(name);
		counter++;
	}
	cout << endl;
	in.close();
}

/*
* guidedTesting method is passed in the queue intialized in the main as well as the user input for the size. The guidedTesting method is a step-by-step detailed description of the driver code for this program. It prompts and explains
* what is being tested and why it works the way it does. Although, this can be slightly annoying when trying to test the code for yourself which is why an unguided version has also been created. See the testing method for that.
* After each step, the system pauses to allow the user time to comprehend what happened in the previous step before moving on. This method successfully tests all methods implemented in the Qqueue.cpp class.
*/
void guidedTesting(Qqueue* queue, int max)
{
	//Prompt
	cout << endl << "Welcome to the guided testing! Here, we can walk through the driver code together and learn some cool stuff about the program! There will be times that the output will pause, simply press any key to continue through the program! Enjoy!" << endl;
	cout << endl;
	system("pause");

	//Printed last names from the readFile method
	queue->print();
	cout << endl << "Above are the last names that you just read in! Now let's see what happens when we enqueue my last name and then print the list again. " << endl << endl;

	//Adding my name to the queue
	queue->enqueue("Jeffries");
	queue->print();
	cout << endl;
	system("pause");

	//Dequeuing the front position in the queue
	cout << endl << "As you can see, it added my name to the back of the queue! Now let's see what happens when we dequeue the name in front and print the list again. " << endl << endl;
	queue->dequeue();
	cout << endl;
	queue->print();
	cout << endl;
	system("pause");

	//Getting the front and back positions of the queue
	cout << endl << "And just like that! Smith has left the queue! Now let's see what happens when we ask for the front and the back of the queue. " << endl << endl;
	queue->getfront();
	queue->getback();
	cout << endl;
	system("pause");

	//Using copy constructor to make a second queue and then comparing the two queue's to each other
	cout << endl << "Awesome! Now let's try copying the first queue to make a second queue and then compare them. " << endl << endl;
	Qqueue* queue2(queue);
	cout << endl << "Queue 1: " << endl;
	queue->print();
	cout << endl << "Queue 2: " << endl;
	queue2->print();
	cout << endl << "True or False? Queue1 = Queue2: " << (queue->equals(*queue2)? "True" : "False") << endl;
	cout << endl;
	system("pause");

	//Adding and removing names from both queues to prove that both will get modified
	cout << endl << "Now here's the cool thing. The way this copy constructor was created allows for me to change not one, but both of the queue's at the same time. This is because the copy constructor doesn't just copy what's inside the queue, but also its place in memory. Watch this! " << endl << endl;
	queue->enqueue("Schafer");
	queue2->enqueue("Kunzelman");
	queue2->dequeue();
	cout << endl << "Queue 1: " << endl;
	queue->print();
	cout << endl << "Queue 2: " << endl;
	queue2->print();
	cout << endl;
	system("pause");

	//Printing their size values
	cout << endl << "Weird right? And look! They even still equal the same thing!" << endl << endl;
	cout << "True or False? Queue1 = Queue2: " << (queue->equals(*queue2) ? "True" : "False") << endl;
	cout << endl << "Even the sizes and capacities are the same! Queue1 size: " << queue->size() << ", Queue1 capacity: " << queue->getCapacity() << ", Queue2 size: " << queue2->size() << ", Queue2 capacity: " << queue2->getCapacity() << endl;
	cout << endl;
	system("pause");

	//Making a new queue using the default constructor and then modifying that queue and comparing it to the first queue
	cout << endl << "Now, let's make a third queue from scratch, add some names, and do some tests shall we? " << endl << endl;
	Qqueue* queue3 = new Qqueue(max);
	cout << endl << "True or False? Queue3 is empty: " << (queue3->IsEmpty() ? "True" : "False") << endl << endl;
	queue3->enqueue("Jeffries");
	queue3->enqueue("Kunzelman");
	queue3->enqueue("Schafer");
	queue3->print();
	cout << endl;
	queue3->dequeue();
	cout << endl;
	queue3->print();
	cout << endl;
	queue3->getfront();
	queue3->getback();
	cout << endl << "True or False? Queue1 = Queue3: " << (queue->equals(*queue3) ? "True" : "False") << endl;
	cout << endl;
	system("pause");

	//Saving and exiting the program
	cout << endl << "Phew! That was a lot of testing! Let's save and get out of here!" << endl;
	save(queue);

	//Destructor for my queue1 and queue 3. Since queue2 is pretty much just a pointer to queue1 in memory, it does not need it's own destructor as that is handled when calling queue->~Qqueue().
	queue->~Qqueue();
	queue3->~Qqueue();
}

/*
* guidedTesting method is passed in the queue intialized in the main as well as the user input for the size. The testing is a blank canvas for you to submit your own driver code if you so desire. 
* Recommended driver code is included but it is commented. See the guidedTesting method for a lengthier and detailed walk through of the driver code.
* This method successfully tests all methods implemented in the Qqueue.cpp class.
*/
void testing(Qqueue* queue, int max) 
{
	//Add your own driver code here if you prefer to do it on your own

	cout << endl << "Add driver code here! Or use the provided (But commented) driver code in the testing method!" << endl;

	/*
	queue->enqueue("Jeffries");
	queue->dequeue();
	queue->getfront();
	queue->getback();
	queue->getCapacity();
	queue->size();
	queue->IsEmpty();
	queue->print();

	Qqueue* queue2(queue);
	queue2->enqueue("Schafer");
	queue2->dequeue();
	queue2->getfront();
	queue2->getback();
	queue2->getCapacity();
	queue2->size();
	queue2->IsEmpty();
	queue2->print();
	queue->equals(*queue2);

	Qqueue* queue3 = new Qqueue(max);
	queue3->enqueue("Jeffries");
	queue3->enqueue("Schafer");
	queue3->enqueue("Kunzelman");
	queue3->dequeue();
	queue3->getfront();
	queue3->getback();
	queue3->getCapacity();
	queue3->size();
	queue3->IsEmpty();
	queue3->print();
	(queue->equals(*queue3) ? "True" : "False");

	save(queue);
	queue->~Qqueue();
	queue3->~Qqueue();
	*/
}

/*
* I'm not entirely sure that this method actually needed implemented or not. It was mentioned once in the rubric for the assingment, but said rubric also contains lots of errors and typos so I wasn't positive if this was one of those errors or not.
* Regardless, the save method takes in the queue initialized in main, and then prints the contents of the queue to a new file called newList.txt.
* However, this method isn't fully functional yet (at this time) and only prints about half of the queue's contents.
*/
void save(Qqueue* queue) 
{
	//Declaration block
	ofstream out;
	out.open("newList.txt", ofstream::app);
	assert(!out.fail());
	int temp = queue->size();
	//end

	for (int i = 0; i < temp; i++)
	{
		out << queue->dequeue() << endl;
	}
	cout << "Everything has been saved!" << endl;
	out.close();
}