/*
 * RomanNumeral.cpp
 *
 *  Created on: Sep 24, 2017
 *      Author: maheshsaripalli
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "RomanNumeral.h"

using namespace std;
// deafult constructor
RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{
}
// string value constructor
// @param roman value is passed to construcotr
RomanNumeral :: RomanNumeral(string rom)
{
	roman=rom;

	decimal = to_decimal(roman);
}
/*
 * Int value constructor
 * @param decimal value is passed to constructor
 */
RomanNumeral :: RomanNumeral(int dec)
{
	decimal=dec;

	roman = to_roman(decimal);
}
/*
 *returns the decimal value
 */
int RomanNumeral :: get_decimal() const
{
	return decimal;
}
/*
 *returns the roman value
 */
string RomanNumeral :: get_roman() const
{
	return roman;
}
/*
 *over ride  + operator (returns int value)
 *returns sum of the two romannumeral class decimals values
 */
int operator + (const RomanNumeral& r1, const RomanNumeral& r2 )
{
	return r1.get_decimal() + r2.get_decimal();
}
/*
 *over ride  - operator (returns int value)
 *returns differnce of the two romannumeral class decimals  values
 */
int operator - (const RomanNumeral& r1, const RomanNumeral& r2 )
{
	return r1.get_decimal() - r2.get_decimal();
}
/*
 *over ride  * operator (returns int value)
 *returns product of the two romannumeral class decimals values
 */
int operator * (const RomanNumeral& r1, const RomanNumeral& r2 )
{
	return r1.get_decimal() * r2.get_decimal();
}
/*
 *over ride  / operator (returns int value)
 *returns quotient  of the two romannumeral class decimals values
 */
int operator / (const RomanNumeral& r1, const RomanNumeral& r2 )
{
	return r1.get_decimal() / r2.get_decimal();
}
/*
 *over ride  == operator (returns bool value)
 *returns true  if the two romannumeral class decimals values are equal
 */
bool operator == (const RomanNumeral& r1, const RomanNumeral& r2 )
{
	return r1.get_decimal()==r2.get_decimal();
}
/*
*over ride  != operator (returns bool value)
*returns true  if the two romannumeral class decimals values are not equal
*/
bool operator!= (const RomanNumeral& r1, const RomanNumeral& r2 )
{
	return r1.get_decimal()!=r2.get_decimal();
}
/*
*over ride << operator
*To take the romannumeral class inputs
*/
ostream& operator <<(ostream& outs, const RomanNumeral& r1 )
{
	outs << "[" << r1.decimal << ":"<< r1.roman << "]";
	return outs;
}
/*
*over ride >> operator
*To return the romannumeral class outputs
*/
istream& operator >>(istream& ins, RomanNumeral& r1 )
{
	ins >> r1.roman;
	string s = r1.roman;
	r1.decimal = r1.to_decimal(s);
	return ins;

}
/*
*private function to convert decimal to string
*/
string RomanNumeral :: to_roman(int decimal)
{
	string roman;
    // storing roman values of digits from 0-9
    // when placed at different places
	// range 1-3999
    string i_1[] = {"", "I", "II", "III", "IV", "V","VI", "VII", "VIII", "IX"};
    string x_10[] = {"", "X", "XX", "XXX", "XL", "L","LX", "LXX", "LXXX", "XC"};
    string c_100[] = {"", "C", "CC", "CCC", "CD", "D","DC", "DCC", "DCCC", "CM"};
    string m_1000[] = {"", "M", "MM", "MMM"};

    // Converting to roman
    roman += m_1000[decimal/1000]; // adding thousands place roman value to roman string
    decimal=decimal%1000;
    roman += c_100[decimal/100];  // adding hundreds place roman value to roman string
    decimal= decimal%100;
    roman +=  x_10[decimal/10];  // adding tens place roman value to roman string
    decimal=decimal%10;
    roman += i_1[decimal%10];    // adding ones place roman value to roman string

    return roman;
}
/*
*private function to convert  string to decimal
*/
int RomanNumeral :: to_decimal(string roman)
{
	int decimal=0;
	int value;
	int array[30];
	//converting roman string to array of values with same index
	for(int i=0;i<roman.length();i++)
	{
		if(roman[i]=='I')      value = 1;
		else if(roman[i]=='V') value = 5;
		else if(roman[i]=='X') value = 10;
		else if(roman[i]=='L') value = 50;
		else if(roman[i]=='C') value = 100;
		else if(roman[i]=='D') value = 500;
		else if(roman[i]=='M') value = 1000;
		array[i]=value; //storing string deciaml into array
	}
	// Loop through the array values
	// check whether the pointed index array value is greater or equal
	// if add value to result else add the next pointed index value to result and subract the index position value
	for(int i=0; i<roman.length();i++)
	{
		if(i+1 >= roman.length())
		{
			decimal += array[i];
			i++;
		}
		else
		{
			if(array[i] < array[i+1])
			{
				decimal +=  array[i+1]-array[i];
				i++;

			}
			else
			{
				decimal += array[i];

			}
		}
	}
	return decimal;
}





