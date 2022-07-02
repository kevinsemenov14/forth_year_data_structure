
#include "header.h"
#include <chrono>

/*************************************************************************
 * FUNCTION OutputMergeHeap
 * -----------------------------------------------------------------------
 * This function outputs either the Merge or the Heap sort to the console
 * in a formatted way so that the data is displayed in an easy to view way
 * -----------------------------------------------------------------------
 * INPUT -
 * 	low       : The lowest index of the array to sort.
 * 	high      : The highest index of the array to sort.
 * 	arr       : The array to sort.
 * 	SortType  : Whether the sprt should be the first element or the second
 *
 * OUTPUT -
 *  A properly formatted grid of information to the console
 *************************************************************************/

void OutputMergeHeap(int low, int high, int* arr, SortType sType)
{
    if(sType == MERGE)
    {
        //VARIABLE DECLERATIONS
        long long operationsCount;//OUT - Stores number of swaps.
        int       temp[5];       //OUT - Stores the first ten unsorted elements.

        //VARIABLE INITIIALIZATIONS
        operationsCount = 0;

        //Store the first ten unsorted elements of arr in temp.
        for (int i = 0; i < 5; ++i)
        {
            temp[i] = arr[i];
        }

        cout << std::flush << left << setw(COL_WIDTH + 5)
             << (sType == MERGE  ? "Merge" : sType == HEAP ? "HEAP" :"");
        cout << setw(COL_WIDTH)
             << high + 1;



        //Start timing, run the sort, and end timing.
        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

        MergeSort(arr, low, high, operationsCount);

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
    }
    else if(sType == HEAP)
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

        cout << std::flush << left << setw(COL_WIDTH + 5)
             << (sType == MERGE  ? "Merge" : sType == HEAP ? "Heap" :"");
        cout << setw(COL_WIDTH)
             << high + 1;



        //Start timing, run the sort, and end timing.
        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

        HeapSort(arr, high, operationsCount);

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
    }
    cout << endl;

    cout << right;
}
