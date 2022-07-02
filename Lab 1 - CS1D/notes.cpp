///*************************************************************************
// * AUTHOR		: Emily Christiansen & Aaris Watts
// * STUDENT ID	: 1027461 & 1001043
// * LAB # 01		: Random Numbers
// * CLASS		: CS1C
// * SECTION		: MW: 2:00 pm
// * DUE DATE		: 08/22/16
// ************************************************************************/
//#include"Header.h"
//
///*************************************************************************
// * Random Numbers
// * _______________________________________________________________________
// * This program will generate 15 random two digit integers, store them in
// * 		three different arrays. These arrays will sort each element,
// * 		reverse the two digits, and sum each element.
// * _______________________________________________________________________
// * 	INPUT:
// * 		No user input for this program
// *
// * 	OUTPUT:
// * 		The output for this program will be:
// *
// * 		The program will output three different integer arrays.
// *
// * 		The first array will have sorted the random numbers from smallest to
// * 		largest called sortAr[]
// *
// * 		The second array will reverse the digits of the two digit numbers
// * 		called switchedAr[]
// *
// *		The third array will split the two digit number and add up the single
// *		digits called sumAr[]
// *
// ************************************************************************/
//
//int main()
//{
//	/*********************************************************************
//	 * CONSTANTS
//	 * -------------------------------------------------------------------
//	 * USED FOR CLASS HEADING - ALL WILL BE OUTPUT
//	 * -------------------------------------------------------------------
//	 * LAB_NUM	: Assignment Number (specific to this assignment)
//	 * LAB_NAME	: Title of the assignment
//	 * LAB_TYPE	: The type of assignment
//	 * -------------------------------------------------------------------
//	 * USED FOR PROGRAM
//	 * -------------------------------------------------------------------
//	 * AR_SIZE  : The size of each array
//	 ********************************************************************/
//
//	const string LAB_NAME	 	= "Random Numbers";
//	const char 	 LAB_TYPE		= 'L';
//	const int 	 LAB_NUM		=  01;
//	const int    AR_SIZE		=  15;
//
//	/*********************************************************************
//	 * DATA TABLE
//	 * -------------------------------------------------------------------
//	 * randomNum	:	The integer that the randomly generated number
//	 * 					will be stored in
//	 * sortAr		:	The array of sorted elements
//	 * switchedAr	:	The array of elements with the digits are
//	 * 					switched
//	 * sumAr		:	The array of elements when the individual digits
//	 * 					are summed
//	 ********************************************************************/
//	srand (time(NULL)); // Generates a random seed
//
//	//Variable List
//	int randomNum;            //CALC & OUT - Variable that stores a RNG two
//							  //			 digit number
//	int sortAr[AR_SIZE];      //CALC & OUT - An array that stores the RNG two
//							  //             digit numbers smallest to largest
//	int switchedAr[AR_SIZE];  //CALC & OUT - An array that switches the RNG two
//							  //             digit numbers so they are reversed
//	int sumAr[AR_SIZE];       //CALC & OUT - An array that sums the RNG two
//							  //             digit numbers individually
//
//	/*********************************************************************
//	 * PROCESSING
//	 * -------------------------------------------------------------------
//	 * This section of code will use FOR LOOPS and functions to first
//	 * store 15 two digit numbers into an array. Then go on to use these
//	 * values to sort by using insertion sort, use a FOR LOOP to store the
//	 * values into switchedAr[] that reversed the values, and lastly use a
//	 * FOR LOOP to sum each individual value and store those values into
//	 * sumAr[]
//	 * -------------------------------------------------------------------
//	 *********************************************************************/
//
//	//This loop will store 15 RNG two digit numbers into an array
//	for (int i = 0; i < 15; i++)
//	{
//		randomNum = (rand() % 89) + 10;
//		sortAr[i] = randomNum;
//	}
//
//	//This function is used to sort the array sortAr[] by smallest to largest
//	//values
//	InsertionSort(sortAr, AR_SIZE);
//
//	//This loop will store the digits of the RNG two digit numbers reversed
//	//into the array switchedAr[]
//	for(int i = 0; i < 15; i++)
//	{
//		switchedAr[i] = SwitchDigit(sortAr[i]);
//	}
//
//	//This loop will have the items of each RNG two digit number individually
//	//summed and stored into the array sumAr[]
//	for(int i = 0; i < 15; i++)
//	{
//		sumAr[i] = AddTwoDigits(sortAr[i]);
//	}
//
//	/*********************************************************************
//	 * OUTPUT
//	 * -------------------------------------------------------------------
//	 * This section of code will output the class header and the values
//	 * for the three different arrays defined above. sortAr[], switchedAr[],
//	 * and sumAr
//	 * -------------------------------------------------------------------
//	 *********************************************************************/
//	PrintHeader(LAB_NAME, LAB_TYPE, LAB_NUM);
//
//	cout << "The sorted array is as follows: \n";
//	for(int i = 0; i < 15; i++)
//	{
//		cout << sortAr[i] << endl;
//	}
//
//	cout << "\nThe switched array is as follows: \n";
//	for(int i = 0; i < 15; i++)
//	{
//		if(switchedAr[i] < 10)
//		{
//			cout << 0;
//		}
//		cout << switchedAr[i] << endl;
//	}
//
//	cout << "\nThe summed array is as follows: \n";
//	for(int i = 0; i < 15; i++)
//	{
//		cout << sumAr[i] << endl;
//	}
//
//
//	return 0;
//}
