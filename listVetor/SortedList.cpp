/*
 * SortedList.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: maheshsaripalli
 */



#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

int SortedList::size() const { return data.size(); }

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedList::prepend(const long value)
{

	Node n1(value);
	data.push_front(n1);
}

void SortedList::append(const long value)
{

	Node n1(value);
	data.push_back(n1);
}

void SortedList::remove(const int index)
{

	list<Node>::iterator it = data.begin();

	int i=0;
	while ((it != data.end()))
	{
		if(i==index) break;
		else i++;
	}
	data.erase(it);

}

void SortedList::insert(const long value)
{


    list<Node>::iterator it = data.begin();
    Node n(value);

    while ((it != data.end()) && (it->get_value() < value  ))
    {
        it++;
    }

    data.insert(it,n);

}

Node SortedList::at(const int index)
{

	 if(index < data.size()-index)
	 {
		 int i=0;
		 list<Node>::iterator it;
	 for( it = data.begin(); it != data.end(); it++)
	 {

		if(i == index) return *it;
		i++;
	 }
	 return *it;
	 }
	 else
	 {
		 int i=data.size()-1;
		  list<Node>:: reverse_iterator rit;
		 for( rit = data.rbegin(); rit != data.rend(); rit++)
		 {

			if(i == index) return *rit;
			i--;
		 }
		 return *rit;

	 }
}

