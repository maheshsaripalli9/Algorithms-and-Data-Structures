/*
 * Calculator.h
 *
 *  Created on: Oct 31, 2017
 *      Author: maheshsaripalli
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include<cstring>
#include<iostream>
#include <iomanip>
#include <fstream>
#include <string>

 using namespace std;


class Calculator
{
public:
/*
 * constructor
 */
	Calculator();
	/*
	 * reads + / - and executes the coresponding expressions nd returns double value
	 * @param expression is a string
	 */
	 double expressionf(string expression) const throw(string);
	 /*
	  * reads   / *  and executes the corresponding and returns double value
	  */
	 double termf(string term) const throw(string);
	 /*
	  * reads  and send the expression between () to expressionf or else return double
	  * @param term is a string
	  */
	 double factorf(string& term)const throw(string);


};




#endif /* CALCULATOR_H_ */
