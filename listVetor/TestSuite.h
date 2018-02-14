/*
 * TestSuite.h
 *
 *  Created on: Oct 25, 2017
 *      Author: maheshsaripalli
 */

#ifndef TESTSUITE_H_
#define TESTSUITE_H_

#include "SortedVector.h"
#include "SortedList.h"

/***** Modify this file if necessary. *****/

/**
 * Test function: Insert new nodes at the beginning of the data vector.
 *                The final node data values are 0, 1, 2, ..., size-1.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 */
void vector_prepends(SortedVector& sv, const int size);

/**
 * Test function: Insert new nodes at the beginning of the data list.
 *                The final node data values are 0, 1, 2, ..., size-1.
 * @param sl the linked list test subject.
 * @param size the data size of the linked list.
 */
void list_prepends(SortedList& sl, const int size);

/**
 * Test function: Append new nodes at the end of the data vector.
 *                The final node data values are 0, 1, 2, ..., size-1.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 */
void vector_appends(SortedVector& sv, const int size);

/**
 * Test function: Append new nodes at the end of the data list.
 *                The final node data values are 0, 1, 2, ..., size-1.
 * @param sl the linked list test subject.
 * @param size the data size of the linked list.
 */
void list_appends(SortedList& sl, const int size);

/**
 * Test function: Access nodes in the data vector.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 * @throw an exception if anything goes wrong.
 */
void vector_gets(SortedVector& sv, const int size) throw (string);

/**
 * Test function: Access nodes in the data list.
 * @param sl the linked list test subject.
 * @param size the data size of the linked list.
 * @throw an exception if anything goes wrong.
 */
void list_gets(SortedList& sl, const int size) throw (string);

/**
 * Test function: Remove all the nodes from the data vector
 *                one at a time.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 */
void vector_removes(SortedVector& sv, const int size);

/**
 * Test function: Remove all the nodes from the data list
 *                one at a time.
 * @param sl the linked list test subject.
 * @param size the data size of the linked list.
 */
void list_removes(SortedList& sl, const int size);

/**
 * Test function: Insert random values into the sorted data vector.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 */
void vector_inserts(SortedVector& sv, const int size);

/**
 * Test function: Insert random values into the sorted data list.
 * @param sl the linked list test subject.
 * @param size the data size of the linked list.
 */
void list_inserts(SortedList& sl, const int size);

#endif /* TESTSUITE_H_ */

