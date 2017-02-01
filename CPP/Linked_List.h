/*
#  File: Linked_List.h
#  Type: C++ Header File
#  Date: January 31, 2017
#
#  Description:
#  A header file for the Linked_List class.
*/

//Include Guards
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//Directives
#include<iostream>
#include "Linked_List_Node.h"

//Namespaces
using namespace std;

//Template Class
template <class T>

//Linked_List Class
class Linked_List
{
	public:
		//Constructor
		Linked_List()
		{
			head = tail = current = NULL;
		}

		//Copy Constructor
		Linked_List(const Linked_List &list)
		{
		}

		//Destructor
		~Linked_List()
		{
		}

		//Initialization
		void initialize()
		{
		}

		//Methods
		void add_front(T node_data)
		{
			current = head;
			head = new Linked_List_Node<T>;
			head->set_data(node_data);
			head->set_next(current);
		}

		//Add Back
		void add_back(Linked_List_Node<T> node)
		{
		}

		//Remove Front
		Linked_List_Node<T> remove_front()
		{
			return NULL;
		}

		//Remove Back
		Linked_List_Node<T> remove_back()
		{
			return NULL;
		}

		//Print
		void print()
		{
			current = head;
			while(current != NULL)
			{
				cout << current->get_data() << endl;
				current = current->get_next();
			}
		}

	private:
		Linked_List_Node<T> *head;
		Linked_List_Node<T> *tail;
		Linked_List_Node<T> *current;
};
#endif
