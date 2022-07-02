/*
 * deck.h
 *
 *  Created on: Feb 6, 2017
 *      Author: ksemenov0
 */

#ifndef DECK_H_
#define DECK_H_
# include <iostream>
#include <iomanip>
#include <string>
using namespace std;





template <class Type>
struct DNode
{
	DNode<Type>  *prev;
	DNode<Type>  *next;
	Type elem;
};

template <class Type>
class DLinkedList {				// doubly linked list
public:
	DLinkedList();				// constructor
	~DLinkedList();				// destructor
	bool empty() const;				// is list empty?
	const Type& front() const;			// get front element
	const Type& back() const;			// get back element
	void addFront(const Type& newElement);		// add to front of list
	void addBack(const Type& newElement);		// add to back of list
	void removeFront();				// remove from front
	void removeBack();				// remove from back

private:					// local type definitions



		DNode<Type>* head;				// list sentinels
		DNode<Type>* trail;

};

template <class Type>
DLinkedList<Type>::DLinkedList() {			// constructor
	head = new DNode<Type>;				// create sentinels
	trail= new DNode<Type>;
	head = NULL;			// have them point to each other
	trail = NULL;
}
template <class Type>
DLinkedList<Type>::~DLinkedList() {			// destructor
	while (!empty()) removeFront();		// remove all but sentinels
	delete head;				// remove the sentinels
	delete trail;
}
template <class Type>
bool DLinkedList<Type>::empty() const		// is list empty?
{
	return (head == NULL||trail == NULL);
}

template <class Type>
const Type& DLinkedList<Type>::front() const	// get front element
{
	if(!empty())
	{
	return head->elem;
	}
	else
	{
		cout << "The list is empty";
	}

}

template <class Type>
const Type& DLinkedList<Type>::back() const		// get back element
{
	if(!empty())
		{
	return trail->elem;
		}
	else
		{
			cout << "The list is empty";

		}
}
template <class Type>
void DLinkedList<Type>::addFront(const Type& newElement)	// add to front of list
{
	DNode<Type>* pointer = new DNode<Type>;
	pointer->elem = newElement;

	if(empty())
	{



		 head = pointer;
		 trail = pointer;
		 pointer->next = NULL;
		 pointer->prev = NULL;// makes  a new node


	}
	else
	{


pointer->next = head;
head->prev = pointer; // adds a new
head=pointer;
	}

}

template <class Type>
void DLinkedList<Type>::addBack(const Type& newElement)	// add to back of list
{
	DNode<Type>* pointer = new DNode<Type>;
	pointer->elem = newElement;
	DNode<Type>* preptr;
	if(empty())
	{



		 head = pointer;
		 trail = pointer;// makes a new node
		 pointer->next = NULL;
		 pointer->prev = NULL;


	}
	else
	{

	preptr = trail;
	preptr->next = pointer;
	pointer->prev = trail;
	trail = pointer; // adds an new node to the front
	pointer->next = NULL;
	}
}


template <class Type>
void DLinkedList<Type>::removeFront()
		{
	DNode<Type>* preptr;


	preptr = head->next;

	head->next = NULL;
	head->prev = NULL;
	head = preptr;


		}
template <class Type>
void DLinkedList<Type>::removeBack()
{
	DNode<Type>* preptr;
	preptr = trail->prev;
	trail->next = NULL;
	trail->prev = NULL;
	trail = preptr;



}



#endif /* DECK_H_ */
