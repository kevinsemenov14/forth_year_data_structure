
#include "header.h"

/*************************************************************************
 * FUNCTION OutputSortTypeHeader
 * -----------------------------------------------------------------------
 * Outputs a small formatted line of text to act as a 'header' for the
 * charts monitoring quick sort performance.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	title : The title of chart.
 *
 * OUTPUT -
 * 	Sends to the console something that looks like this:
 * 	     title -
 * 	     Algorithm      Size (N)  Time (ns)      Swaps
 *
 *************************************************************************/

void OutputSortTypeHeader(string title)
{
    cout << left << endl << endl;
    cout << title << " -\n";
    cout << setw(COL_WIDTH + 5)   << "Algorithm"
         << setw(COL_WIDTH)       << "Size (N)"
         << setw(COL_WIDTH + 5)   << "Time (ns)"
                                  << "Swaps\n\n";
    cout << right;
}
