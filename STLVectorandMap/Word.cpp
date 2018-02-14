/*
 * Word.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: maheshsaripalli
 */




#include <string>
#include "Word.h"
using namespace std;



Word::Word() : text(""), count(0) {}
Word::Word(string text) : text(text), count(1) {}

Word::~Word() {}
string Word::get_text() const
{
	return text;
}
void Word::inc_count()
{
	count++;
}

int Word::get_count()
{
	return count;
}

 bool operator!= (Word w1, Word w2)
{
	 if(w1.text != w2.text || w1.count != w2.count) return true;
	 else return false;
}
