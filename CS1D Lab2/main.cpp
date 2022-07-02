/*****************************************************************************
 * AUTHOR		: Aaris Watts & Kathryn
 * ASSIGN # 02	: Recursion
 * CLASS		: CS1C
 * SECTION		: MW: 2:00 pm
 * DUE DATE		: 01/23/17
 *****************************************************************************/
#include "Header.h"

/*****************************************************************************
 * Lab 2: Recursion
 * ___________________________________________________________________________
 * Program that determines whether an entire string is a palindrome or not.
 * The program will remove whitespace and punctuation. It is not case
 * sensitive.
 * ___________________________________________________________________________
 * 	OUTPUT:
 * 	Whether the tested string is a palindrome or not.
 ******************************************************************************/
int main()
{
	// Constants used for header.
	const string ASSIGN_NAME	  = "Recursion";
	const char 	 ASSIGN_TYPE	  = 'L'; // Determines it as a lab.
	const int 	 ASSIGN_NUM		  =  2;

	//Outputs the class heading
	PrintHeader(ASSIGN_NAME, ASSIGN_TYPE, ASSIGN_NUM);

	//Outputs the summary of the program through a user defined namespace
	cout << "   Program that determines whether an entire string is a palindrome or not.\n"
			"   The program will remove whitespace and punctuation. It is not case\n"
			"   sensitive.\n\n";

	string palindromeAr[10] = {"radar", "CS1D", "Racecar", "Saddleback", "dad",
							   "mom", " A man a plan a canal Panama",
							   "The rain in Spain", "No lemon, no melon",
							   "Was it a cat I saw?"};

	string palindrome; // String to check if it is a palindrome or not.

	for(int i = 0; i < 10; i++){

		palindrome = palindromeAr[i];

		cout << "   String to test: " << palindrome << std::endl;

		// Removes any spaces in the string.
		palindrome.erase(std::remove(palindrome.begin(),palindrome.end(), ' '),
				         palindrome.end());
		// Removes any punctuation in the string.
		palindrome.erase(std::remove_if(palindrome.begin(),palindrome.end(),
				 	     ispunct), palindrome.end());

		// Makes the string all lowercase.
		for(int j = 0; j < palindrome.length(); j++ ){
			palindrome[j] = tolower(palindrome[j]);
		}

		// Outputs whether it is a palindrome or not.
		if(IsPalindrome(palindrome)){
			cout << "   The string : \"" << palindromeAr[i] << "\" is a Palindrome! :>\n";
		}else {
			cout << "   The string : \"" << palindromeAr[i] << "\" is not a Palindrome! :<\n";
		}

		cout << std::endl; // Flush output buffer.
	}

	return 0;
}

