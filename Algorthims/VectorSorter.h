#ifndef VECTORSORTER_H_
#define VECTORSORTER_H_

#include <string>
#include <vector>
#include "Sorter.h"
#include "Element.h"
using namespace std;

/**
 * Abstract base class of the vector sorting subclasses.
 */
class VectorSorter: public Sorter
{
public:
    VectorSorter(string name);
    virtual ~VectorSorter();

    virtual void generate_data(DataGenerator *generator, int size);
    void clear_data();
    void print_data() const;

protected:
    vector<Element> data;  // the vector to sort

    bool is_data_sorted() const;
    void swap(const int index1, const int index2);
};

#endif /* VECTORSORTER_H_ */
