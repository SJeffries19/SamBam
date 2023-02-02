//Provided by Dr. Meilin Liu, , and you can make minor modifications if you want.

#ifndef _BinaryTreeNode_
#define _BinaryTreeNode_
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "assert.h"
#include <algorithm>

using namespace std;

class BinaryTreeNode
{
public:
	string lastname;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
	
	BinaryTreeNode(string& newLname, BinaryTreeNode* rightptr = NULL, BinaryTreeNode* leftptr = NULL);

	~BinaryTreeNode();

};
#endif
