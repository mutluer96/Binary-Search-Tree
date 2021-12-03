#include<iostream>

using namespace std;

struct BSTNode {
	int key;
	BSTNode* left, *right; //true version
	//BSTNode* left, right;
	BSTNode(int key):key(key), left(NULL),right(NULL){}
};
