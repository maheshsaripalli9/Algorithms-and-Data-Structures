/*
 * example.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: maheshsaripalli
 */

#include <iostream>
#include <string>

using namespace std;
string longest_palindrome(string input);
int main()
{
string input = "ThEre";

    string res = longest_palindrome(input);
    cout<< res;

}
bool check_palindrome(string in);
string longest_palindrome(string input) {
	string result = input;
	transform(input.begin(), input.end(), input.begin(), ::tolower);

	remove( input.begin(), input.end(), ' ' );

//	string::iterator end_pos = std::remove(input.begin(), input.end(), ' ');
//	input.erase(end_pos, input.end());

    string res;
    int final=0,temp;
    int x, y;
    for(int i=0; i<= input.length(); i++)
    {

       for(int j=i+1; j<= input.length(); j++)
       {
           string in = input.substr(i,j);

           bool flag = check_palindrome(in);
          // cout << in  <<  "     "<<flag << endl;
           temp = abs(i-j);
           if(flag == true)
           {

               if(final == 0 )
               {

                   res = in;
                   final = temp;
                   x=i;
                   y=j;

               }
               else if(final < temp)
            	   {

            	   res = in;
            	   final = temp;
            	   x=i;
            	   y=j;

            	   }
              // cout << res << endl;
           }
       }
    }

    if (final!=1) return result.substr(x,y);
    else return "";


}

bool check_palindrome(string in)
{
    bool flag = true;
    int length = in.length();
    for(int i=0;i < length ;i++)
    {
        if(in[i] != in[length-i-1])
        {
            flag = false;
            break;
        }
    }
    return flag;
}
