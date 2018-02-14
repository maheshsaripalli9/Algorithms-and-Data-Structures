/*
 * Node.h
 *
 *  Created on: Oct 22, 2017
 *      Author: maheshsaripalli
 */

#ifndef NODE_H_
#define NODE_H_

/***** Modify this file if necessary. *****/

/**
 * A node for the sorted vector and sorted linked list.
 */
class Node
{
public:
    /**
     * Constructor.
     * @param the_value the initial value.
     */
    Node(const long the_value);

    /**
     * Copy constructor.
     * @param other the other node object to copy.
     */
    Node(const Node& other);

    /**
     * Destructor.
     */
    virtual ~Node();

    /**
     * Getter.
     * @return the value.
     */
    long get_value() const;

    /**
     * Getter.
     * @return the value of the global constructor_count.
     */
    static long get_constructor_count();

    /**
     * Getter.
     * @return the value of the global copy_count.
     */
    static long get_copy_count();

    /**
     * Getter.
     * @return the value of the global destructor_count.
     */
    static long get_destructor_count();

    /**
     * Reset the values of the global counters.
     */
    static void reset();

    /**
     * Overloaded == operator.
     * @return true if the values of two nodes are equal, else false.
     */
    bool operator ==(const Node& other) const;

    /**
     * Overloaded > operator.
     * @return true if the value of this node is greater than
     *              the value of the other node, else false.
     */
    bool operator  >(const Node& other) const;

private:
    long value;

    // Static member variables, which are global to the class.
    // These variables exist independently from any Node objects.
    static long constructor_count;
    static long copy_count;
    static long destructor_count;
};


#endif /* NODE_H_ */

