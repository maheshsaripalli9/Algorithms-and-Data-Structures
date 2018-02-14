
#include "InsertionSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
	// reference http://www.geeksforgeeks.org/insertion-sort/
	Element  key;
	int i,j;
	   for (i = 1; i < size; i++)
	   {
	       key = data[i];
	       j = i-1;

	       /* Move elements of arr[0..i-1], that are
	          greater than key, to one position ahead
	          of their current position */
	       while (j >= 0 && data[j] > key)
	       {
				   compare_count++;
				   data[j+1] = data[j];
				   j--;
	       }
	       data[j+1] = key;
	       move_count++;
	   }
}
