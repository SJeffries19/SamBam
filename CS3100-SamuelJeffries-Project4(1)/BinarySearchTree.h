//Provided by Dr. Meilin Liu, and you can make minor modifications if you want.

#ifndef _BinarySearchTree_
#define _BinarySearchTree_

#include <cstdlib>
#include "BinaryTreeNode.h"

using namespace std;

class BinarySearchTree 
{
	public:
		BinarySearchTree();	//constructor
		~BinarySearchTree();	//destructor
		void clear(BinaryTreeNode*& root);
		BinaryTreeNode* insert(string& last, BinaryTreeNode* root);
		bool search(string& last, BinaryTreeNode* root);
		BinaryTreeNode* remove(string& last, BinaryTreeNode*& root);
		BinaryTreeNode* getPredecessor(BinaryTreeNode*& root);
		int BSTsize(BinaryTreeNode* root);
		bool save(BinaryTreeNode* root);
		bool save(BinaryTreeNode* root, ofstream& out);
		void print(BinaryTreeNode* root);
		BinaryTreeNode* getRoot() const;
	private:
		BinaryTreeNode * root;
		int size;
};


#endif
 
