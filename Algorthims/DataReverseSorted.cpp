#include "DataReverseSorted.h"

/**
 * Default constructor.
 */
DataReverseSorted::DataReverseSorted() : DataGenerator("Reverse sorted") {}

/**
 * Destructor.
 */
DataReverseSorted:: ~DataReverseSorted() {}

/**
 * Generate reverse sorted values (high to low) to fill a data vector.
 * @param data the data vector to fill.
 */
void DataReverseSorted::generate_data(vector<Element>& data, int size)
{
    for (long i = 0; i < size; i++) data.push_back(Element(size - i));
}
