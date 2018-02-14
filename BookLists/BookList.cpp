#include"BookList.h"
#include"Book.h"

BookList::BookList(const string name)
    : name(name), head(nullptr), tail(nullptr)
{
   // create();
}
BookList::BookList(const string name, vector<BookList>& categories): name(name), head(nullptr), tail(nullptr)
{
  merge(categories);
}

void BookList::merge(const BookList& other)
{
	// Insert each node of the other book list.
	for (BookNode *ptr = other.head; ptr != nullptr; ptr = ptr->get_next())
	{
		Insert(ptr->get_book());
	}
}
//void BookList::merge(string category)
//{
//	   ifstream ins;
//	   BookList list(category);
//    string input;
//    ins>>input;
//
//    ifstream ins2;
//
//
//    while (!ins.fail())
//    {
//       string cat_file_name = input+".txt";
//       ins2.open(cat_file_name);
//       Book book;
//       ins2>>book;
//
//       while (!ins2.fail())
//       {
//          list.Insert(book);
//          ins2>>book;
//       }
//       ins2.close();
//
//       ins>>input;
//}
void BookList::append(const Book book)
{
	BookNode *new_node = new BookNode(book);

	// First node in the list.
	if (head == nullptr)
	{
	head = tail = new_node;
	}

	// Subsequent node.
	 else
	{
	tail->set_next(new_node);
	tail = new_node;
	 }
}


void BookList::copy(const BookList &other)
{
 // Append a copy of each node of the other book list.
 for (BookNode *ptr = other.head; ptr != nullptr; ptr = ptr->get_next())
{
append(ptr->get_book());
}
}




void BookList::print()
{
   //printing the book list and count
   int count=0;

   cout<<endl<<"Book list: "<<name<<endl<<endl;

   for (BookNode *ptr = head; ptr != nullptr; ptr = ptr->next)
   {
	   cout << "  " << ptr->book ;
	   count++;
   }
    cout<<"    ("<< count <<" books)"<<endl;
}


void BookList::Insert(Book book)
{

	BookNode *new_node = new BookNode(book);
	 string isbn = book.getIsbn();

	 // First node in the list, or insertion before the first node.
	 if ((head == nullptr) || (isbn < head->get_book().getIsbn()))
	 {
	new_node = new BookNode(book);
	 new_node->set_next(head);
	head = new_node;

	 if (head->get_next() == nullptr) tail = head;
	}
	 else
	{
	  BookNode *ptr = head;
	  BookNode *prev;

	 // Look for where to insert into the book list.
	 while ((ptr != nullptr) && (isbn > ptr->get_book().getIsbn()))
	 {
	  prev = ptr;
	 ptr = ptr->get_next();
	 }

	// Insert only if not a duplicate ISBN.
	 if ((ptr == nullptr) || (isbn < ptr->get_book().getIsbn()))
	  {
	 prev->set_next(new_node);
	 new_node->set_next(ptr);

	 if (ptr == nullptr) tail = prev;
	 }
	}
}



