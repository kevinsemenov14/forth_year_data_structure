/******************************************************************************
 * NAME		  : Aaris Watts & Matthew Johnson
 * STUDENT ID : 1001043     & 222080
 * CLASS	  : CS1D
 * DUE DATE   : 01/18/17
 *-----------------------------------------------------------------------------
 *  This program will generate twenty three-digit numbers. The program will
 * store, sort, and reverse the random numbers of vector. Then copy the
 * reversed vector into another vector then sum the digits of each number in
 * the vector and store the sums into another vector. Once that is complete
 * the program will output each vector to the user.
 ******************************************************************************/

#include "Header.h"

int main()
{
	// Class Heading
	cout << "\nThis program will generate twenty three-digit numbers. The\n "
			"program will store, sort, and reverse the random numbers of\n "
			"vector. Then copy the reversed vector into another vector then\n "
			"sum the digits of each number in the vector and store the sums\n"
			" into another vector. Once that is complete the program will\n "
			"output each vector to the user.\n\n";

	//Variable List
	int randomNum;         //CALC & OUT - Variable that stores a RNG three
					       //			 digit number
	vector <int> summed;   //CALC & OUT - An vector that stores the RNG three
						   //             digit numbers smallest to largest
	vector <int> sorted;   //CALC & OUT - An vector that switches the RNG three
						   //             digit numbers so they are reversed
	vector <int> reversed; //CALC & OUT - An vector that sums the RNG three
	                       //             digit numbers individually

	//Generates a seed of the time
	srand(time(NULL));

	//This loop will store 15 RNG two digit numbers into an array
	for (int i = 0; i < SIZE; i++)
	{
		//Only generates three digit numbers
		randomNum = (rand() % 899) + 100;
		sorted.push_back(randomNum);
	}

	//Sorts the vector
	InsertionSort(sorted);

	cout << "Sorted Vector: \n";
	//Outputs the sorted vector
	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(3) << i+1 << ": " << sorted[i] << endl;
	}
	cout << endl;

	//Stores the sorted vector into reversed vector
	for(int i = 0; i < SIZE; i++)
	{
		reversed.push_back(SwitchDigit(sorted[i]));
	}

	cout << "Reversed Vector: \n";
	//Outputs the reversed vector
	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(3) << i+1 << ": ";
		if(reversed[i] < 100)
			cout << '0';

		if(reversed[i] < 10)
			cout << '0';

		cout << reversed[i] << endl;
	}
	cout << endl;

	//Stores the sorted vector into summed vector
	for(int i = 0; i < SIZE; i++)
	{
		summed.push_back(AddThreeDigits(sorted[i]));
	}

	cout << "Summed Vector: \n";
	//Outputs the summed vector
	for (int i = 0; i < SIZE; i++)
	{
		cout << "The sum of the digits in " << sorted[i] << " is "
			 << summed[i] << endl;
	}
	cout << endl;



	return 0;
}
