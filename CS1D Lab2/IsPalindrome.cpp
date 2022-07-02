/*****************************************************************************
 * AUTHOR		: Aaris Watts & Kathryn
 * ASSIGN # 02	: Recursion
 * CLASS		: CS1C
 * SECTION		: MW: 2:00 pm
 * DUE DATE		: 01/23/17
 *****************************************************************************/

#include "header.h"

  /************************************************************************
  * IsPalindrome
  * 	A function that is called recursively to determine whether the
  * 	passed in string is a palindrome or not.
  * 	- returns true if it is a palindrome, and false if not.
  ************************************************************************/

bool IsPalindrome(string possiblePalindrome){
	if (possiblePalindrome.length() < 2){
		return true;
	}else if( possiblePalindrome[0] !=
			  possiblePalindrome[possiblePalindrome.length()-1]){
		return false;
	}

	// Reducing the string
	possiblePalindrome = possiblePalindrome.substr(1, possiblePalindrome.length() - 2);

	// Recursive call if above statements are false.
	if(IsPalindrome(possiblePalindrome)){
		return true;
	}else{
		return false;
	}
}

