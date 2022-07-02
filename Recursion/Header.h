/*************************************************************************
 * AUTHOR		: Emily Christiansen & Aaris Watts
 * STUDENT ID	: 1027461 & 1001043
 * LAB # 01		: Random Numbers
 * CLASS		: CS1C
 * SECTION		: MW: 2:00 pm
 * DUE DATE		: 08/22/16
 ************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;

/*-------------------------------PROTOTYPES-------------------------------
  *************************************************************************
  * PrintHeader
  * 	This function receives an assignment name, type, and number then
  * 	outputs the appropriate header.
  * 	- returns nothing -> This will output the class heading.
  ************************************************************************/
	void PrintHeader (string asName,	// IN - Assignment name
						char asType,	// IN - Assignment type
				  	  	  	  	  		//    - (LAB or ASSIGNMENT)
						int asNum);		// IN - Assignment number

  /*************************************************************************
  * InsertionSort
  * 	This function receives an array and array size for the purpose of
  * 	sorting the integer array's elements from smallest to largest.
  * 	- returns nothing -> Sorts the array
  ************************************************************************/
	void InsertionSort(vector <int> &v);

  /*************************************************************************
   * SwitchDigit
   * 	This function receives an array to switch the numbers from each
   * 	element.
   * 	- returns the new elements of the array
   ************************************************************************/
	int SwitchDigit(int numToSwitch);

  /*************************************************************************
   * AddTwoDigits
   * 	This function receives an array to sum each individual element of
   * 	the array.
   * 	- returns the new elements of the array
   ************************************************************************/
	int AddThreeDigits(int numToAdd);
//-------------------------------------------------------------------------
	const int SIZE = 20;

#endif
