
#ifndef HEAP_H_
#define HEAP_H_
#include "math.h"


/*
 * heap.h
 *
 *  Created on: Feb 28, 2017
 *      Author: ksemenov0
 */


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
	void print();

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
		if(list[number] < list[number/2])
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


	if(i  <= size && left <= size && right <= size)
	{
		//If on first iteration of recursion
//		if(left <= 2 )
//		{
//
//			if(list[left] < list[i])
//			{
//				swap(list[left],list[i]);
//				bubbledown(left);
//			}
//			else
//			{
//				swap(list[right],list[i]);
//				bubbledown(right);
//			}
//		}
		//If both exist
		 if(right < size)
		{
			//Compare left against right and swap with left
			if(list[left]< list[right])
			{
				if(list[left] < list[i])
				{
				swap(list[left],list[i]);
				bubbledown(left);
				}
			}
			//Otherwise swap with right child
			else
			{
				if(list[right] < list[i])
				{
				swap(list[right],list[i]);
				bubbledown(right);
				}
			}
		}
		//If only the left exists
		else
		{
			if(list[left]< list[i])
			{
				swap(list[left],list[i]);
			}
		}
		//Check if we need to swap with left


	}
}
template <class type>
type heap<type>::top()
{

	return list[1];
}
template <class type>
void heap<type>::print()
{
	for(int i= 1; i <= size;i++)
	{
		cout << list[i] << endl;;
	}
}

#endif /* HEAP_H_ */
