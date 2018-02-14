/*
 * SortedList.h
 *
 *  Created on: Oct 25, 2017
 *      Author: maheshsaripalli
 */

#ifndef SORTEDLIST_H_
#define SORTEDLIST_H_

#include <list>
#include <iterator>
#include "Node.h"

/***** Modify this file if necessary. *****/

using namespace std;

/**
 * A sorted linked list of Node objects.
 */
class SortedList
{
public:
    /**
     * Defaut constructor.
     * Reset the global Node counters.
     */
    SortedList();

    /**
     * Destructor.
     * Reset the global Node counters.
     */
    virtual ~SortedList();

    /**
     * @return the size of the data list.
     */
    int size() const;

    /**
     * Check that the data is sorted.
     * @return true if sorted, false if not.
     */
    bool check();

    /**
     * Return a forward iterator pointing at the indexed position.
     * @param index the index
     * @return the iterator.
     */
    list<Node>::iterator position(const int index);

    /**
     * Insert a new node at the beginning of the data list.
     * @param value the new node's value.
     */
    void prepend(const long value);

    /**
     * Append a new node at the end of the data list.
     * @param value the new node's value.
     */
    void append(const long value);

    /**
     * Remove a node.
     * @param index the index of the node to remove.
     */
    void remove(const int index);

    /**
     * Insert a new node into the data list at the
     * appropriate position to keep the list sorted.
     */
    void insert(const long value);

    /**
     * Return the data node at the indexed position.
     * @param the index of the node.
     * @return a copy of the data node.
     */
    Node at(const int index);

private:
    list<Node> data;
};

#endif /* SORTEDLIST_H_ */

