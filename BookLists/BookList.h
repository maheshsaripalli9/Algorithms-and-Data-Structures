#ifndef BOOKLIST_H_
#define BOOKLIST_H_

#include<iostream>
#include<vector>
#include <iomanip>
#include <fstream>
#include <string>
#include<cstring>
using namespace std;
#include "BookNode.h"
#include "Book.h"
/**
 * A list of book nodes.
 */
class BookList
{
public:
    /**
     * Constructor.
     * @param name the name of this list.
     */
    BookList(const string name);
    BookList(const string name, vector<BookList>& categories);
    void merge(string categories);
    void copy(const BookList &other);
    void append(const Book book);




    /**
     * Print the list
     */
    void print();
    void merge(const BookList& other);

    void Insert(Book book);




private:
    string name;      // name of this book list
    BookNode *head;   // head of the list of book nodes
    BookNode *tail;   // tail of the list of book nodes

};

#endif /* BOOKLIST_H_ */
