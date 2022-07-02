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
	cout << " ****************************************************************"
			"**************\n"
			" * NAME       : Aaris Watts & Matthew Johnson\n"
			" * STUDENT ID : 1001043     & 222080\n"
			" * CLASS      : CS1D\n"
			" * DUE DATE   : 01/18/17\n"
			" *---------------------------------------------------------------"
			"--------------\n"
			" *  This program will generate twenty three-digit numbers. The pr"
			"ogram will\n"
			" * store, sort, and reverse the random numbers of vector. Then co"
			"py the\n"
			" * reversed vector into another vector then sum the digits of eac"
			"h number in\n"
			" * the vector and store the sums into another vector. Once that i"
			"s complete\n"
			" * the program will output each vector to the user.\n"
			" ****************************************************************"
			"**************\n\n";

	srand(time(NULL)); //Generates a seed of the time

	//Variable List
	int randomNum;
	vector <int> random;
	vector <int> summed;
	vector <int> sorted;
	vector <int> reversed;

	/*********************************************************************
	 * PROCESSING
	 * -------------------------------------------------------------------
	 * This section of code will use FOR LOOPS and functions to first
	 * store 15 two digit numbers into an array. Then go on to use these
	 * values to sort by using insertion sort, use a FOR LOOP to store the
	 * values into switchedAr[] that reversed the values, and lastly use a
	 * FOR LOOP to sum each individual value and store those values into
	 * sumAr[]
	 * -------------------------------------------------------------------
	 *********************************************************************/

	//This loop will store 15 RNG two digit numbers into an array
	for (int i = 0; i < SIZE; i++)
	{
		randomNum = (rand() % 899) + 100;
		sorted.push_back(randomNum);
	}
	cout << "Generated numbers";
	cin.get();



//	for (int i = 0; i < SIZE; i++)
//	{
		InsertionSort(sorted);
		cout << "Sorted numbers";
		cin.get();
//	}

		for (int i = 0; i < SIZE; i++)
		{
			cout << setw(3) << i+1 << ": " << sorted[i] << endl;
		}
		cout << endl;
		cout << "Output numbers";
		cin.get();

		for(int i = 0; i < SIZE; i++)
		{
			reversed.push_back(SwitchDigit(sorted[i]));
		}
		cout << "Reversed numbers";
		cin.get();

		for (int i = 0; i < SIZE; i++)
		{

			cout << setw(3) << i+1 << ": " << reversed[i] << endl;
		}
		cout << endl;
		cout << "Output numbers";
		cin.get();

		for(int i = 0; i < SIZE; i++)
		{
			summed.push_back(AddThreeDigits(sorted[i]));
		}
		cout << "Summed numbers";
		cin.get();

		for (int i = 0; i < SIZE; i++)
		{

			cout << setw(3) << i+1 << ": " << summed[i] << endl;
		}
		cout << endl;
		cout << "Output numbers";
		cin.get();




	return 0;
}
