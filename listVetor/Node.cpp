/*
 * Node.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: maheshsaripalli
 */



#include <iostream>
#include "Node.h"

using namespace std;

long Node:: constructor_count = 0;
long Node:: copy_count =0;
long Node:: destructor_count =0;


Node::Node(const long the_value)
{
	value = the_value;
	constructor_count++;
}
Node::Node(const Node& other)
{
	value= other.value;
	copy_count++;
}
 Node::~Node()
{
	destructor_count++;
}
 long Node::get_value() const
{
	return value;
}
long Node::get_constructor_count()
{
	return constructor_count;
}
 long Node::get_copy_count()
{
	return copy_count;
}
 long Node::get_destructor_count()
{
	return destructor_count;
}
 void Node::reset()
{
	constructor_count = 0;
	copy_count = 0;
	destructor_count =0;
}
bool Node::operator ==(const Node& other) const
{
	if(value == other.value) return true;
	else return false;
}
bool Node::operator  >(const Node& other) const
{
	if(value > other.value) return true;
	else return false;
}
