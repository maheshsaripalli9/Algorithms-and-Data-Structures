#ifndef BOOK_H_
#define BOOK_H_

#include<iostream>
#include<vector>
#include <iomanip>
#include <fstream>
#include <string>
#include<cstring>
using namespace std;

class Book
{
public:

   Book();//constrctor

   Book(string isbn, string last, string first, string title, string category);

   string getIsbn() const;

    string getLast() const;

    string getFirst() const;

    string getTitle() const;

    friend ostream& operator<<(ostream& output, Book& a);

	friend istream& operator >> (istream&  input, Book& a);

	~Book();//destructor

private:

   string isbn;
   string last;
   string first;
   string title;

};

#endif /* BOOK_H_ */
