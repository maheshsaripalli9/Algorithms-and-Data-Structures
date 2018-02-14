/*
 * Sortedvector.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: maheshsaripalli
 */


#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;


SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

int SortedVector::size() const { return data.size(); }

bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedVector::prepend(const long value)
{

	Node n(value);
	data.insert(data.begin(),n);

}

void SortedVector::append(const long value)
{

	Node n(value);
	data.push_back(n);
}

void SortedVector::remove(const int index)
{

	data.erase(data.begin()+index);
}

void SortedVector::insert(const long value)
{

	Node n(value);

	vector<Node>::const_iterator it = data.begin();
	while ((it != data.end()) && (value > it->get_value())) it++;
	data.insert(it,n);

}

Node SortedVector::at(const int index) const
{

	return data[index];
}


