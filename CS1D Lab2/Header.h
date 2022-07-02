/*****************************************************************************
 * AUTHOR		: Aaris Watts & Kathryn
 * ASSIGN # 02	: Recursion
 * CLASS		: CS1C
 * SECTION		: MW: 2:00 pm
 * DUE DATE		: 01/23/17
 *****************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using std:: cout;
using std:: string;


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

  /************************************************************************
  * IsPalindrome
  * 	A function that is called recursively to determine whether the
  * 	passed in string is a palindrome or not.
  * 	- returns true if it is a palindrome, and false if not.
  ************************************************************************/
	bool IsPalindrome (string possiblePalindrome);
//-------------------------------------------------------------------------



#endif /* HEADER_H_ */
