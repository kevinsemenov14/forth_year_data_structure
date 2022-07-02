/*************************************************************************
 * NAME		  : Aaris Watts & Matthew Johnson
 * STUDENT ID : 1001043     & 222080
 * CLASS	  : CS1D
 * DUE DATE   : 01/18/17
 ************************************************************************/

/**************************************************************************
 *
 * 	FUNCTION SwitchDigit
 * ________________________________________________________________________
 * 	This function receives an array to switch the numbers from each
 * 	element.
 * 	- returns the new elements of the array
 * 	_______________________________________________________________________
 * 	PRE-CONDITIONS
 * 			array[]    : Has to be previously defined
 *
 * 	POST-CONDITIONS
 * 			Stores new values into array
 *************************************************************************/
#include "Header.h"

int SwitchDigit(int numToSwitch)
{
	int reverse;
	int remainder;

	reverse = 0;

	while(numToSwitch != 0)
	{
		remainder = numToSwitch%10;
		reverse = (reverse * 10) + remainder;
		numToSwitch /= 10;
	}

	return reverse;
}
