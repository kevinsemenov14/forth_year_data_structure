#include "skiplist.h"

int main()
{
	skiplist list;


	list.insert( 11,"tom");
	list.insert( 10,"sdf");
	list.insert( 9,"tosdfsdfm");

	list.print();
	return 0;
}
