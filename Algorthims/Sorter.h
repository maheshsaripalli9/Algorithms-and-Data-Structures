#ifndef SORTER_H_
#define SORTER_H_

#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include "DataGenerator.h"

using namespace std;
using namespace std::chrono;

/**
 * The abstract base class of the sorting algorithms.
 */
class Sorter
{
public:
    Sorter(string name);
    virtual ~Sorter();

    // Name of the sorting algorithm.
    string get_name() const;

    // Size (number of data elements) to sort.
    int get_size() const;
    void set_size(int sz);

    // Get the number of data element moves and compares
    // during a sort, and the elapsed time in milliseconds.
    long get_move_count() const;
    long get_compare_count() const;
    long get_elapsed_ms() const;

    long get_constructor_count() const;
    long get_copy_count() const;
    long get_destructor_count() const;

    // Abstract functions to generate the data to sort.
    virtual void generate_data(DataGenerator* generator, int size) = 0;

    // Sort the data. Not abstract!
    virtual bool sort() throw (string);

    virtual void clear_data() = 0;
    virtual void print_data() const = 0;  // useful for debugging

protected:
    int size;            // number of data elements to sort
    long move_count;     // count of data element moves during a sort
    long compare_count;  // count of data element compares during a sort

    // Abstract functions to run a sort algorithm
    // and to verify a correct sort.
    virtual void run_sort_algorithm() throw (string) = 0;
    virtual bool is_data_sorted() const = 0;

private:
    string name;

    steady_clock::time_point timer;
    long elapsed_time;

    void start_timer();
    void stop_timer();
};

#endif /* SORTER_H_ */
