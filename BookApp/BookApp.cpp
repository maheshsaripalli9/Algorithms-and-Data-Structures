#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>
#include "Book.h"


using namespace std;
/*
 * Binary search
 * @param isbn is a string of book
 * @param vector catalog
 * returns index of vector catalog
 */
int find(const string isbn, const vector<Book>& catalog);

/*
 * Execute is to read command and exute the following code
 * @param command is a character of book
 * @param istream input
 * @param vector catalog
 */
void execute(char command, istream& input, vector<Book>& catalog);

/*
 * insert function is to insert book data ('-')
 * @param istream input
 * @param vector catalog
 * @param Book class
 */
void insert(istream& input,  vector<Book>& catalog , Book& book );

/*
 * erase is to delete book data ('-')
 * @param istream input
 * @param vector catalog
 */
void erase(istream& input,  vector<Book>& catalog);

/*
 * @search is to search book data based on required field
 * @param istream input
 * @param vector catalog
 */
void search(istream& input,  vector<Book>& catalog);

// Status codes.
enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};

/**
 * Find the book in the catalog with the given ISBN.
 * Use a binary search.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
const string INPUT_FILE_NAME = "commands.in";


int main()
{
	// Open the input file.
	ifstream input;
	input.open(INPUT_FILE_NAME);
	if (input.fail())
	{
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
	}

	vector<Book> catalog;  // book catalog

	char command;
	input >> command;  // read the first command

	/**
	 * Loop to read commands until the end of file.
	 */
	while (!input.fail())
	{

		execute(command, input, catalog);
		input >> command;

	}

	return 0;
}

void execute(char command, istream& input, vector<Book>& catalog)
{
	Book b;
	string s;

	if (command == '+') // insertion command
	{
		cout<< endl << command<<" ";
		insert( input, catalog, b);
	}
	else if(command == '-') // erase command
	{
		erase(input,catalog);
	}

	else if(command == '?') //search comand
	{
		cout << endl << command << " ";
		search(input, catalog);
	}
	else
	{
		input >> s;
		cout << endl;
		cout<<"$ *** Invalid command ***"<<endl;
	 }
}

// Binary search
int find(const string isbn, const vector<Book>& catalog)
{
	string::size_type sz;

	long int search_isbn = stol(isbn, &sz);
	int high=catalog.size();
	int low=0;
	int mid;
	Book b;

	while (low <= high)
	{
	   mid= (low + high)/2;
	   b=catalog[mid];
		string isbn_n = b.get_isbn();
		string sub = isbn_n.substr(5,isbn_n.length());

		long int book_isbn = stol(sub, &sz);

		if (book_isbn == search_isbn) return mid;

		else if(book_isbn > search_isbn)	    high = mid-1;

		else low = mid+1;

	}
	return -1;
}


void insert(istream& input,  vector<Book>& catalog, Book& book )
{


	input >> book;   //reading all details
	bool flag=true;


	//if the vector is empty, push back the first book object
	if(catalog.size() == 0)
	{
		catalog.push_back(book);
		cout <<"Inserted at index "<<"0"<<": ";
		cout << book <<endl;
	}

	//if vector is not empty
	else
	{
		//iterate through catalog and find if id is already present
		for(int i=0; i<catalog.size(); i++)
		{
			if(catalog[i].get_isbn() == book.get_isbn())
			{
				cout<<"Inserted at index "<< i <<": " ;
				cout << book << endl;
				cout<<"*** Duplicate ISDN ***"<<endl;
				flag = false;
			}
		}
		//if id is not present insert it at right position
		if(flag)
		{
			int i=0;
			while(book.get_isbn() > catalog[i].get_isbn())
			{
				i++;
				if(i == catalog.size())
					break;
			}

			catalog.insert(catalog.begin() + i, book);
			cout<<"Inserted at index "<<i<<": ";
			cout << book << endl;
		}
	}

}

void erase(istream& input,  vector<Book>& catalog)
{

	string str,temp;

	getline(input, str);
	int str_len = str.length();

	bool found=false;
	int value;
	for(int i=0; i<catalog.size(); i++)
	{
		if(catalog[i].get_isbn() == str)
		{
		value = i;
		found=true;
		}
	}
	if(found)
	{
		cout<<endl;
		cout <<"- Removed "<<catalog[value]<<endl;
		catalog.erase(catalog.begin() + value);

	}
	else
	{
		cout<<endl;
		string isbn_b = str.substr(1,str_len);
		cout<<"- Removed " << "Book{ISBN="<< isbn_b << ", last="
				<<", first="<<", title="<<", category="<<"none"<<"}"<<endl;

		cout<<"*** Book not found ***"<<endl;

	}


}

void search(istream& input,  vector<Book>& catalog)
{

	string str,temp;
	int cat_len=catalog.size();
	getline(input, str);
	string sub = str.substr(0,2);
	int len = str.length();

	if(str == "")
	{
		cout << "All books in the catalog:" << endl;
		for( int i = 0; i < catalog.size(); i++)
		{
			cout << catalog[i] << endl;
		}
	}
	else if(sub == " a")
	{
		string name = str.substr(8,len);
		cout<<" Books by author "<< name <<":"<<endl;
		for(int i = 0 ;i< cat_len ; i++)
		{
			if(catalog[i].get_last() == name )
			{
				cout<<catalog[i]<<endl;
			}
		}



	}
    else if(sub== " f")
    {
    	string name = str.substr(6,len);
		for(int i = 0 ;i< cat_len ; i++)
		{
			if(catalog[i].get_first() == name )
			{
				cout<<catalog[i]<<endl;
			}
		}
    }
    else if(sub == " t")
    {
    	string title = str.substr(8,len);
		for(int i = 0 ;i< cat_len ; i++)
		{
			if(catalog[i].get_title() == title )
			{
				cout<<catalog[i]<<endl;
			}
		}


    }
	else if(sub == " c")
	{
		string name = str.substr(10,len);
		Book::Category category;
		//cout << sub << endl;
		cout<<" Books in category "<< name<<": "<<endl;
		if(name=="fiction")
		   {
			category=Book::FICTION;
		   }
		   if(name =="history")
		   {
			category=Book::HISTORY;
		   }
		   if(name =="technical")
		   {
			category=Book::TECHNICAL;
		   }
		for(int i = 0 ;i< cat_len ; i++)
		{
				if(catalog[i].get_category() == category)
				{
					cout << catalog[i]<<endl;
				}
		}


	}
	else if(sub == " i")
	{

		sub = str.substr(10,len);
		//cout << sub << endl;
		cout<<" Book with ISBN "<<str.substr(6,len)<<":"<<endl;
		int sub_temp=find(sub, catalog);
		if (sub_temp == -1) {}
		else cout << catalog[sub_temp] << endl;

	}

}

