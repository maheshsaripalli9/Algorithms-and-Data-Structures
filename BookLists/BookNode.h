#ifndef BOOKNODE_H_
#define BOOKNODE_H_

#include "Book.h"
#include<string>
/**
 * A book node in a linked list.
 */
class BookNode
{
public:
    /**
     * Constructor.
     * @param book this node's book.
     */
    BookNode(Book book);
    BookNode();

    BookNode *get_next() const;
    Book get_book() const;


    void set_next(BookNode *next_node);



    /***** Complete this class. *****/

public:
    Book book;       // this node's book
    BookNode *next;  // link to the next node in the list
};

#endif /* BOOKNODE_H_ */
