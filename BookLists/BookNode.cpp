/***** Complete this file. *****/
#include "BookNode.h"

BookNode :: BookNode(Book book) : book(book), next(nullptr)
{

}

BookNode :: BookNode()
{

}
BookNode *BookNode::get_next() const
{
	return next;
}
void BookNode::set_next(BookNode *next_node)
{
	next = next_node;
}

Book BookNode::get_book() const
{
	return book;
}
