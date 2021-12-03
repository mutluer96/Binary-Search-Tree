#include"BST1.h"
#include<cmath>
#include<iomanip>
#include<Windows.h>
///----------------
///Erases all the nodes of tree
///

void BST1::eraseTreeNodes(BSTNode *node)
{
	/*
	if (node == NULL) return;
	eraseTreeNodes((*root).left);
	eraseTreeNodes((*root).right);
	delete root;
	root = NULL;
	*/
	if (node)
	{
		eraseTreeNodes(node->left);
		eraseTreeNodes(node->right);
		delete node;
	}
}//end-eraseTreeNodes()

///--------------------------------
///Searches a given key in bst
///

bool BST1::find(int key)
{
	BSTNode *p = root;
	while (p)
	{
		if (key == (*p).key) return true;
		if (key < (*p).key) p = p->left;
		else				p = p->right;
	}
	return false;
}
///--------------------------------
///Returns the minimum key in bst
///
int BST1::mino()
{
	if (root == NULL) throw std::exception("BST1::min - Tree is empty");

	BSTNode * p = root;
	while ((*p).left != NULL) p = p->left;
	return (*p).key;
}
///------------------------------
///Returns the maximum key in bst
///
int BST1::maxo()
{
	if (root == NULL) throw std::exception("BST1::max - Tree is empty");
	BSTNode * p = root;
	while ((*p).right != NULL) p = p->right;
	return p->key;
}
///--------------------------------
///Adds a key to the bst
///
void BST1::add(int key)
{
	BSTNode *q = NULL;
	BSTNode *p = root;
	while (p)
	{
		q = p;
		if ((*p).key == key) return;
		else if (key < (*p).key)
		{
			p = p->left;
		}
		else p = p->right;
	}
	BSTNode * node = new BSTNode(key);
	if (root == NULL) root = node;
	else if (key < (*q).key) (*q).left = node;
	else (*q).right = node;
}//end-add
///--------------------------
///Removes a given key from the bst if it exists
///

void BST1::remove(int key)
{
	BSTNode *pp = NULL;
	BSTNode *p = root;
	while (p && (*p).key != key)
	{
		pp = p;
		if (key < (*p).key) p = p->left;
		else				p = p->right;
	}
	if (p == NULL) return; //key not found

	//Case3:The node to be deleted has two children
	if (p->left && p->right)
	{
		BSTNode *qp = p;
		BSTNode *q = (*p).left;
		while (q->right)
		{
			qp = q;
			q = q->right;
		}

		p->key = q->key;
		pp = qp;
		p = q;

	}//endif

	//Special Case: Tree with a single root node
	if (p == root)
	{
		root = root->left ? root->left : root->right;
		delete p;
		return;
	}//endif

	//Case1:The node to be deleted has no children, p is a leaf
	//Case2:The node to be deleted has one children
	if (p == pp->left) pp->left = p->left ? p->left : p->right; 
	else			   pp->right = p->left ? p->left : p->right;

	delete p;
}//end remove

///------------------------
///gotoxy function
///
void BST1::gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


///-----------------------
///Print
///
void BST1::print()
{
	queue<BSTNode*> r;
	BSTNode * kok; //yeni
	kok = root; //yeni
	r.push(kok);
	int counter = 0;
	int sqrtCounter;
	int pos = 90;//90 idi
	
	while (!r.empty())
	{

		sqrtCounter = (int)sqrt((double)counter);
		BSTNode *vertex = r.front();
		if (vertex != NULL)
		{

			cout << setw(pos) << (*vertex).key;
			if (counter+1 == (pow(2, sqrtCounter+1)-1 ))
			{
				cout << "\n\n\n";
				pos = (4*pos) / 7;//4/7 güzel
				
			}
			r.pop();
			if (vertex->left != NULL)
			{
				r.push((*vertex).left);
			}
			if (vertex->right != NULL)
			{
				r.push((*vertex).right);
			}
			
		}//endif
		counter++;
	}//endwhile
	
}