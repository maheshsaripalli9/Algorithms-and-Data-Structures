#include "ShellSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{

	int n = size;
	// Reference http://www.geeksforgeeks.org/shellsort/
	 // Start with a big gap, then reduce the gap
	    for (int gap = n/2; gap > 0; gap /= 2)
	    {
	        // Do a gapped insertion sort for this gap size.
	        // The first gap elements a[0..gap-1] are already in gapped order
	        // keep adding one more element until the entire array is
	        // gap sorted
	        for (int i = gap; i < n; i += 1)
	        {
	            // add a[i] to the elements that have been gap sorted
	            // save a[i] in temp and make a hole at position i
	            Element temp = data[i];

	            // shift earlier gap-sorted elements up until the correct
	            // location for a[i] is found
	            int j;
	            for (j = i; j >= gap && data[j - gap] > temp; j -= gap)
	            {
	                data[j] = data[j - gap];
	            compare_count++;
	            }
	            //  put temp (the original a[i]) in its correct location
	            data[j] = temp;
	            move_count++;

	        }
	    }

}
