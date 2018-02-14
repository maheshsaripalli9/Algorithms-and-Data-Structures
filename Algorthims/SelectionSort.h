#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

#include "VectorSorter.h"

/**
 * The class that implements the selection sort algorithm
 * for a vector of data.
 */
class SelectionSort: public VectorSorter
{
public:
    SelectionSort(string name);
    virtual ~SelectionSort();

    virtual void run_sort_algorithm() throw (string);
};

#endif /* SELECTIONSORT_H_ */
