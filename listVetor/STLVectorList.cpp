/*
 * STLVectorList.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: maheshsaripalli
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <chrono>
#include "Node.h"
#include "SortedVector.h"
#include "SortedList.h"
#include "TestSuite.h"

using namespace std;
using namespace std::chrono;

/**
 * Run the test suite.
 * @throw an exception if anything goes wrong.
 */
void run_test_suite() throw (string);

/**
 * Run and time a pair of vector and linked list test functions.
 * @param test_name the name of the test pair.
 * @param fv the vector function.
 * @param fl the linked list function.
 * @throw an exception if anything goes wrong.
 */
void run_test_functions(const string test_name,
                        void fv(SortedVector& sv, const int size),
                        void fl(SortedList& sl,   const int size))
    throw (string);

/**
 * Run and time a vector test function.
 * @param sv the sorted vector test subject.
 * @param size the data size of the vector.
 * @param f the test function.
 * @return the elapsed time in milliseconds.
 * @throw an exception if anything goes wrong.
 */
long timed_test(SortedVector& sv, const int size,
                void f(SortedVector& sv, const int size)) throw (string);

/**
 * Run and time a linked list test function.
 * @param sl the sorted linked list test subject.
 * @param size the data size of the linked list.
 * @param f the test function.
 * @return the elapsed time in milliseconds.
 * @throw an exception if anything goes wrong.
 */
long timed_test(SortedList& sl, const int size,
                void f(SortedList& sl, const int size)) throw (string);

/**
 * Convert a number to a string with commas.
 * @param n the number.
 */
string commafy(const long n);


// Vector and list sizes.
const int SIZES[] = {100, 500, 1000, 5000, 10000, 50000};
// Add size 50000 outside of CodeCheck.

/**
 * The main.
 */
int main()
{
    srand(time(NULL));

    // The overall starting time.
    steady_clock::time_point start_time = steady_clock::now();

    // Run the test suite. Catch any exceptions.
    try
    {
        run_test_suite();
    }
    catch (string& msg)
    {
        cout << endl << "***** " << msg << endl;
        cout.flush();
        return -1;
    }

    // Compute and print the overall elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    duration<double> elapsed_time = duration_cast<duration<double> > (end_time - start_time);
    cout << "Done! Total time: " << elapsed_time.count() << " seconds" << endl;

    return 0;
}

void run_test_suite() throw (string)
{
    run_test_functions("Prepend", vector_prepends, list_prepends);
    run_test_functions("Append",  vector_appends,  list_appends);
    run_test_functions("Get",     vector_gets,     list_gets);
    run_test_functions("Remove",  vector_removes,  list_removes);
    run_test_functions("Insert",  vector_inserts,  list_inserts);
}

void run_test_functions(const string test_name,
                        void fv(SortedVector& sv, const int size),
                        void fl(SortedList& sl, const int size))
    throw (string)
{
    // Print a nice header for the test pair.
    for (int i = 0; i < test_name.length(); i++) cout << "=";
    cout << endl << test_name << endl;
    for (int i = 0; i < test_name.length(); i++) cout << "=";
    cout << endl;
    cout << "          |---------------Vector-------------|";
    cout <<        "   |-----------------List-------------|" << endl;
    cout << "   Size        Time  Creates   Copies Destroys";
    cout <<        "        Time  Creates   Copies Destroys" << endl;

    // Loop over the data sizes for the tests.
    for (int size : SIZES)
    {
        cout << setw(7) << commafy(size);

        // Run and time the vector test and print its statistics.
        SortedVector sv;
        long etv = timed_test(sv, size, fv);
        cout << setw(9) << commafy(etv) << " ms";
        cout << setw(9) << commafy(Node::get_constructor_count());
        cout << setw(9) << commafy(Node::get_copy_count());
        cout << setw(9) << commafy(Node::get_destructor_count());
        cout.flush();

        // Make sure the test didn't ruin the sort order.
        if (!sv.check()) throw string("Vector sort error!");

        // Run and time the linked list test and print its statistics.
        SortedList sl;
        long etl = timed_test(sl, size, fl);
        cout << setw(9) << commafy(etl) << " ms";
        cout << setw(9) << commafy(Node::get_constructor_count());
        cout << setw(9) << commafy(Node::get_copy_count());
        cout << setw(9) << commafy(Node::get_destructor_count());
        cout << endl;

        // Make sure the test didn't ruin the sort order.
        if (!sl.check()) throw string("List sort error!");
    }

    cout << endl;
}

long timed_test(SortedVector& sv, const int size,
                void f(SortedVector& sv, const int size)) throw (string)
{
    // Starting time.
    steady_clock::time_point start_time = steady_clock::now();

    // Run the test.
    f(sv, size);

    // Compute and return the elpased time in milliseconds.
    steady_clock::time_point end_time = steady_clock::now();
    return duration_cast<milliseconds>(end_time - start_time).count();
}

long timed_test(SortedList& sl, const int size,
                void f(SortedList& sl, const int size)) throw (string)
{
    // Starting time.
    steady_clock::time_point start_time = steady_clock::now();

    // Run the test.
    f(sl, size);

    // Compute and return the elpased time in milliseconds.
    steady_clock::time_point end_time = steady_clock::now();
    return duration_cast<milliseconds>(end_time - start_time).count();
}

string commafy(const long n)
{
    string str = to_string(n);
    int pos = str.length() - 3;

    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }

    return str;
}


