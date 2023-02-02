//Course Number: CS3100
//Course Title: Data Structures and their Algorithms
//Name: Samuel Jeffries
//Prof Name: Meilin Liu
//Date: 4/16/2021
//Project Name: Project 4
//Email: jeffries.39@wright.edu

/*
* The following file is the implementation of Meilin's given BinarySearchTree.h and BinaryTreeNode.h
* All functionality is implemented correctly with no known errors.
*/

#include "BinarySearchTree.h"
#include "BinaryTreeNode.h"

//BST constructor
BinarySearchTree::BinarySearchTree() {}

//Destructor for BST
BinarySearchTree::~BinarySearchTree() { delete root; }

//Clears the BST
void BinarySearchTree::clear(BinaryTreeNode*& root)
{

	if (root == nullptr) 
	{
		return;
	}
	delete(root);
	root = nullptr;
}

//Inserts a node from the BST using inorder traversal
BinaryTreeNode* BinarySearchTree::insert(string& last, BinaryTreeNode* root) 
{

	if (root == nullptr) 
	{
		return new BinaryTreeNode(last, NULL, NULL);
	}
	if (last < root->lastname) 
	{
		root->left = insert(last, root->left);
	}
	else 
	{
		root->right = insert(last, root->right);
	}
	return root;
}

//Traverses through the BST inorder until it finds a match for the lastname and then returns true if it's been found
bool BinarySearchTree::search(string& last, BinaryTreeNode* root)
{
	if (root == NULL) 
	{
		return false;
	}
	else if (last < root->lastname) 
	{
		search(last, root->left);
	}
	else if (last > root->lastname) 
	{
		search(last, root->right);
	}
	else 
	{
		last = root->lastname;
		return true;
	}
}

//Removes a node from the BST using inorder traversal
BinaryTreeNode* BinarySearchTree::remove(string& last, BinaryTreeNode*& root)
{
	if (root == nullptr) //If blank exit
	{
		return root;
	}
	if (last < root->lastname) //If the name we're looking for is smaller go left
	{
		root->left = remove(last, root->left);
	}
	else if (last > root->lastname) //If the name we're looking for is bigger go right
	{
		root->right = remove(last, root->right);
	}
	else //If it's found
	{
		if (root->left == nullptr && root->right == nullptr) //No children
		{
			free(root);
			root = nullptr;
		}
		else if (root->left == nullptr) //Only right child
		{
			BinaryTreeNode* tempPtr = root;
			root = root->right;
			free(tempPtr);
		}
		else if (root->right == nullptr) //Only left child
		{
			BinaryTreeNode* tempPtr = root;
			root = root->left;
			free(tempPtr);
		}
		else //Both
		{
			BinaryTreeNode* tempPtr = getPredecessor(root->right);
			root->lastname = tempPtr->lastname;
			root->right = remove(tempPtr->lastname, root->right);
		}
	}
	return root;
}
//Helper method for remove
BinaryTreeNode* BinarySearchTree::getPredecessor(BinaryTreeNode*& root)
{
	BinaryTreeNode* tempPtr;
	tempPtr = root;

	while (tempPtr && tempPtr->left != nullptr)
	{
		tempPtr = tempPtr->left;
	}
	return tempPtr;
}

//Returns how many nodes are in the BST
int BinarySearchTree::BSTsize(BinaryTreeNode* root)
{
	if (root == nullptr) 
	{
		return 0;
	}
	else 
	{
		return(BSTsize(root->left) + 1 + BSTsize(root->right));
	}
	return size;
}

//Helper method for save. Declares the output stream for me
bool BinarySearchTree::save(BinaryTreeNode* root) 
{
	ofstream out;
	out.open("output.txt", ofstream::app);
	assert(!out.fail());

	return save(root, out);
	out.close();
}

//Saves the BST to output.txt using inorder traversal
bool BinarySearchTree::save(BinaryTreeNode* root, ofstream& out)
{
	if (root == nullptr)
	{
		cout << "Tree is empty!" << endl;
		return false;
	}

	if (root->left != nullptr)
	{
		save(root->left);
	}

	out << root->lastname << endl;

	if (root->right != nullptr)
	{
		save(root->right);
	}

	out.close();
	return true;
}

//Prints the BST using inorder traversal
void BinarySearchTree::print(BinaryTreeNode* root) 
{
	if (root == nullptr) 
	{
		cout << "Tree is empty!" << endl;
		return;
	}

	if (root->left != nullptr) 
	{
		print(root->left);
	}

	cout << root->lastname << endl;
	
	if (root->right != nullptr) 
	{
		print(root->right);
	}
}

//getter
BinaryTreeNode* BinarySearchTree::getRoot() const
{
	return root;
}

//BTN constructor
BinaryTreeNode::BinaryTreeNode(string& newLname, BinaryTreeNode* rightptr, BinaryTreeNode* leftptr)
{
	lastname = newLname;
	right = rightptr;
	left = leftptr;
}

//Destructor for BTN
BinaryTreeNode::~BinaryTreeNode() 
{ 
	delete left; 
	delete right; 
	left = nullptr;
	right = nullptr;
}