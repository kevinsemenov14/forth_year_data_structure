/*
 * priorityqueue.h
 *
 *  Created on: Feb 28, 2017
 *      Author: ksemenov0
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_
#include <iostream>
#include <iomanip>
#include <string>
#include "heap.h"
using namespace std;

struct person
{
	string name;
	float time;
	bool operator>(const person& other)
	{
		return (time > other.time);
	}

};



 class pQueue
{




public:
	pQueue();

	bool isempty();
	void addtolist(string newname, float newtime);
	void showfront();
	void remove();

private:

	heap <person>list;

};


pQueue::pQueue()
{


}
void pQueue::addtolist(string newname, float newtime)
{
 person newperson;

newperson.time = newtime;
newperson.name = newname;

	list.add(newperson);

}
void pQueue::showfront()
{
	cout << list.top().name;

}
void pQueue::remove()
{
	list.pop();
}

#endif /* PRIORITYQUEUE_H_ */
