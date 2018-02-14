#include <iostream>
#include "QuickSorter.h"
using namespace std;

/**
 * Constructor.
 * @param name the name of this algorithm.
 */

void swap(Element& a, Element& b);
QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
void QuickSorter::quicksort(const int left, const int right)
{
    // reference: http://www.geeksforgeeks.org/merge-sort/
	if (left < right)
	    {
	        /* pi is partitioning index, data[p] is now
	           at right place */
		Element& pivot = choose_pivot(left, right);
	        int pi = partition( left, right, pivot);

	        quicksort(left, pi - 1);  // Before pi
	        quicksort( pi + 1, right); // After pi
	    }

}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
	// refernce: http://www.geeksforgeeks.org/merge-sort/
	Element& pi = data[right];    // pivot
	    int i = (left - 1);  // Index of smaller element

	    for (int j = left; j <= right- 1; j++)
	    {
	        // If current element is smaller than or
	        // equal to pivot
	    	compare_count++;
	        if (data[j] <= pi)
	        {
	            i++;    // increment index of smaller element
	            swap(i, j);
	        }
	    }
	    swap(i + 1, right);
	    move_count++;
	    return (i + 1);
	}


