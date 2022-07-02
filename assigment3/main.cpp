/*
 * main.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: ksemenov0
 */

#include "queue.h"
#include "circularArray.h"
int main()
{
	cout << "Name : Kevin semenov" << endl;
	cout << "Class: CS1D "<< endl;
	cout << "This Program will Implement the Queue interface with a class that "<< endl;
	cout <<	"is based on the LinkedDeque and DLinkedList classes and part two will "<< endl;
	cout << "will Implement the vector ADT by means of an extendable array used in a circular"<< endl;
	cout <<	"fashion, so that insertions and deletions at the beginning and end run in constant time. "<< endl;
	cout <<	"Print the circular array before and after each insertion and deletion. "<< endl;
	cout <<	"Insertions and deletion that do not at the beginning or end will run in O(n) time."<< endl<< endl;

cout << "part A using the Queue"<< endl;
	queue<string> list;


//	if(list.empty())
//	{
//		cout << " the list is empty" << endl;
//	}
//	else
//	{
//		cout << "the list is not empty" << endl;
//	}
	cout << "The size is" <<list.size();
	cout <<"Adding A man, a plan, a canal, Panama to the list\n";
	list.enqueue("A man, a plan, a canal, Panama");
	cout << endl;
	cout <<"Adding Was it a car or a cat I saw?\n";
	list.enqueue("Was it a car or a cat I saw?");
	cout << endl;
	cout <<"Adding Sit on a potato pan, Otis\n";
	list.enqueue("Sit on a potato pan, Otis");
	cout << endl;
	cout << "showing the front: ";
	list.fronts();
	cout << endl;
	//cout << "The size is" <<list.size();
	cout << endl << endl;


	cout << "Part B using a extendable array used in a circular fashion" << endl << endl;


ArrayVector<int> word(10);

cout << "The capacity of the vector: "<<word.Capacity();
cout << endl;
cout << "The size of the Vector: " <<word.size();
cout << endl;
cout << "Adding 13 to the back of the Vector";
word.addback(13);
cout << endl ;
cout <<  "showing the array ";
word.print();
cout << endl;
cout <<"The size of the Vector: " << word.size();
cout << endl;
cout << "Adding 113 to the front of the Vector";
word.addfront(113);
cout << endl;
cout <<  "showing the array ";
word.print();
cout << endl;
cout << "The size of the Vector: " << word.size();
cout << endl;
cout << "Showing the Element At 1: ";
word.at(1);
cout << endl;
cout << "inserting 3 into element 2"<< endl;
word.insert(2,3);
cout <<  "showing the array ";
word.print();
cout << endl;
cout << "Showing the Element At 2: ";
word.at(2);
cout << endl;
cout << "Removing the last element of the Vector";
word.removeback();
cout << endl;
cout << "Showing the Element At 2: ";
word.at(2);
cout << endl;
cout <<  "showing the array ";
word.print();
cout << endl;






	return 0;
}
