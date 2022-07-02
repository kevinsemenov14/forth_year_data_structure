/*
 * circularArray.h
 *
 *  Created on: Feb 14, 2017
 *      Author: ksemenov0
 */

#ifndef CIRCULARARRAY_H_
#define CIRCULARARRAY_H_
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;



template <class Type>
class ArrayVector {

public:
	ArrayVector();
	ArrayVector(int i) ;// constructor
	int size() const;                            // number of elements
	int Capacity();                               // size of the array
	bool empty() const;                           // is vector empty?
	void erase(int i);                            // remove element at index
	void insert(int i, const Type& newElement);        // insert element at index
	void addfront( const Type& newElement);
	void addback( const Type& newElement);
	void at(int element);
	void removefront();
	void removeback();
	void removeat( int element);
	void resize();
	void print();
private:
	int capacity;              // current array size
	int n;                     // number of elements in vector
	int head;
	int tail;
	Type *list;


};


template <class Type>
ArrayVector<Type>::ArrayVector()         // constructor
{
	list = NULL;
	capacity = 10;
	n = 0;
	head = 0;
	tail = 0;
}
template <class Type>
ArrayVector<Type>::ArrayVector(int i)
{
	list = new Type[i];
	capacity = i;
	n=0;
	head = 0;
	tail = 0;
}
template <class Type>
int ArrayVector<Type>::size() const // number of elements
{
	return n;
}
template <class Type>
bool ArrayVector<Type>::empty() const // is vector empty?
{
	return n == 0;
}
template <class Type>
void ArrayVector<Type>::resize()
{
	if(n >= (capacity - 5))
	{
		Type *temp = new Type[capacity * 2];
		for(int x = 0; x < capacity;x++)
		{
			temp[x] = list[x];
		}

		delete [] list;

		list = temp;

		temp = NULL;

	}
}
template <class Type>
int ArrayVector<Type>::Capacity()
{
	return capacity;
}
template <class Type>
void ArrayVector<Type>::addback(const Type& newElement)
{
	resize();
	if(empty())
	{
		list[0]= newElement;
		n++;
		tail = n;
	}
	else
	{
		tail = n;
		list[tail+1]=newElement;
		n++;
		tail = n;
	}
}
template <class Type>
void ArrayVector<Type>::addfront(const Type& newElement)
{
	resize();
	if(empty())
	{
		tail = n;
		list[0]= newElement;
		n++;
	}
	else
	{
		tail = n;
		Type *temp = new Type[capacity];
		temp[0] = newElement;
		for(int x = 1; x <= n;x++)
		{
			temp[x] = list[x-1];
		}
		n++;
		delete [] list;

		list = temp;

		temp = NULL;

	}
}
template <class Type>
void ArrayVector<Type>::insert(int i, const Type& newElement)
{
	resize();

	if(empty())
	{
		tail = n;
		cout << "the array was empty inserted to the front";
		list[0]= newElement;
		n++;
	}
	else
	{
		tail = n;
		Type *temp = new Type[capacity];
		for(int x = 0; x < i;x++)
		{
			temp[x] = list[x];

		}
		temp[i]=newElement;
		for(int y = i+1; y <= n;y++)
		{
			temp[y] = list[y];
		}
		n++;
		delete [] list;

			list = temp;

			temp = NULL;
	}
}
template <class Type>
void ArrayVector<Type>::at(int element)
{
	resize();
	if(element < n)
	{
cout << list[element];
	}
	else
	{
		cout << "nothing at that element";
	}

}
template <class Type>
void ArrayVector<Type>::removeback()
{
	resize();
n--;
tail = n;
}
template <class Type>
void ArrayVector<Type>::removeat( int element)
{

}
template <class Type>
void ArrayVector<Type>::removefront()
{
	resize();
head = head+1;
tail = n;
}
template <class Type>
void ArrayVector<Type>::print()
{
for(int i = head; i < n;i++ ) // proving that its a circuler array printing from head to tail
{
	this->at(i); cout << " ";
}
}
#endif /* CIRCULARARRAY_H_ */
