/*
 * Element.h
 *
 *  Created on: Nov 14, 2017
 *      Author: maheshsaripalli
 */
#ifndef DATA_H_
#define DATA_H_


#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
    Element();
    Element(long val);
    Element(const Element& other);
    virtual ~Element();

    long get_value() const;
    static long get_copy_count() ;
    static long get_constructor_count() ;
    static long get_destructor_count() ;
    static void reset();


    bool operator >(const Element& other) const;
    bool operator <(const Element& other) const;
    bool operator >=(const Element& other) const;
    bool operator <=(const Element& other) const;
    friend ostream& operator <<(ostream& outs, const Element& elt);



    static long copy_count;
    static long constructor_count;
    static long destructor_count;
private:
    long value;
};

#endif /* DATA_H_ */
