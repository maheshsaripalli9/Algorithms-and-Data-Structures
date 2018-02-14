/*
 * SortedVector.h
 *
 *  Created on: Oct 25, 2017
 *      Author: maheshsaripalli
 */
#ifndef SORTEDVECTOR_H_
#define SORTEDVECTOR_H_

#include <vector>
#include <iterator>
#include "Node.h"

/***** Modify this file if necessary. *****/

using namespace std;

/**
 * A sorted vector of Node objects.
 */
class SortedVector
{
public:
    /**
     * Defaut constructor.
     * Reset the global Node counters.
     */
    SortedVector();

    /**
     * Destructor.
     * Reset the global Node counters.
     */
    virtual ~SortedVector();

    /**
     * @return the size of the data vector.
     */
    int size() const;

    /**
     * Check that the data is sorted.
     * @return true if sorted, false if not.
     */
    bool check() const;

    /**
     * Insert a new node at the beginning of the data vector.
     * @param value the new node's value.
     */
    void prepend(const long value);

    /**
     * Append a new node at the end of the data vector.
     * @param value the new node's value.
     */
    void append(const long value);

    /**
     * Remove a node.
     * @param index the index of the node to remove.
     */
    void remove(const int index);

    /**
     * Insert a new node into the data vector at the
     * appropriate position to keep the vector sorted.
     */
    void insert(const long value);

    /**
     * Return the data node at the indexed position.
     * @param the index of the node.
     * @return a copy of the data node.
     */
    Node at(const int index) const;

private:
    vector<Node> data;
};

#endif /* SORTEDVECTOR_H_ */

