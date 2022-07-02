/*************************************************************************
 * NAME		  : Aaris Watts & Matthew Johnson
 * STUDENT ID : 1001043     & 222080
 * CLASS	  : CS1D
 * DUE DATE   : 01/18/17
 ************************************************************************/

/**************************************************************************
 *
 * 	FUNCTION InsertionSort
 * ________________________________________________________________________
 * 	This function receivess an array[] and its ARRAY_SIZE then
 * 		sorts the array using the insertion sort method -
 * 		returns nothing.
 * 	_______________________________________________________________________
 * 	PRE-CONDITIONS
 * 			array[]    : Has to be previously defined
 * 			ARRAY_SIZE : Has to be previously defined
 *
 * 	POST-CONDITIONS
 * 			Sorts the array
 *************************************************************************/
#include "Header.h"

void InsertionSort(vector <int> &v)
{

	int index1;    // CALC - index for the subsequent element
	int index2;    // CALC - index for the first element
	int temporary; // CALC - temporary value for an index

	//For loop that sorts the array from smallest to largerst
	for(index1 = 1; index1 < SIZE; index1++)
	{

		//Holds value for an index value
		temporary = v[index1];

		index2 = index1 - 1;

		//Sorts the array from smallest value to largest
		while(index2 >= 0 && v[index2] > temporary)
		{

			v[index2 + 1] = v[index2];
			index2 = index2 - 1;
		}

		v[index2 + 1] = temporary;
	}

}
