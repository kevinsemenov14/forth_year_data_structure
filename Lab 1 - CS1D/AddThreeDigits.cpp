/*************************************************************************
 * NAME		  : Aaris Watts & Matthew Johnson
 * STUDENT ID : 1001043     & 222080
 * CLASS	  : CS1D
 * DUE DATE   : 01/18/17
 ************************************************************************/

/**************************************************************************
 *
 * 	FUNCTION AddThreeDigits
 * ________________________________________________________________________
 * 	This function receives an array to sum each individual element of
 * 	the array.
 * 	- returns the new elements of the array
 * 	_______________________________________________________________________
 * 	PRE-CONDITIONS
 * 			array[]    : Has to be previously defined
 *
 * 	POST-CONDITIONS
 * 			Stores new values into the array
 *************************************************************************/

#include "Header.h"

int AddThreeDigits(int numToAdd)
{
	int firstDigit;
	int secondDigit;
	int thirdDigit;

	firstDigit = numToAdd / 100;
	numToAdd %= 100;
	secondDigit = numToAdd / 10;
	thirdDigit = numToAdd % 10;

	return (firstDigit + secondDigit + thirdDigit);
}
