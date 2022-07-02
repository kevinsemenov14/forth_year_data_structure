
#include "header.h"

/*************************************************************************
 * FUNCTION HeapSort
 * -----------------------------------------------------------------------
 * Performs a heap sort on an integer array.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	Integer array needs to be occupied with data
 *
 * POSTCONDITIONS -
 * 	Returns an ordered array
 *************************************************************************/

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i, long long &count)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        ++ count;
        heapify(arr, n, largest, count);
    }
}

void Bheapify(int arr[], int n, int i, long long &count)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        Bheapify(arr, n, largest, count);
    }
}

// main function to do heap sort
void HeapSort(int arr[], int n, long long &swapCount)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        Bheapify(arr, n, i, swapCount);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0, swapCount);
    }
}
