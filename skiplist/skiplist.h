#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <math.h>
#include <vector>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */
using namespace std;

#ifndef SKIPLIST_H_
#define SKIPLIST_H_

struct node {
	string name;
	int key;
	node * up;
	node * down;
	node * left;
	node * right;
	int level;
};

class skiplist {
public:
	skiplist();
	~skiplist();
	int size();
	bool empty();
	void insert(int number, string name);
	void remove();
	node *search(int key);
	void print();

private:
	bool randomgen();

	vector<node> list;
	int highestlevel;
	node * head;
	node * bottomhead;
	node * last;
};

skiplist::skiplist() {
	srand(time(NULL));
	head = NULL;
	last = NULL;
	bottomhead = NULL;
	highestlevel = 0;
}
skiplist::~skiplist() {
	delete head;
	delete last;
}
bool skiplist::randomgen() {
	return rand() % 2;
}
void skiplist::insert(int number, string name) {
	node *newperson = new node;
	node *pointer = NULL;

	bool toss;
	newperson->name = name;
	newperson->key = number;

	if (head == NULL) {

		//		last = head;
		newperson->level = 0;
		newperson->down = NULL;
		newperson->up = NULL;
		newperson->left = NULL;
		newperson->right = NULL;
		head = newperson;
		bottomhead = head;
		toss = randomgen();
		pointer = newperson;
		if (toss) {
			while (toss) {

				node *addingnode = new node;
				addingnode->name = name;
				addingnode->key = number;
				addingnode->level = pointer->level + 1;
				addingnode->down = pointer;
				pointer->up = addingnode;
				addingnode->up = NULL;
				addingnode->left = NULL;
				addingnode->right = NULL;
				highestlevel = addingnode->level;
				head = addingnode;
				pointer = addingnode;

				toss = randomgen();
			}
		}
	} else if (newperson->key >= bottomhead->key) {
		if (bottomhead->right != NULL) {
			while (bottomhead->right != NULL && newperson->key > bottomhead->right->key)
			{
				bottomhead = bottomhead->right;
			}
		}
		newperson->left = bottomhead;
		newperson->down = NULL;
		newperson->up = NULL;
		newperson->right = NULL;
		bottomhead->right = newperson;
		bottomhead = newperson;
		pointer = newperson;

		toss = randomgen();
		if (toss) {
			node * checker;

			while (toss) {

				node *addingnode = new node; // makes a node
				addingnode->name = name;
				addingnode->key = number;   // gets info for the node
				addingnode->level = pointer->level + 1;
				addingnode->down = pointer;
				pointer->up = addingnode;

				checker = pointer;
				while(pointer->left != NULL)
				{
					pointer = pointer->left;
					if(pointer-> up != NULL)
					{
						pointer = pointer->up;
						if(pointer->level == addingnode->level)
						{
							pointer->right = addingnode;
							addingnode->left = pointer;
							break;
						}
						pointer = pointer->up;
					}
					//							pointer = pointer->left;
				}


					{
						head = addingnode;
					}
			}
		}
	} else {
		if (bottomhead->left != NULL) {
			while ( bottomhead->left != NULL && newperson->key < bottomhead->left->key) {
				bottomhead = bottomhead->left;
			}

		}

		newperson->right = bottomhead;
		newperson->up = NULL;
		newperson->down = NULL;
		newperson->left = NULL;
		bottomhead->left = newperson;

		bottomhead = newperson;
		last = bottomhead;
	}

}
node *skiplist::search(int key) {
	node * pointer;
	pointer = head;

	return pointer;

}
void skiplist::print() {

	node* printer;
	printer = last;


	while (printer->right != NULL) {
		cout << printer->name << "  ";
		printer = printer->right;
	}
	cout << printer->name << " ";
	printer = head;
	while(printer->down != NULL)
	{
		cout << printer->name << " ";
		printer = printer->down;

	}
	cout << printer->name << " ";
}
#endif /* SKIPLIST_H_ */
