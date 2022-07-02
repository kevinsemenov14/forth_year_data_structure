/*
 * main.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: ksemenov0
 */

#include "deck.h"
#include "stacks.h"
#include "queue.h"
#include <stack>

int main()
{

	//Tasha, JoAnn, Lucy, Mark, Cathy, Jane 48.4, 887.55, 88.88, 123.123, 8.445, 983.3, 1.2, 354.8
		stack<string> stacklist;
		stack<double>stackdouble;
		stacks<string> stackslist;
		stacks<double> stacksdouble;
		DLinkedList<string> decklist;
		DLinkedList<double> deckdouble;
		queue<string> queuelist;
		queue<double> queuedouble;



		cout << "Programmer KEVIN SEMENOV \n";
		cout << "This programe will use stacks, queue , deques and the stl stack showing the inputs and out puts\n";
		cout << "of the data and then it will show how it takes data out of the contoiners. \n";
		cout << "PART A.\n";
		cout << "INSTRUCTIONS - Implement and print the stacks using the STL \n";
		cout << "<stack> with the above data.\n";

		stacklist.push("Tasha");
		cout << "- " << stacklist.top();
		cout << endl;
		stacklist.push("JoAnn");
		cout <<"- " << stacklist.top();
		cout << endl;
		stacklist.push("Lucy");
		cout << "- " <<stacklist.top();
		cout << endl;
		stacklist.push("Mark");
		cout << "- " <<stacklist.top();
		cout << endl;
		stacklist.push("Cathy");
		cout << "- " <<stacklist.top();
		cout << endl;
		stacklist.push("Jane");
		cout <<"- " << stacklist.top();
		cout << endl;
		cout << "stack of doubles \n";
		stackdouble.push(48.4);
		cout << "- " <<stackdouble.top();
		cout << endl;
		stackdouble.push(887.55);
		cout << "- " <<stackdouble.top();
		cout << endl;
		stackdouble.push(88.88);
		cout << "- " <<stackdouble.top();
		cout << endl;
		stackdouble.push(123.123);
		cout << "- " <<stackdouble.top();
		cout << endl;
		stackdouble.push(8.445);
		cout << "- " <<stackdouble.top();
		cout << endl;
		stackdouble.push(983.3);
		cout << "- " <<stackdouble.top();
		cout << endl;
		stackdouble.push(1.2);
		cout << "- " <<stackdouble.top();
		cout << endl;
		stackdouble.push(354.8);
		cout << "- " <<stackdouble.top();
		cout << endl;

		cout << "\nPART B.\n";
		cout << "INSTRUCTIONS - Delete Cathy and 1.2 from the above stacks \n";
		cout << "(you will need to delete others) using the STL <stack> and print\n";
		cout << "the remaining elements in the stacks.\n";

		cout << "Popping the stack\n";
		stacklist.pop();
		stacklist.pop();
		cout << "remaining stack\n";
		cout << stacklist.top(); cout << " is left on top\n";
		stacklist.pop();

		stackdouble.pop();
		cout << "popping the double stack till popped 1.2\n";
		stackdouble.pop();
		cout << stackdouble.top();
		cout << " is left on the top of the stack\n";


		cout << "\nPART C.\n";
		cout << "INSTRUCTIONS - C.	Implement and print the stacks using a singly \n";
		cout << "linked list using the above data.  Do not use the STL.\n";

		stackslist.push("Tasha");
		cout << "- " ;stackslist.top();
		cout << endl;
		stackslist.push("JoAnn");
		cout <<"- ";stackslist.top();
		cout << endl;
		stackslist.push("Lucy");
		cout << "- ";stackslist.top();
		cout << endl;
		stackslist.push("Mark");
		cout << "- " ;stackslist.top();
		cout << endl;
		stackslist.push("Cathy");
		cout << "- " ;stackslist.top();
		cout << endl;
		stackslist.push("Jane");
		cout <<"- " ; stackslist.top();
		cout << endl;
		cout << "stack of doubles \n";
		stacksdouble.push(48.4);
		cout << "- ";stacksdouble.top();
		cout << endl;
		stacksdouble.push(887.55);
		cout << "- " ;stacksdouble.top();
		cout << endl;
		stacksdouble.push(88.88);
		cout << "- " ;stacksdouble.top();
		cout << endl;
		stacksdouble.push(123.123);
		cout << "- " ;stacksdouble.top();
		cout << endl;
		stacksdouble.push(8.445);
		cout << "- " ;stacksdouble.top();
		cout << endl;
		stacksdouble.push(983.3);
		cout << "- " ;stacksdouble.top();
		cout << endl;
		stacksdouble.push(1.2);
		cout << "- " ;stacksdouble.top();
		cout << endl;
		stacksdouble.push(354.8);
		cout << "- " ;stacksdouble.top();
		cout << endl;


		cout << "\n part D.	Delete Cathy and 1.2 from the above stacks \n"
				"(you will need to delete others) and print the remaining elements\n"
				"in the stacks. Do not use the STL.\n\n";
		cout << "Popping the stack\n";
		stackslist.pop();
		stackslist.pop();
		cout << "remaining stack\n";
		stackslist.top(); cout << " is left on top\n";
		stackslist.pop();

		stacksdouble.pop();
		cout << "popping the double stack till popped 1.2\n";
		stacksdouble.pop();
		stacksdouble.top();
		cout << " is left on the top of the stack\n";


		cout << "\n part E.	Implement and print the queues using either a circular \n"
				"array or a linked list using the above data.  Do not use the STL.\n";


		queuelist.enqueue("Tasha");
		queuelist.enqueue("JoAnn");
		queuelist.enqueue("Lucy");
		queuelist.enqueue("Mark");
		queuelist.enqueue("Cathy");
		queuelist.enqueue("Jane");
		cout << "- " ; queuelist.fronts();
		cout << endl;
		queuelist.dequeue();
		cout << "- " ; queuelist.fronts();
		cout << endl;
		queuelist.dequeue();
		cout << "- " ; queuelist.fronts();
		cout << endl;
		queuelist.dequeue();
		cout << "- " ; queuelist.fronts();
		cout << endl;
		queuelist.dequeue();
		cout << "- " ; queuelist.fronts();
		cout << endl;
		queuelist.dequeue();
		cout << "- " ; queuelist.fronts();
		cout << endl;
		queuelist.enqueue("Tasha");
		queuelist.enqueue("JoAnn");
		queuelist.enqueue("Lucy");
		queuelist.enqueue("Mark");
		queuelist.enqueue("Cathy");
		queuelist.enqueue("Jane");
		cout << "queue of doubles \n";
		queuedouble.enqueue(48.4);
		queuedouble.enqueue(887.55);
		queuedouble.enqueue(88.88);
		queuedouble.enqueue(123.123);
		queuedouble.enqueue(8.445);
		queuedouble.enqueue(983.3);
		queuedouble.enqueue(1.2);
		queuedouble.enqueue(354.8);
		cout << "- " ;queuedouble.fronts();
		cout << endl;
		queuedouble.dequeue();
		cout << "- " ;queuedouble.fronts();
		cout << endl;
		queuedouble.dequeue();
		cout << "- " ;queuedouble.fronts();
		cout << endl;
		queuedouble.dequeue();
		cout << "- " ;queuedouble.fronts();
		cout << endl;
		queuedouble.dequeue();
		cout << "- " ;queuedouble.fronts();
		cout << endl;
		queuedouble.dequeue();
		cout << "- " ;queuedouble.fronts();
		cout << endl;
		queuedouble.dequeue();
		cout << "- " ;queuedouble.fronts();
		cout << endl;
		queuedouble.dequeue();
		cout << "- " ;queuedouble.fronts();
		cout << endl;
		queuedouble.enqueue(48.4);
		queuedouble.enqueue(887.55);
		queuedouble.enqueue(88.88);
		queuedouble.enqueue(123.123);
		queuedouble.enqueue(8.445);
		queuedouble.enqueue(983.3);
		queuedouble.enqueue(1.2);
		queuedouble.enqueue(354.8);

		cout << "\n part F.	Cathy and 1.2 from the above queues (you will need to \n"
				"delete others)  and print the remaining elements in the queues. \n"
				"Do not use the STL.\n";
		queuelist.dequeue();
		queuelist.dequeue();
		queuelist.dequeue();
		queuelist.dequeue();
		queuelist.dequeue();
		queuelist.dequeue();
		cout << "- " ; queuelist.fronts();
		cout << endl;
		cout << "double queue.\n";
		queuedouble.dequeue();
		queuedouble.dequeue();
		queuedouble.dequeue();
		queuedouble.dequeue();
		queuedouble.dequeue();
		queuedouble.dequeue();
		queuedouble.dequeue();
		cout << "- " ;queuedouble.fronts();
		cout << endl;

		cout << "\npart G.	Implement and print the deques using a linked list using \n"
				"the above data.    Do not use the STL.\n";
		decklist.addFront("Tasha");
		cout << "- " << decklist.front();
		cout << endl;
		decklist.addFront("JoAnn");
		cout << "- " << decklist.front();
		cout << endl;
		decklist.addFront("Lucy");
		cout << "- " << decklist.front();
		cout << endl;
		decklist.addFront("Mark");
		cout << "- " << decklist.front();
		cout << endl;
		decklist.addFront("Cathy");
		cout << "- " << decklist.front();
		cout << endl;
		decklist.addFront("Jane");
		cout << "- " << decklist.front();
		cout << endl;
		cout << "deck of doubles \n";
		deckdouble.addFront(48.4);
		cout << "- " << deckdouble.front();
		cout << endl;
		deckdouble.addFront(887.55);
		cout << "- " << deckdouble.front();
		cout << endl;
		deckdouble.addFront(88.88);
		cout << "- " << deckdouble.front();
		cout << endl;
		deckdouble.addFront(123.123);
		cout << "- " << deckdouble.front();
		cout << endl;
		deckdouble.addFront(8.445);
		cout << "- " << deckdouble.front();
		cout << endl;
		deckdouble.addFront(983.3);
		cout << "- " << deckdouble.front();
		cout << endl;
		deckdouble.addFront(1.2);
		cout << "- " << deckdouble.front();
		cout << endl;
		deckdouble.addFront(354.8);
		cout << "- " << deckdouble.front();
		cout << endl;

		cout << "\n part H. Cathy and 1.2 from the above deques (you will need \n"
				"to delete others) and print the remaining elements in the deques. \n"
				"Do not use the STL.\n";
		decklist.removeFront();
		decklist.removeFront();
		cout << "- " << decklist.front();
		cout << endl;
		decklist.removeFront();
		cout << "- " << decklist.front();
		cout << endl;
		decklist.removeFront();
		cout << "- " << decklist.front();
		cout << endl;
		decklist.removeFront();
		cout << "- " << decklist.front();
		cout << endl;
		deckdouble.removeFront();
		deckdouble.removeFront();
		cout << "reaming doubles\n";
		cout << "- " << deckdouble.front();
		cout << endl;
		deckdouble.removeFront();
		cout << "- " << deckdouble.front();
		cout << endl;
		deckdouble.removeFront();
		cout << "- " << deckdouble.front();
		cout << endl;
		deckdouble.removeFront();
		cout << "- " << deckdouble.front();
		cout << endl;
		deckdouble.removeFront();
		cout << "- " << deckdouble.front();
		cout << endl;
		deckdouble.removeFront();
		cout << "- " << deckdouble.front();
		cout << endl;





//cout << "I.	Implement the Parentheses Algorithm without using the STL).  \n";
	//	cout <<"Test your algorithm with the following mathematical statements. \n ";
//	string statement = "(((6x+6) - x[9x+3])))";
//	DLinkedList<string> stringstatement;
//
//	string word;
//bool valid = true;
//	for(unsigned int x = 0; x <statement.length();x++ )
//	{
//		//cout << endl << "Loop #: " << x;
//		//cout << endl << "Current character: " << statement[x];
//
//		if(statement[x]== '[')
//		{
//
//			stringstatement.addFront("[");
//
//		}
//		if(statement[x]== '{')
//		{
//
//			stringstatement.addFront("{");
//
//		}
//		if(statement[x]== '(')
//
//		{
//
//			stringstatement.addFront("(");
//
//		}
//if( !stringstatement.empty())
//{
//		if(statement[x]== ')'&& stringstatement.front() == "(")
//		{
//			//cout << endl << "Front in remove end parentheses: " << stringstatement.front();
//			stringstatement.removeFront();
//
//		}
//
//
//		if(statement[x]== '}'&& stringstatement.front() == "{")
//		{
//			//cout << endl << "Removing end brace";
//			stringstatement.removeFront();
//
//		}
//
//
//		if(statement[x]== ']'&& stringstatement.front() == "[")
//		{
//			stringstatement.removeFront();
//
//		}
//}
//else if(statement[x]== ']'||statement[x]== ')'||statement[x]== '}')
//{
//	valid = false;
//}
//
//	}
//
//	cout << endl << statement << " is ";
//	if(valid&&stringstatement.empty())
//	{
//		cout << "a true statement";
//	}
//	else
//	{
//		cout << "a untrue statement ";
//	}

	return 0;
}


