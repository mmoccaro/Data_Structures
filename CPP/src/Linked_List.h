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
#include<exception>
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
		//Constructors
		Linked_List()
		{
			head = tail = current = temp = NULL;
			this->type = SINGLY_LINKED_LIST;
			this->dummy_head_node = false;
			this->circular_list = false;
			this->size = 0;
		}

		//Input Type Constructor
		Linked_List(int type, bool dummy_head_node, bool circular_list)
		{
			head = tail = current = temp = NULL;
			this->type = type;
			this->dummy_head_node = dummy_head_node;
			this->circular_list = circular_list;
			this->size = 0;
		}

		//Copy Constructor
		Linked_List(const Linked_List &list)
		{
			//Set current to head node
			current = list.head;
			type = list.type;
			dummy_head_node = list.dummy_head_node;
			circular_list = list.circular_list;

			//Create head node
			try
			{
				head = new Linked_List_Node<T>;
			}
			catch(bad_alloc)
			{
				cerr << "Memory Allocation Failed." << endl;
			}

			head->set_data(current->get_data());
			temp = head;
			size = 1;	

			current = current->get_next();		

			//Copy the remainder of the list
			while(current != NULL)
			{		
				try
				{
					temp->set_next(new Linked_List_Node<T>);
				}
				catch(bad_alloc)
				{
					cerr << "Memory Allocation Failed." << endl;
				}
				temp = temp->get_next();		 
				temp->set_data(current->get_data());
				current = current->get_next();
				size++;
			}
			temp->set_next(NULL);
			tail = temp;
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
			try
			{
				head = new Linked_List_Node<T>;
			}
			catch(bad_alloc)
			{
				cerr << "Memory allocation failed." << endl;
			}

			//Set parameters of new node
			head->set_data(node_data);
			head->set_next(current);
			current = head;

			//Set Tail
			if(size == 0)
			{
				tail = current;
			}

			//Increment Size
			size++;
		}

		//Add Back
		void add_back(T node_data)
		{
			//Assign current pointer
			current = head;

			//Find the end of the list
			while(current->get_next() != NULL)
			{
				current = current->get_next();
			}

			//Allocate a new node
			try
			{
				current->set_next(new Linked_List_Node<T>);
			}
			catch(bad_alloc)
			{
				cerr << "Memory allocation failed." << endl;
			}

			//Set Parameters of new node
			current = current->get_next();
			current->set_data(node_data);
			current->set_next(NULL);
			tail = current;

			//Increment Size
			size++;
		}

		//Remove Front
		T remove_front()
		{
			current = head;
			head = head->get_next();

			T data = current->get_data();
			delete current;
			current = head;

			//Decrement Size
			size--;

			return data;
		}

		//Remove Back
		T remove_back()
		{
			//Offset current and temp pointers
			current = head->get_next();
			temp = head;

			//Iterate through to the end of the list.
			while(current->get_next() != NULL)
			{
				current = current->get_next();
				temp = temp->get_next();
			}

			//Get the data and then delete the node
			T data = current->get_data();
			delete current;

			//Set the new tail
			temp->set_next(NULL);
			tail = temp;

			//Decrement Size
			size--;

			//Return the deleted node's data
			return data;			
		}

		//Print
		void print()
		{
			//Set iterator pointer
			current = head;

			//Set the size
			cout << "Size: " << size << endl;
			
			//Iterate through list and print each node's data.
			while(current != tail->get_next())
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

		//Attributes
		int size;
};
#endif
