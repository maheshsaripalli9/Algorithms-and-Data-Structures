/*
 * Element.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: maheshsaripalli
 */




#include <iostream>
#include "Element.h"

using namespace std;

long Element::copy_count=0;
long Element::constructor_count=0;
long Element::destructor_count=0;


/**
 * Default constructor.
 */
Element::Element() : value(0) {constructor_count++;}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {constructor_count++;}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other)
{
	copy_count++;
    value = other.value;
}

/**
 * Destructor.
 */
Element::~Element()
{
	destructor_count++;
    /***** Complete this class. *****/
}

/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const { return value; }

 long Element::get_copy_count()  { return copy_count;}

 long Element::get_constructor_count()  { return constructor_count;}

 long Element::get_destructor_count()  {return destructor_count;}

void Element::reset()
{
	constructor_count = 0;
	destructor_count = 0;
	copy_count = 0;

}

bool Element::operator >(const Element& other) const
{
	 return (value > other.value);
}
bool Element::operator <(const Element& other) const
{
	 return (value < other.value);
}

bool Element::operator >=(const Element& other) const
{
	 return (value >= other.value);
}

bool Element::operator <=(const Element& other) const
{
	 return (value <= other.value);
}

ostream& operator << (ostream& outs, const Element& elt)
{
	 outs << elt.get_value();
	 return outs;
}
