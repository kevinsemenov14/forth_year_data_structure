
#include "header.h"
#include <ctime>
#include <chrono>

/*************************************************************************
 * FUNCTION OutputQuickSort
 * -----------------------------------------------------------------------
 * This wraps the quick sort function with information to track its
 * performance and output the result to the console. It will keep track
 * of the time taken to run, the number of swaps done in the sort, the
 * first ten elements before the sort, and the first ten elements after.
 * These are output to the console when the sort is done in a formatted
 * chart.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	low       : The lowest index of the array to sort.
 * 	high      : The highest index of the array to sort.
 * 	arr       : The array to sort.
 * 	pivotType : Whether the pivot should be the first element, the middle
 * 	            element, or a random element.
 *
 * OUTPUT -
 * 	arr             : This is returned, having been sorted.
 * 	operationsCount : Is output to the console, contains the number of
 * 	                  swaps done by the sort.
 * 	tv_nsex         : Is output to the console, contains the number of
 * 	                  nanoseconds taken by the sort.
 * 	temp            : Is output to the console, contains the first elements
 * 	                  of arr from before the sort.
 *************************************************************************/
void OutputQuickSort(int low, int high, int* arr, PivotIndex pivotType)
{
	//VARIABLE DECLERATIONS
	long long operationsCount;//OUT - Stores number of swaps.
	int       temp[10];       //OUT - Stores the first ten unsorted elements.

	//VARIABLE INITIIALIZATIONS
	operationsCount = 0;

    //Store the first ten unsorted elements of arr in temp.
    for (int i = 0; i < 5; ++i)
    {
    	temp[i] = arr[i];
    }

    //Output the size and pivot type of the array about to be sorted.
    cout << left;
	cout << setw(COL_WIDTH)
		 << high + 1
	     << setw(COL_WIDTH + 5)
	     << (pivotType == FIRST  ? "First" :
	    	 pivotType == MIDDLE ? "Middle":
	    		                   "Random");

    //Start timing, run the sort, and end timing.
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    QuickSort(low, high, arr, operationsCount, pivotType);

    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    //Output the elapsed time and the number of swaps.
    cout << setw(COL_WIDTH + 5) << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
    	 << setw(COL_WIDTH)     << operationsCount;

    //Output the first ten elements of the array before and after it
    //was sorted.
    cout << "UNSORTED: ";
    for (int i = 0; i < 5; ++i)
    {
    	cout << temp[i];
        if (i != 4)
    		cout << ", ";
    }
    cout << endl;

    cout << setw(50) << ' ' << "SORTED  : ";
    for (int i = 0; i < 5; ++i)
    {
    	cout << arr[i];
        if (i != 4)
    		cout << ", ";
    }
    cout << endl;

    cout << right;
}

