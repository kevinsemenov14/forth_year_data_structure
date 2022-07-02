
#include "header.h"

/*************************************************************************
 * Sorting Performance
 * -----------------------------------------------------------------------
 * This assignment's job is to test efficiency of sorting algorithms. This
 * program tests the efficiency in both number of sorts and time for each
 * sorting algorithm. Both the Quicksort section as well as the Heap/Merge
 * sort section contain explanations on why each algorithm has the
 * performance it does.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	All input is hard coded. The arrays are filled with either ordered,
 * 	reversed, or randomized integers.
 *
 * OUTPUT -
 * 	The results of the tests are output to the console in formatted
 * 	charts.
 *************************************************************************/
int main()
{
	//VARIABLE DECLERATIONS
	int arr5K [5000]; //PROC & OUT - Stores 5000  integers.
	int arr10K[10000];//PROC & OUT - Stores 10000 integers.
    int arr50K[50000];//PROC & OUT - Stores 30000 integers.
    int arr75K[75000];//PROC & OUT -Stores 75000 integers
    string array[10];//IN, PROC, & OUT - The array of strings to sort.


	/*********************************************************************
	 * OUT - Outputs the class header to the console.
	 *********************************************************************/
    cout <<"Kevin semenov cs1D asignment 15";

    cout << "This assignment's job is to test efficiency of sorting algorithms. This\n"
            "program tests the efficiency in both number of sorts and time for each\n"
            "sorting algorithm. Both the Quicksort section as well as the Heap/Merge\n"
            "sort section contain explanations on why each algorithm has the\n"
            "performance it does.\n\n";

	/*********************************************************************
     * QUICK SORT
	 *********************************************************************/
    cout << "Quick Sort:\n\n";


    /*********************************************************************
     * ORDERED ARRAYS
     *********************************************************************/
	OutputChartHeader("ORDERED");

    //5000 Elements
    ArrayFill(arr5K, 5000, ORDERED);
    OutputQuickSort(0, 4999,  arr5K,  FIRST);

    ArrayFill(arr5K, 5000, ORDERED);
    OutputQuickSort(0, 4999,  arr5K,  MIDDLE);

    ArrayFill(arr5K, 5000, ORDERED);
    OutputQuickSort(0, 4999,  arr5K,  RANDOM);

    //10000 Elements
    ArrayFill(arr10K, 10000, ORDERED);
    OutputQuickSort(0, 9999,  arr10K,  FIRST);

    ArrayFill(arr10K, 10000, ORDERED);
    OutputQuickSort(0, 9999,  arr10K,  MIDDLE);

    ArrayFill(arr10K, 10000, ORDERED);
    OutputQuickSort(0, 9999,  arr10K,  RANDOM);

    //50000 Elements
    ArrayFill(arr50K, 50000, ORDERED);
    OutputQuickSort(0, 49999,  arr50K, FIRST);

    ArrayFill(arr50K, 50000, ORDERED);
    OutputQuickSort(0, 49999,  arr50K, MIDDLE);

    ArrayFill(arr50K, 50000, ORDERED);
    OutputQuickSort(0, 49999,  arr50K, RANDOM);

	cout << endl << endl;


	/*********************************************************************
	 * REVERSE ORDERED ARRAYS
	 *********************************************************************/
	OutputChartHeader("REVERSE ORDERED");

    //5000 Elements
    ArrayFill(arr5K, 5000, REVERSED);
    OutputQuickSort(0, 4999,  arr5K,  FIRST);

    ArrayFill(arr5K, 5000, REVERSED);
    OutputQuickSort(0, 4999,  arr5K,  MIDDLE);

    ArrayFill(arr5K, 5000, REVERSED);
    OutputQuickSort(0, 4999,  arr5K,  RANDOM);

    //10000 Elements
    ArrayFill(arr10K, 10000, REVERSED);
    OutputQuickSort(0, 9999,  arr10K,  FIRST);

    ArrayFill(arr10K, 10000, REVERSED);
    OutputQuickSort(0, 9999,  arr10K,  MIDDLE);

    ArrayFill(arr10K, 10000, REVERSED);
    OutputQuickSort(0, 9999,  arr10K,  RANDOM);

    //50000 Elements
    ArrayFill(arr50K, 50000, REVERSED);
    OutputQuickSort(0, 49999,  arr50K, FIRST);

    ArrayFill(arr50K, 50000, REVERSED);
    OutputQuickSort(0, 49999,  arr50K, MIDDLE);

    ArrayFill(arr50K, 50000, REVERSED);
    OutputQuickSort(0, 49999,  arr50K, RANDOM);

	cout << endl << endl;


	/*********************************************************************
	 * RANDOMIZED ARRAYS
	 *********************************************************************/
	OutputChartHeader("RANDOM NUMBERS");

    //5000 Elements
    ArrayFill(arr5K, 5000, RANDOMIZED);
    OutputQuickSort(0, 4999,  arr5K,  FIRST);

    ArrayFill(arr5K, 5000, RANDOMIZED);
    OutputQuickSort(0, 4999,  arr5K,  MIDDLE);

    ArrayFill(arr5K, 5000, RANDOMIZED);
    OutputQuickSort(0, 4999,  arr5K,  RANDOM);

    //10000 Elements
    ArrayFill(arr10K, 10000, RANDOMIZED);
    OutputQuickSort(0, 9999,  arr10K,  FIRST);

    ArrayFill(arr10K, 10000, RANDOMIZED);
    OutputQuickSort(0, 9999,  arr10K,  MIDDLE);

    ArrayFill(arr10K, 10000, RANDOMIZED);
    OutputQuickSort(0, 9999,  arr10K,  RANDOM);

    //50000 Elements
    ArrayFill(arr50K, 50000, RANDOMIZED);
    OutputQuickSort(0, 49999,  arr50K, FIRST);

    ArrayFill(arr50K, 50000, RANDOMIZED);
    OutputQuickSort(0, 49999,  arr50K, MIDDLE);

    ArrayFill(arr50K, 50000, RANDOMIZED);
    OutputQuickSort(0, 49999,  arr50K, RANDOM);

	cout << endl;

	/*********************************************************************
	 * OUTPUT - The results are analyzed and output to the console.
	 *********************************************************************/
	cout << WordWrap("Using the left most pivot is a bad idea because if"
			         "the array was already sorted (not uncommon) then you "
			         "run in the worst case, which is O(n^2). The best case "
			         "is O(logn) which is a substantial improvement. On "
			         "average there was little difference between a random "
			         "pivot or the middle pivot, but when there was the "
			         "middle pivot came out just slightly better so I "
			         "suppose thats the strategy I would prefer.", 80);
    cout << "\n\n\n";

    /*********************************************************************
     * MERGE & HEAP SORT
     *********************************************************************/
    cout << "Merge & Heap Sorts:";

    /*********************************************************************
     * ORDERED ARRAYS
     *********************************************************************/
    OutputSortTypeHeader("ORDERED");

    //50000 Elements
    ArrayFill(arr50K, 50000, ORDERED);
    OutputMergeHeap(0, 49999, arr50K, MERGE);

    ArrayFill(arr50K, 50000, ORDERED);
    OutputMergeHeap(0, 49999, arr50K, HEAP);

    //75000 Elements
    ArrayFill(arr75K, 75000, ORDERED);
    OutputMergeHeap(0, 74999, arr75K, MERGE);

    ArrayFill(arr75K, 75000, ORDERED);
    OutputMergeHeap(0, 74999, arr75K, HEAP);

    /*********************************************************************
     * REVERSE ORDERED ARRAYS
     *********************************************************************/
    OutputSortTypeHeader("REVERSE ORDERED");

    //50000 Elements
    ArrayFill(arr50K, 50000, REVERSED);
    OutputMergeHeap(0, 49999, arr50K, MERGE);

    ArrayFill(arr50K, 50000, REVERSED);
    OutputMergeHeap(0, 49999, arr50K, HEAP);

    //75000 Elements
    ArrayFill(arr75K, 75000, REVERSED);
    OutputMergeHeap(0, 74999, arr75K, MERGE);

    ArrayFill(arr75K, 75000, REVERSED);
    OutputMergeHeap(0, 74999, arr75K, HEAP);

    /*********************************************************************
     * RANDOMIZED ARRAYS
     *********************************************************************/
    OutputSortTypeHeader("RANDOM NUMBERS");

    //50000 Elements
    ArrayFill(arr50K, 50000, RANDOMIZED);
    OutputMergeHeap(0, 49999, arr50K, MERGE);

    ArrayFill(arr50K, 50000, RANDOMIZED);
    OutputMergeHeap(0, 49999, arr50K, HEAP);

    //75000 Elements
    ArrayFill(arr75K, 75000, RANDOMIZED);
    OutputMergeHeap(0, 74999, arr75K, MERGE);

    ArrayFill(arr75K, 75000, RANDOMIZED);
    OutputMergeHeap(0, 74999, arr75K, HEAP);

    cout << endl << endl <<
         WordWrap("Both of the algorithms showed close swap amounts, but "
                  "the execution time was always in favor of the heap "
                  "sort. Although the two sorts show close swaps, the "
                  "Heap sort consistently shows better execution in terms "
                  "of the swaps that it needs to make. Both of these "
                  "algorithms are performed in O(n log(n)) time, but "
                  "the Heap still seems to show better performance.", 80);


    /*********************************************************************
     * RADIX SORT
     *********************************************************************/
    cout << "\n\n\nRadix Sort:\n\n";
    /*********************************************************************
     * INPUT - The hard coded input is entered into the array.
     *********************************************************************/
    array[0] = "acdes";
    array[1] = "asdsd";
    array[2] = "ksjtr";
    array[3] = "kerpt";
    array[4] = "absqa";
    array[5] = "zabaa";
    array[6] = "rkdsb";
    array[7] = "qqqqq ";
    array[8] = "kdfaa";
    array[9] = "zedsd";

    /*********************************************************************
     * OUT - The unsorted array is output to the console.
     *********************************************************************/
    cout << "UNSORTED - \n";
    for (int i = 0; i < 10; ++i)
    {
        cout << array[i];
        if (i != 9)
        {
            cout << ", ";
        }
    }
    cout << endl << endl;

    /*********************************************************************
     * PROC - The array is sorted.
     *********************************************************************/
    Radix(array, 10, 5);

    /*********************************************************************
     * OUT - The now sorted array is output to the console.
     *********************************************************************/
    cout << "SORTED - \n";
    for (int i = 0; i < 10; ++i)
    {
        cout << array[i];
        if(i != 9)
        {
            cout << ", ";
        }
    }

}
