/*
 * WordMap.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: maheshsaripalli
 */




#include <iostream>
#include <map>
#include "WordMap.h"



using namespace std;

WordMap::WordMap()
{

}

WordMap::~WordMap()
{

}

Word *WordMap::insert(const string text)
{
	map<string, Word> ::iterator it = data.find(text);
	if(it == data.end())
	{
		data[text] = Word(text);
	}
	else
	{
		(it->second).inc_count();

	}
	return &(it->second);

}

Word *WordMap::search(const string text)
{
	map<string, Word> ::iterator it = data.find(text);

	if(it != data.end()) return &(it->second);
	else return nullptr;
}

int WordMap::get_size()
{
	return data.size();
}
map<string, Word>& WordMap::get_data()
{
	return data;
}
