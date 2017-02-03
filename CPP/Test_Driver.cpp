/*
#  File: Test_Driver.cpp
#  Type: C++ Source File
#  Date: January 31, 2017
#
#  Description:
#  This is the main C++ source file which tests
#  each data structure within this project.
*/

//Directives
#include<iostream>
#include "Linked_List.h"

//Namespaces
using namespace std;

//Main
int main()
{
	//Test Driver
	cout << "\nC++ Data Structures Test Driver" << endl;

	Linked_List<int> list;
	list.add_front(7);
	list.add_front(5);
	list.add_front(53);
	list.add_front(25);
	list.add_front(98);
	list.add_front(1);
	list.add_front(34);
	list.print();

	cout << "LIST 2-------------" << endl;
	Linked_List<int> list2(list);
	list2.print();
	cout << "Adding 78 to back..." << endl;
	list2.add_back(78);
	list2.print();
	cout << "Removing 78 from back..." << endl;
	int data = list2.remove_back();
	list2.print();
	cout << "Removing from front..." << endl;
	data = list2.remove_front();
	list2.print();
	

	//Exit Code
	return 0;
}
