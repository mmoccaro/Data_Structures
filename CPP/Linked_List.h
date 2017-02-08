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

//Enums
enum Type{SINGLY_LINKED_LIST, DOUBLY_LINKED_LIST};

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
			type = SINGLY_LINKED_LIST;
			dummy_head_node = false;
			circular_list = false;
		}

		//Copy Constructor
		Linked_List(const Linked_List &list)
		{
			//Set current to head node
			current = list.head;

			//Create head node
			head = new Linked_List_Node<T>;
			head->set_data(current->get_data());
			temp = head;	

			current = current->get_next();		

			//Copy the remainder of the list
			while(current != NULL)
			{		
				temp->set_next(new Linked_List_Node<T>);
				temp = temp->get_next();		 
				temp->set_data(current->get_data());
				current = current->get_next();
			}
			temp->set_next(NULL);
		}

		//Destructor
		~Linked_List()
		{
			//Iterate through the list and clean up memory
			current = head;
			while(current != NULL)
			{
				current = head->get_next();
				delete head;
				head = current;
			}
		}

		//Methods
		void add_front(T node_data)
		{
			//Set current to head temporarily
			current = head;

			//Create a new node and set its parameters
			head = new Linked_List_Node<T>;
			head->set_data(node_data);
			head->set_next(current);
			current = head;
		}

		//Add Back
		void add_back(T node_data)
		{
			current = head;
			while(current->get_next() != NULL)
			{
				current = current->get_next();
			}
			current->set_next(new Linked_List_Node<T>);
			current = current->get_next();
			current->set_data(node_data);
			current->set_next(NULL);
		}

		//Remove Front
		T remove_front()
		{
			current = head;
			head = head->get_next();

			T data = current->get_data();
			delete current;
			current = head;

			return data;
		}

		//Remove Back
		T remove_back()
		{
			current = head->get_next();
			temp = head;
			while(current->get_next() != NULL)
			{
				current = current->get_next();
				temp = temp->get_next();
			}
			T data = current->get_data();
			delete current;
			temp->set_next(NULL);
			return data;			
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

		//Node Pointers
		Linked_List_Node<T> *head;
		Linked_List_Node<T> *tail;
		Linked_List_Node<T> *current;
		Linked_List_Node<T> *temp;

		//Type
		Type type;
		bool dummy_head_node;
		bool circular_list;
};
#endif
