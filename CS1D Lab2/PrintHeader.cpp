/*****************************************************************************
 * AUTHOR		: Aaris Watts & Kathryn
 * ASSIGN # 02	: Recursion
 * CLASS		: CS1C
 * SECTION		: MW: 2:00 pm
 * DUE DATE		: 01/23/17
 *****************************************************************************/
#include "Header.h"
using std:: right;
using std:: left;
using std:: setw;

/**************************************************************************
 *
 * 	FUNCTION PrintHeader
 * ________________________________________________________________________
 * 	This function receives an assignment name, type, and number then
 * 		outputs the appropriate header -
 * 		returns nothing.
 * 	_______________________________________________________________________
 * 	PRE-CONDITIONS
 * 			asName:	Assignment name has to be previously defined
 * 			asType: Assignment type has to be previously defined
 * 			asNum:	Assignment number has to be previously defined
 *
 * 	POST-CONDITIONS
 * 			This function will output the class heading.
 *************************************************************************/

void PrintHeader (string asName,	// IN - Assignment name
				  char asType,		// IN - Assignment type
				  	  	  	  	  	//    - LAB or ASSIGNMENT)
				  int asNum)		// IN - Assignment number
{
	cout << left;
	cout << "******************************************************\n";
	cout <<	"*  PROGRAMMED BY : Aaris Watts & Kathryn Cox";
	cout << "\n*  " << setw(14) << "CLASS" << ": CS1C --> MW - 2:00pm";
	cout << "\n*  ";

	// Determines if the assignment is an assignment or a lab from input
	if(toupper (asType) == 'L')
	{
		cout << "LAB #" << setw(9);
	}
	else
	{
		cout << "ASSIGNMENT #" << setw(2);
	}
	cout << asNum << ": " << asName;
	cout << "\n******************************************************\n\n";
	cout << right;
}

