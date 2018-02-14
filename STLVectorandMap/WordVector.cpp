/*
 * WordVector.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: maheshsaripalli
 */




#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"

/***** Complete this file. *****/

using namespace std;

WordVector::WordVector()
{

}

WordVector::~WordVector()
{

}

Word *WordVector::insert(const string text)
{
	Word t(text);
	vector<Word>::iterator it = data.begin();

	if(data.size() == 0)
	{
		data.push_back(t);
		return &(*it);

	}
	else
	{
				bool found=false;
				int low = 0;
				int mid,high = data.size()-1;
				while(  low <= high )
				{

					mid = (low+high)/2 ;
					if(text == data[mid].get_text()) found = true;
					if (found)
					{
						data[mid].inc_count();
						return &(*it);
					}
					else if(text < data[mid].get_text())
					{
						high = mid-1;
					}
					else
					{
						low = mid+1;
					}
				}
				if(low < data.size()) it = data.begin() + low;
				else it=data.end();

		data.insert(it,t);

		return &(*it);
	}




}
Word *WordVector::search(const string text)
{
	//bool found=false;

	vector<Word>::iterator it = data.begin();

	bool found=false;
	int low = 0;
	int mid,high = data.size()-1;
	while(  low <= high )
	{

		mid = (low+high)/2 ;
		if(text == data[mid].get_text()) found = true;
		if (found)
		{
			it = data.begin() + mid;
			return &(*it);
		}
		else if(text < data[mid].get_text())
		{
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}

	}
	it=data.end();
	return &(*it);
}


vector<Word>& WordVector::get_data()
{
	return data;
}


int WordVector::get_size()
{
	return data.size();
}



