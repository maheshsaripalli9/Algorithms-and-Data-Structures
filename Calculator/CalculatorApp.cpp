/*
 * CalculatorApp.cpp
 *
 *  Created on: Oct 30, 2017
 *      Author: maheshsaripalli
 */


# include "Calculator.h"
using namespace std;

int main()
{


	    string ch;
	    Calculator cal;

	    bool check = true;

	    while(check)
	    {
	    		try
	    		{
	    			char c;
	    			cout << "expression ? ";
	    	        cin >> ws;
	    	        c = cin.peek();
	    	        if(c == '.')    // end of program
	    	        	{
	    	        	check = false;
	    	        	break;
	    	        	}
				getline(cin,ch, '=');// reads expression until delimeter(=)
				int count1=0 ,count2=0;
				for (int i=0 ; i<ch.length();i++)
				{
					if(ch[i] == '(') count1++;
					if(ch[i] == ')') count2++;
				}
				if(count1>count2) throw string("Missing )");
				else if (count1<count2) throw string("unexpected )");
				double result = cal.expressionf(ch);
				cout<< result <<endl;

	    		}
	    	    catch(string& msg)
	    	    {
	    	        cout << "***** " << msg << endl;
	    	    }
	    }
	    cout << endl << "Done!" << endl;
	    return 0;
}


