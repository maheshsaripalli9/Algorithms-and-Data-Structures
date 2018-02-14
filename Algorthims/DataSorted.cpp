#include "DataSorted.h"

/**
 * Default constructor.
 */
DataSorted::DataSorted() : DataGenerator("Already sorted") {}

/**
 * Destructor.
 */
DataSorted:: ~DataSorted() {}

/**
 * Generate already sorted values (low to high) to fill a vector.
 * @param data the data vector to fill.
 */
void DataSorted::generate_data(vector<Element>& data, int size)
{
    for (long i = 0; i < size; i++) data.push_back(Element(i));
}
