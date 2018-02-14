#ifndef QUICKSORTSUBOPTIMAL_H_
#define QUICKSORTSUBOPTIMAL_H_

#include "QuickSorter.h"

/**
 * The class that implements the suboptimal quicksort algorithm
 * for a vector of data by using a bad pivot strategy.
 */
class QuickSortSuboptimal: public QuickSorter
{
public:
    QuickSortSuboptimal(string name);
    virtual ~QuickSortSuboptimal();

private:
    virtual Element& choose_pivot_strategy(const int left, const int right);
};

#endif /* QUICKSORTSUBOPTIMAL_H_ */
