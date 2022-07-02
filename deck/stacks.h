/*
 * stacks.h
 *
 *  Created on: Feb 7, 2017
 *      Author: ksemenov0
 */

#ifndef STACKS_H_
#define STACKS_H_

#include "deck.h"




template <class Type>
class stacks : protected DLinkedList<Type>
{
public:

	stacks();
	~stacks();

  void push(const Type& newElement);
  bool empty() const;
  void pop();
  void top();

private:

};
template <class Type>
stacks<Type>::stacks()
		{

		}
template <class Type>
stacks<Type>::~stacks()
		{

		}

template <class Type>
void stacks<Type>::pop()
{
	this->removeFront();

}
template <class Type>
void stacks<Type>::push(const Type& newElement)
{
	 this->addFront( newElement);
}
template <class Type>
void stacks<Type>::top()
{
	cout << this->front();
}
template <class Type>
bool stacks<Type>::empty() const		// is list empty?
{
	return (this->head == NULL);
}

#endif /* STACKS_H_ */

