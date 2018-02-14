/*
 * IsUnique.cpp
 *
 *  Created on: Feb 12, 2018
 *      Author: maheshsaripalli
 */

#include<iomanip>
#include<iostream>
#include<string>


using namespace std;

bool IsUnique(string s);
int main()
{
	string s;
	cout << "enter string:  ";
	cin >> s;
	cout << IsUnique(s);
}

bool IsUnique(string s)
{
	bool a[256];
	memset(a,0,sizeof(a));

	for(int i=0; i<s.length() ; i++)
	{
		int v = s[i];
		if(a[v])  return false;
		a[v] = true;

	}
	return true;

}

