#include <iostream>
#include <vector>
#include "Element.h"
#include "ListSorter.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
ListSorter::ListSorter(string name) : Sorter(name) {}

/**
 * Destructor.
 */
ListSorter::~ListSorter() {}

/**
 * Generate the data to sort. The data can be random,
 * already sorted, sorted in reverse, or all zeros.
 * @param generator the data generator.
 * @param size the number of data elements.
 */
void ListSorter::generate_data(DataGenerator *generator, int size)
{
    clear_data();

    vector<Element> v;
    generator->generate_data(v, size);

    for (int i = 0; i < size; i++) data.add(v[i]);
    set_size(size);
}

/**
 * Print the data elements.
 */
void ListSorter::print_data() const
{
    Node *ptr = data.get_head();

    while (ptr != nullptr)
    {
        cout << " " << ptr->element.get_value();
        ptr = ptr->next;
    }

    cout << endl;
}

/**
 * Verify that the data is correctly sorted.
 * @return true if correctly sorted, else false.
 */
bool ListSorter::is_data_sorted() const
{
    Node *ptr = data.get_head();

    // Chase next pointers from start to end.
    while ((ptr != nullptr) && (ptr->next != nullptr))
    {
        if (ptr->element.get_value() > ptr->next->element.get_value()) return false;  // incorrect
        ptr = ptr->next;
    }

    return true;  // correct
}

/**
 * Clear the data.
 */
void ListSorter::clear_data()
{
    if (data.get_size() > 0) data.clear();
}
