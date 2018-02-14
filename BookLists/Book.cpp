/***** Complete this file. *****/
#include "Book.h"
#include <string>
#include <iomanip>

using namespace std;

Book::Book()
{
}

Book::Book(string isbn, string last, string first, string title, string cat): isbn( isbn)
   ,last (last)
   ,first (first)
   ,title (title)

   {
	category = cat;
}

string Book::getIsbn() const
{
   return isbn;
}

string Book::getLast() const
{
   return last;
}

string Book::getFirst() const
{
   return first;
}

string Book::getTitle() const
{
   return title;
}


ostream& operator<<(ostream& o, Book& temp)
{
   //printing the Book list details
   o<<"Book{ISBN="<<temp.isbn<<", last="<<temp.last<<", first="<<temp.first;
   o<<", title="<<temp.title<<"}"<<endl;
   return o;
}


istream& operator >>(istream &ins, Book& book)
{

   getline (ins,book.isbn,',');
   getline (ins,book.last,',');
   getline (ins,book.first,',');
   getline (ins,book.title);
   return ins;
}


Book::~Book()
{

}
