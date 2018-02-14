#ifndef BOOK_H_
#define BOOK_H_

#include <string>
using namespace std;


/**
 * The Book class.
 */
class Book
{
public:
    /**
     * Book categories.
     */
    enum  Category { FICTION, HISTORY, TECHNICAL, NONE };

    /**
     * Default constructor.
     */
    Book();

    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title, Category category);

    /**
     * Destructor.
     */
    ~Book();


     //setter functions
    /*
     * Set the isbn string
     * @param string takes the isbn
     */
    void set_isbn(string i);
    /*
     * Set the last name
     * @param str1 takes the last name string
     */
    void set_last(string lastn);
    /*
     * Set the first name
     * @param str2 takes the first name
     */
    void set_first(string firstn);
    /*
     * Set the title of book
     * @param t  takes title of book as string
     */
    void set_title(string t);
    /*
     * Set the category of book
     * @param category enum takes the category field
     */
    void set_category(Category c);

    //getter functions
    /*
     * returns the isbn string
     */
    string get_isbn();
    /*
     * returns the last name string
     */
    string get_last();
    /*
     * returns the first name string
     */
    string get_first();
    /*
     * returns the title
     */
    string get_title();
    /*
     * returns the category of book
     */
    Category get_category();
    /*
    *over ride << operator
    *@param ostream variable
    *@param book class object-1
    */
    friend ostream& operator <<(ostream& outs, Book& book);

    /*
    *over ride >> operator
    *@param ostream variable
    *@param book class object-1
    */
    friend istream& operator >>(istream& outs, Book& book);


private:


    string isbn;     // isbn of book
    string last;     // last name of author
    string first;    // first name of author
    string title;    // title of book
    Category category; // category of book

};

#endif /* EMPLOYEE_H_ */
