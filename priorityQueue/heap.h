/*
 * heap.h
 *
 *  Created on: Feb 28, 2017
 *      Author: ksemenov0
 */

#ifndef HEAP_H_
#define HEAP_H_
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



template <class type>
class heap
{

public:

	heap();

	int  getSize();
	void add( type stuff);
	bool isEmpty();
	void pop();
	type top();

private:
	void bubbleup(int i);
	void bubbledown(int i);
	int size;
	vector<type> list;
	type stuff;


};
template <class type>
heap<type>::heap()
{
	size = 0;
	list.push_back(stuff);
}


template <class type>
int heap<type>::getSize()
{
	return size;
}
template <class type>
bool heap<type>::isEmpty()
{
	return (size == 0);
}
template <class type>
void heap<type>::add(type stuff)
{

	if(isEmpty())
	{
		list.push_back(stuff);
		size++;
	}
	else
	{
		list.push_back(stuff);
		size++;
		bubbleup(size);
	}
}
template <class type>
void heap<type>::bubbleup(int i)
{
	int number = i;
	while (number != 1)
	{
		if(list[number] > list[number/2])
		{
			swap(list[number],list[number/2]);
		}
		number = number/ 2;
	}
}

template <class type>
void  heap<type>::pop()
{
	list[1]= list.back();
	list.pop_back();
	size--;
	bubbledown(1);
}
template <class type>
void  heap<type>::bubbledown(int i)
{
	int left =i *2;
	int right = left+1;



	if(size !=1)
	{

		if(left >= size )
		{
			if(list[left] > list[i])
			{
				swap(list[left],list[i]);
			}
		}
		else if(list[left]> list[right])
		{
			swap(list[left],list[i]);
			bubbledown(left);
		}
		else
		{
			swap(list[right],list[i]);
			bubbledown(right);
		}

	}
}
template <class type>
type heap<type>::top()
{

	return list[1];
}
#endif /* HEAP_H_ */
