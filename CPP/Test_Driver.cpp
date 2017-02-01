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
	list.print();
	

	//Exit Code
	return 0;
}
