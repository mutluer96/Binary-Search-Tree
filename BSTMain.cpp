#include "BST1.h"

void test1()
{
	try
	{
		BST1 agac;
		agac.add(9);
		agac.add(4);
		agac.add(14);
		agac.add(1);
		agac.add(6);
		agac.add(12);
		agac.add(16);
		agac.add(-1);
		agac.add(2);
		agac.add(5);
		agac.add(7);
		agac.add(11);
		agac.add(13);
		agac.add(15);
		agac.add(17);
		agac.print();
	}
	catch (std::exception &e)
	{
		cout << "\n Exception Occured: " << e.what() << endl;
	}
}

int main()
{
	test1();


	system("Pause");
	return 0;
}