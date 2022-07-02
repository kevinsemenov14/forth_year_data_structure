/*
 * kevinMap.h
 *
 *  Created on: Mar 7, 2017
 *      Author: ksemenov0
 */

#ifndef KEVINMAP_H_
#define KEVINMAP_H_
#include <string>
#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
using namespace std;


struct unit
{
	int key ;
	string name;

};
class kevinmap
{

public:

	kevinmap();
	int     size();
	bool    isempty();
	void    put(int key,string name);
	void    erase(int key);
	//	void    erase(string name);
	string  find(int key);
	void    print();


private:


	vector<unit> list;



};

kevinmap::kevinmap()
{
	unit newperson;
	newperson.key = -1;
	newperson.name = " ";
	for(int i = 0; i < 31;i++)
	{
		list.push_back(newperson);
	}
}
int kevinmap::size()
{
	return list.size();
}
bool kevinmap::isempty()
{
	return list.empty();
}
void kevinmap::put(int key,string name)
{
	//h(k) = k mod 31
	//h’(k) = 17 - k mod 17

	int k= 0;
	k = key;
	int index= 0;
	unit person;
	int j= 0;

	person.key = key;
	person.name = name;

	//( (h(k) + j*h'(k)) %N )

	index = (((k % 31)+ j*(17 - k % 17))%31);

		while(list[index].key != -1&&key != list[index].key )
		{
			++j;
			index =(((k % 31)+ j*(17 - k % 17))%31);

		}

	list[index] = person;
}
string kevinmap::find(int key)
{
	int index = 0;
	int k = key;
	int j = 0;

	index = (k % 31)+ j*(17 - k % 17)%31;
	if(key != list[index].key)
	{
		while(list[index].key != -1)
		{
			j++;
			index = (k % 31)+ j*(17 - k % 17)%31;


		}
	}
	if(list[index].key != -1)
	{
		return list[index].name;
	}
	else
	{

		return "There is no one at that spot";
	}
}
void    kevinmap::erase(int key)
{
	unit person;
	person.key =-1;
	person.name = " ";
	int index = 0;
	int k = key;
	int j = 0;

	index = (k % 31)+ (j*(17 - k % 17))%31;
	if(key != list[index].key)
	{
		while(list[index].key != -1)
		{
			j++;
			index = (k % 31)+ (j*(17 - k % 17))%31;



		}
	}
	if(list[index].key != -1)
	{
		list[index] = person;
	}
	else
	{

		cout << key <<" Key does not exist\n";
	}

}

void  kevinmap::print()
{
	for(int i = 0; i < list.size();i++)
	{
		cout<<" index " <<  i << " "<< list[i].name << " " << list[i].key << endl;
	}
}
#endif /* KEVINMAP_H_ */
