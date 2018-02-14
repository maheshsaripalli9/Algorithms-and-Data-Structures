#include "Book.h"
#include "BookList.h"
#include "BookNode.h"
#include<iostream>
#include<vector>
#include <iomanip>
#include <fstream>
#include <string>
#include<cstring>

using namespace std;

const string CATEGORIES_FILE_NAME = "categories.txt";

void listBooks(string s);
/**
 * The main. Create and print the book lists.
 */
int main()
{
   /***** Complete this main. *****/
   ifstream input;
   input.open(CATEGORIES_FILE_NAME);

   if (input.fal())
   {
      cout << "Failed to open " << CATEGORIES_FILE_NAME << endl;
      return -1;
   }

   vector < string > category_files;

   string command;
   input>>command;

    while (!input.fail())
   {
      listBooks(command);
      input >> command;
   }

   listBooks("MERGED");
   listBooks("SORTED");

  input.close();

   return 0;
}

void merge(stream& ins, BookList& list)
{


    string file_name = CATEGORIES_FILE_NAME;

    ins.open(file_name);

    string input;
    ins>>input;

    ifstream ins2;


    while (!ins.fail())
    {
       string cat_file_name = input+".txt";
       ins2.open(cat_file_name);
       Book book;
       ins2>>book;

       while (!ins2.fail())
       {
          list.Insert(book);
          ins2>>book;
       }
       ins2.close();

       ins>>input;
    }

    list.print();

}

void listBooks(string category)
{
   ifstream ins;
   BookList list(category);

    if(category == "MERGED")
    {

    }
//    {

//
//        string file_name = CATEGORIES_FILE_NAME;
//
//        ins.open(file_name);
//
//        string input;
//        ins>>input;
//
//        ifstream ins2;
//
//
//        while (!ins.fail())
//        {
//           string cat_file_name = input+".txt";
//           ins2.open(cat_file_name);
//           Book book;
//           ins2>>book;
//
//           while (!ins2.fail())
//           {
//              list.Insert(book);
//              ins2>>book;
//           }
//           ins2.close();
//
//           ins>>input;
//        }
//
//        list.print();
//     }
    else  if(category == "SORTED")
    {

    }
    else
    {

        BookList list(category);

        string file_name = category+".txt";
        ins.open(file_name);

        if (ins.fail())
        {
           cout << "Failed to open category file" << file_name << endl;
           return;
        }

        Book book;
        ins>>book;

        while (!ins.fail())
        {
           list.Insert(book);
           ins>>book;
        }
        list.print();

    }


}



