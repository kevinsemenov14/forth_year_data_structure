/*
 * main.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: ksemenov0
 */


#include "heap.h"
struct person
{
	string value;
	int key;
	bool operator<(const person& other)
	{
		return (key < other.key);
	}

	friend ostream& operator<<(ostream& os, const person& obj)
	{
		os << obj.value << " " << obj.key;

		return os;
	}
};

int main()
{

	person student1;
	person student2;
	person student3;
	person student4;
	person student5;
	person student6;
	person student7;
	person student8;
	person student9;
	person student10;
	student1.value = "Rams";
	student1.key = 33;
	student2.value = "Vikings";
	student2.key = 22;
	student3.value = "Lions";
	student3.key = 88;
	student4.value = "Dolphins";
	student4.key = 44;
	student5.value = "Patriots";
	student5.key = 123;
	student6.value = "Bengals";
	student6.key = 44;
	student7.value = "Packers";
	student7.key = 69;
	student8.value = "Broncos";
	student8.key = 24;
	student9.value = "Bears";
	student9.key = 13;
	student10.value = "Chargers";
	student10.key = 49;

	heap <person> list;

	list.add(student1);
	list.add(student2);
	list.add(student3);
	list.add(student4);
	list.add(student5);
	list.add(student6);
	list.add(student7);
	list.add(student8);
	list.add(student9);
	list.add(student10);

	person array[10];


cout << "Kevin semenov CLASS Cs1D" << endl;
cout << "This program will Show each intermediate heap \n"
		"while adding the following nodes\n"
		"to a heap (key, value) \n \n";
cout << "All elments added to the heap \n";
cout << "the top of the heap is " << list.top().value << endl;
cout << "The heap is \n\n";
list.print();
// the first person bear
array[0].value= list.top().value;
array[0].key= list.top().key;
cout <<"\nRemoving the top of the heap\n\n";
list.pop();
list.print();
// second value goes into 1
array[1].value= list.top().value;
array[1].key= list.top().key;
cout <<"\nRemoving the top of the heap\n\n";
list.pop();
list.print();
// third value goes in
array[2].value= list.top().value;
array[2].key= list.top().key;
cout <<"\nRemoving the top of the heap\n\n";
list.pop();
list.print();
// fourth name goes into array
array[3].value= list.top().value;
array[3].key= list.top().key;
cout <<"\nRemoving the top of the heap\n\n";
list.pop();
list.print();
// fifth name goes into array
array[4].value= list.top().value;
array[4].key= list.top().key;
cout <<"\nRemoving the top of the heap\n\n";
list.pop();
list.print();
// sith name goes into array
array[5].value= list.top().value;
array[5].key= list.top().key;
cout <<"\nRemoving the top of the heap\n\n";
list.pop();
list.print();
// seventh name goes into array
array[6].value= list.top().value;
array[6].key= list.top().key;
cout <<"\nRemoving the top of the heap\n\n";
list.pop();
list.print();
// 8th name goes into array
array[7].value= list.top().value;
array[7].key= list.top().key;
cout <<"\nRemoving the top of the heap\n\n";
list.pop();
list.print();
//9th name goes into array
array[8].value= list.top().value;
array[8].key= list.top().key;
cout <<"\nRemoving the top of the heap\n\n";
list.pop();
list.print();
array[9].value= list.top().value;
array[9].key= list.top().key;
cout << "\nThe list in order \n";
cout << array[0];
cout << endl;
cout << array[1];
cout << endl;
cout << array[2];
cout << endl;
cout << array[3];
cout << endl;
cout << array[4];
cout << endl;
cout << array[5];
cout << endl;
cout << array[6];
cout << endl;
cout << array[7];
cout << endl;
cout << array[8];
cout << endl;
cout << array[9];

	return 0;
}
