/*
 * main.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: ksemenov0
 */


#include "priorityqueue.h"

#include <queue>
class stlperson
{

public:
	bool operator()(const stlperson& guy, const stlperson& other)
	{
		return (guy.stltime < other.stltime);
	}

	 string stlname;
	float stltime;
};



int main()
{
pQueue list;





list.addtolist("Irene ill",6);
list.addtolist("Frank Feelingbad",7);
list.addtolist("Cathy Coughing",4);
list.addtolist("Alice Ailment",5);
list.addtolist("Paula Pain ",2);
list.addtolist("Tom Temperature ",2.5);
list.addtolist("Sam Sneezing ",1);

cout << "Programmer Kevin Semenov Class CS1D - Priorityqueue" << endl << endl;
cout << "This program will Test both priority queues with the following data assuming \n"
		"that the priority queue is built at noon and Doctor DoGood is the only doctor on duty.\n"
		"Each patient requires 20 minutes of care.  The patient who waited the longest has the\n"
		"highest priority unless there is a life threatening scenario. \n"
		"Determine the order in which the patients will be treated.  \n \n";


cout << "Assumptions \n"
	"1. When a patient's care is interrupted, they still only get 20 minutes of care total\n"
	"2. If a patient’s treatment starts at 1:00 and is not interrupted, then the next patient’s treatment will start at 1:20.\n"
	"3. Waiting time is wait time before noon \n \n";

cout << "The time is 12:00 the person being seen now is ";
list.showfront();
cout << " and is seen for 20 mins \n";
list.remove();
cout << "The time now is 12:20 ";list.showfront(); cout <<" is the next person in line and is seen until 12:22 ";
list.addtolist("Bob Bleeding", 10);
cout << "since "; list.showfront();  cout << " comes in and takes higher priority \n";
list.remove();
cout << "The time now is 12:42 and "; list.showfront(); cout << " is seen again for 18 mins until 1:00pm \n";
list.remove();
cout << "The time now is 1:00  and "; list.showfront(); cout << " is seen until 1:20\n";
list.remove();
cout << "The time now is 1:20  and "; list.showfront(); cout << " is seen until 1:40 \n";
list.remove();
cout << "The time now is 1:20  and "; list.showfront(); list.addtolist("Sid Sickly", 9); cout << " is seen until 1:45 \n"
		"becouse "; list.showfront(); cout << " comes in with a higher priority and is seen until 2:05 \n";
list.remove();
cout << "the time is now 2:05 and "; list.showfront(); cout <<" is seen again until 2:20\n \n";

cout <<"Part Two using the stl Priority queue\n \n";




priority_queue <stlperson, vector<stlperson>,  stlperson> stlList;

stlperson person1;
stlperson person2;
stlperson person3;
stlperson person4;
stlperson person5;
stlperson person6;
stlperson person7;
stlperson person8;
stlperson person9;
person1.stlname = "Irene ill";
person1.stltime = 6;

person2.stlname = "Frank Feelingbad";
person2.stltime = 7;

person3.stlname = "Cathy Coughing";
person3.stltime = 4;

person4.stlname = "Alice Ailment";
person4.stltime = 5;

person5.stlname = "Paula Pain ";
person5.stltime = 2;

person6.stlname = "Tom Temperature";
person6.stltime = 2.5;

person7.stlname = "Sam Sneezing";
person7.stltime = 1;

stlList.push(person1);
stlList.push(person2);
stlList.push(person3);
stlList.push(person4);
stlList.push(person5);
stlList.push(person6);
stlList.push(person7);





cout << "The time is 12:00 the person being seen now is ";
cout << stlList.top().stlname;
cout << " and is seen for 20 mins \n";
stlList.pop();
cout << "The time now is 12:20 ";cout << stlList.top().stlname; cout <<" is the next person in line and is seen until 12:22 ";
person8.stlname = "Bob Bleeding";
person8.stltime = 10;
stlList.push(person8);
cout << "since ";cout << stlList.top().stlname;  cout << " comes in and takes higher priority \n";
stlList.pop();
cout << "The time now is 12:42 and "; cout << stlList.top().stlname; cout << " is seen again for 18 mins until 1:00pm \n";
stlList.pop();
cout << "The time now is 1:00  and "; cout << stlList.top().stlname; cout << " is seen until 1:20\n";
stlList.pop();
cout << "The time now is 1:20  and "; cout << stlList.top().stlname; cout << " is seen until 1:40 \n";
stlList.pop();
cout << "The time now is 1:20  and ";cout << stlList.top().stlname;
person9.stlname = "Sid Sickly";
person9.stltime = 10;
stlList.push(person9);
cout << " is seen until 1:45 \n"
		"becouse ";cout << stlList.top().stlname;cout << " comes in with a higher priority and is seen until 2:05 \n";
stlList.pop();
cout << "the time is now 2:05 and "; cout << stlList.top().stlname; cout <<" is seen again until 2:20\n \n";


return 0;
}


