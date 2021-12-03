#ifndef _BST1_H_
#define _BST1_H_

#include<iostream>
#include "BSTNode.h"
#include<stack>
#include<queue>
using namespace std;
class BST1
{
private:
	BSTNode *root;

	//void printAux(BSTNode* root);
	void eraseTreeNodes(BSTNode* root);
public:
	BST1() { root = NULL; }
	~BST1() { eraseTreeNodes(root); cout << "\nDestructor called\n"; }
	bool find(int key);
	int mino();
	int maxo();
	void add(int key);
	void remove(int key);
	void print();
	void gotoxy(int, int);
};

#endif