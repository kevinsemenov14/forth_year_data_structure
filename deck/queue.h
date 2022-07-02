/*
 * queue.h
 *
 *  Created on: Feb 7, 2017
 *      Author: ksemenov0
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "deck.h"



template <class Type>
class queue : protected DLinkedList<Type>
{
public:

	queue();
	~queue();


  bool empty() const;
  void fronts();
  void enqueue(const Type& newElement);
  void dequeue();

private:

};
template <class Type>
queue<Type>::queue()
{

}
template <class Type>
queue<Type>::~queue()
{

}
template <class Type>
void queue<Type>::dequeue()
{
	this->removeFront();
}
template <class Type>
void queue<Type>::enqueue(const Type& newElement)
{
	this->addBack( newElement);
}
template <class Type>
void queue<Type>::fronts()
{
	cout << this->front();
}
template <class Type>
bool queue<Type>::empty() const
{
	return (this->head == NULL);
}



#endif /* QUEUE_H_ */
