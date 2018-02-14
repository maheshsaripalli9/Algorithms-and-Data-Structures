#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include "Book.h"

using namespace std;
// book default constructor
Book::Book()
{

}
// book constructor
Book::Book(string Isbn, string Last, string First, string Title, Book::Category cat )
{
	isbn =Isbn;
	last = Last;
	first = First;
	title = Title;
	category = cat;
}

Book::~Book()
{

}

string Book::get_isbn()
{
	return isbn;
}
string Book::get_last()
{
	return last;
}
string Book::get_first()
{
	return first;
}
string Book::get_title()
{
	return title;
}
Book::Category Book::get_category()
{
   return category;
}


void Book::set_isbn(string i)
{
	isbn = i;
}
void Book::set_last(string lastn)
{
	last = lastn;
}
void Book::set_first(string firstn)
{
	first = firstn;
}
void Book::set_title(string t)
{
	title = t;
}
void Book::set_category(Category c)
{
   category = c;
}
istream& operator >>(istream& outs, Book& book)
{
	string isbn, last, first, title,c;
	Book::Category category;


	getline(outs, isbn, ','); // delime is ,
	book.set_isbn(isbn);

	//reading  last name
	getline(outs, last, ',');
	book.set_last(last);

	//reading  first name
	getline(outs, first, ',');
	book.set_first(first);

	// reading title of book
	getline(outs, title, ',');
	book.set_title(title);

	// reading category
	getline(outs, c);
	if(c=="fiction")
    {
    	category=Book:: FICTION;
    }
    if(c=="history")
    {
    	category=Book:: HISTORY;
    }
    if(c=="technical")
    {
    	category=Book:: TECHNICAL;
    }
    book.set_category(category);

	return outs;
}
ostream& operator <<(ostream& outs, Book& book)
{
	//printing the book details
	string book_category;

	if(book.category==0)
	{
	   book_category="fiction";
	}
	if(book.category==1)
	{
	   book_category="history";
	}
	if(book.category==2)
	{
	   book_category="technical";
	}
	string isbn_new = book.isbn.substr(1,14);
		outs<<"Book{ISBN"<<"="<<isbn_new<<", last="<<book.last<<
	      ", first="<<book.first<<", title="<<book.title<<", category="<<book_category<<"}";;
	return outs;
}
