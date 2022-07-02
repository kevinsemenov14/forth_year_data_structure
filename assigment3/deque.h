/*
 * deque.h
 *
 *  Created on: Feb 9, 2017
 *      Author: ksemenov0
 */

#ifndef DEQUE_H_
#define DEQUE_H_
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
	int size();          // retrun the size of the list
private:					// local type definitions



		DNode<Type>* head;				// list sentinels
		DNode<Type>* trail;
		int count;

};

template <class Type>
DLinkedList<Type>::DLinkedList() {			// constructor
	head = new DNode<Type>;				// create sentinels
	trail= new DNode<Type>;
	head = NULL;			// have them point to each other
	trail = NULL;
	count = 0;
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
	//return (head == NULL||trail == NULL);
	if(count == 0)
		return true ;
	return false;
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
return NULL;
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
			return NULL;
		}

}
template <class Type>
void DLinkedList<Type>::addFront(const Type& newElement)	// add to front of list
{
	DNode<Type>* pointer = new DNode<Type>;
	pointer->elem = newElement;

	if(empty())
	{

count++;

		 head = pointer;
		 trail = pointer;
		 pointer->next = NULL;
		 pointer->prev = NULL;// makes  a new node

//i suck at doing my job
		 //i also suck at teamwork
	}
	else
	{

		count++;
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

		count++;

		 head = pointer;
		 trail = pointer;// makes a new node
		 pointer->next = NULL;
		 pointer->prev = NULL;


	}
	else
	{
		count++;
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

if(empty())
{
	cout << "the list is empty";
}
else
{
	preptr = head->next;

		head->next = NULL;
		head->prev = NULL;
		head = preptr;
		count--;
}


		}
template <class Type>
void DLinkedList<Type>::removeBack()
{
	if(empty())
	{
		cout << "the list is empty";
	}
	else
	{
		count--;
	DNode<Type>* preptr;
	preptr = trail->prev;
	trail->next = NULL;
	trail->prev = NULL;
	trail = preptr;

	}


}

template <class Type>
int  DLinkedList<Type>::size()
{
return count;
}

#endif /* DEQUE_H_ */
