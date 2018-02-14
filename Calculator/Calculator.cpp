/*
 * Calculator.cpp
 *
 *  Created on: Oct 31, 2017
 *      Author: maheshsaripalli
 */
#include "Calculator.h"
#include <stdlib.h>
#include <sstream>

using namespace std;

Calculator :: Calculator()
{

}

 double Calculator ::  expressionf(string expression) const throw(string)
{

	for(int i=0 ; i< expression.length(); i++  )
	{
		char c = expression[i];

		if(c == '%') throw string("Unexpected %"); // throw error
		if(c == '^') throw string("Unexpected ^");
		if(c == '(' ||c == '*' || c == '/')
		{
			termf(expression);
			break;
		}

		else if(c== '+' || c == '-')
		{
			// it e /E contains in expression don't do anything to that +
			if(expression[i-1] == 'e' || expression[i-1] == 'E' ) { }
			else
			{
				string expression1 = expression.substr(0,i);
				string expression2 = expression.substr(i+1, expression.length()-i);

				 double term;

				 if (c == '+')
					 {
					 term = expressionf(expression1) + expressionf(expression2);
					 }
				 else
					 {
					 term = expressionf(expression1) - expressionf(expression2);
					 }
				return term;
			}


		}
	}
	return termf(expression);



}

 double Calculator ::  termf(string term) const throw(string)
{
	for(int i=0 ; i< term.length(); i++  )
	{
		char c = term[i];

		if(c == '(')
			{

			factorf(term);  // if it has ( send to  factorf function
			break;
			}

		else if(c== '*' || c == '/' )
		{
			string factor1 = term.substr(0,i);
			string factor2 = term.substr(i+1, term.length()-i);

			 double term1 =  termf(factor1) ;
			 double term2 =	 termf(factor2);

			 double term;
			if (c == '*')  term=term1 * term2;
			else
				{
					if(term2 == 0) throw  string(" Divison By zero"); // error check
					term=term1 / term2;
				}
			return term;
			break;

		}
	}
	return factorf(term);
}

 double Calculator ::  factorf(string& factor) const throw(string)
{
	for(int i=0 ; i< factor.length(); i++  )
	{
		char c = factor[i];

		if( c == '(')
		{

			int j= i;

			while(factor[j] != ')')
				{
					j++;
				}

			string expression = factor.substr(i+1,j-1);

			return expressionf(expression);
		}

	}

	   stringstream ss(factor);
	   double value = 0;
	   ss >> value;


	   return value;

}

