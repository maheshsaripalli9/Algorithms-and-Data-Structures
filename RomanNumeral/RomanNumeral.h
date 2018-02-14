/*
 * RomanNumeral.h
 *
 *  Created on: Sep 24, 2017
 *      Author: maheshsaripalli
 */
#include<iostream>
#include<string>
#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

using namespace std;

class RomanNumeral
{
public:
    /**
     * Default constructor.
     */
    RomanNumeral();
	/*
	 * roman value constructor
	 * @param roman value is passed to constructor
	 */
    RomanNumeral(string roman);

    /*
     * Int value constructor
     * @param decimal value is passed to constructor
     */
    RomanNumeral(int decimal);
    /*
     *returns the decimal value
     */
    int get_decimal() const;
    /*
     *returns the roman value
     */
    string get_roman() const;
    /*
     *over ride  + operator (returns int value)
     *@param RomanNumeral class object-1
     *@param RomanNumeral class object-2
     */
    friend int operator + (const RomanNumeral& r1, const RomanNumeral& r2 );
    /*
     *over ride  - operator (returns int value)
     *@param RomanNumeral class object-1
     *@param RomanNumeral class object-2
     */
    friend int operator - (const RomanNumeral& r1, const RomanNumeral& r2);
    /*
     *over ride  * operator (returns int value)
     *@param RomanNumeral class object-1
     *@param RomanNumeral class object-2
     */
    friend int operator * (const RomanNumeral& r1, const RomanNumeral& r2);
    /*
     *over ride  / operator (returns int value)
     *@param RomanNumeral class object-1
     *@param RomanNumeral class object-2
     */
    friend int operator / (const RomanNumeral& r1, const RomanNumeral& r2 );
    /*
     *over ride  == operator (returns bool value)
     *@param RomanNumeral class object-1
     *@param RomanNumeral class object-2
     */
    friend bool operator == (const RomanNumeral& r1, const RomanNumeral& r2 );
    /*
    *over ride  != operator (returns bool value)
    *@param RomanNumeral class object-1
    *@param RomanNumeral class object-2
    */
    friend bool operator != (const RomanNumeral& r1, const RomanNumeral& r2 );
    /*
    *over ride << operator
    *@param ostream variable
    *@param RomanNumeral class object-1
    */
    friend ostream& operator <<(ostream& outs, const RomanNumeral& r1 );
    /*
    *over ride >> operator
    *@param istream variable
    *@param RomanNumeral class object-1
    */
    friend istream& operator >>(istream& ins,  RomanNumeral& r1 );

private:
    string roman;  // Roman value
    int decimal;   // Decimal value
    /*
    *private function to convert decimal to string
    *@param decimal value
    */
    string to_roman(int decimal);
    /*
    *private function to convert  string to decimal
    *@param roman value
    */
    int to_decimal(string roman);

};



#endif /* ROMANNUMERAL_H_ */
