/*
#  File: Linked_List_Node.cpp
#  Type: C++ Header File
#  Date: January 31, 2017
#
#  Description:
#  A header file for the Linked_List_Node class.
*/

//Include Guards
#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

//Directives
#include<iostream>

//Namespaces
using namespace std;

//Template
template <class T>

//Linked_List Class
class Linked_List_Node
{
	public:
		//Constructor
		Linked_List_Node<T>()
		{
			this->data = NULL;
			this->next = NULL;
		}

		//Copy Constructor
		Linked_List_Node<T>(const Linked_List_Node<T> &node)
		{
			node->data = this->data;
		}

		//Destructor
		~Linked_List_Node<T>()
		{
			delete next;
			next = NULL;
		}

		//Initialization
		void initialize();

		//Set Data
		void set_data(T data)
		{
			this->data = data;
		}

		//Get Data
		T get_data()
		{
			return data;
		}

		//Set Next
		void set_next(Linked_List_Node<T>* next)
		{
			this->next = next;
		}

		//Get Next
		Linked_List_Node<T>* get_next()
		{
			return next;
		}
		

	private:
		T data;
		Linked_List_Node<T> *next;
};
#endif
