/*
 * BankPassword.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: maheshsaripalli
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
bool validPassword(string test);
int solution(string &s);


int main()
{
	string s="a0Ba";
	cout <<solution(s);

}

int solution(string &s) {
    // write your code in C++14 (g++ 6.2.0)
        int i=0,start=0,end=0;
    string temp;
    bool flag;
    int result=-1, temp_res=-1;
    while (i < s.length())
    {

       //cout<<"entering at  " << i <<"   "<< s[i] <<endl;
      	if(isdigit(s[i])) { i++;}
        else
        {
            start = i;
            while(!isdigit(s[i]))
            {
                end=i;
                i++;
            }
            //cout <<start<<end<<endl;
            if(start==end)
            {
            	temp=s[start];

            }
            else temp = s.substr(start,end);

            //cout<< temp<<endl;
            flag=false;
            for(int j=0;j<temp.length(); j++)
            {
                if(isupper(temp[j]))
                {
                    flag=true;
                    break;
                }
            }
            //cout << flag << true <<endl;
            if(flag) temp_res=temp.length();
            //cout << temp_res <<endl;
            if(result< temp_res) result=temp_res;
            //cout<<endl;
            //cout<< i <<s.length()<<endl;

        }
        //cout <<result;

    }
    return result;
}
//	int i=0,j=0, res=0,count;
//	string npos;
//	string s= "test 5 a0A pass007 ?xy1";
//	size_t pos = 0;
//	string token;
//	while ((pos = s.find(" ")) != string::npos) {
//	    token = s.substr(0, pos);
//
//		bool f = validPassword(token);
//		 cout << token << "   "<< pos << "   "<< f<<endl;
//		if (f) count = token.length();
//		if(count >res) res=count;
//
//	    s.erase(0, pos + 1);
//	}
//    cout << s <<endl;
//	bool f = validPassword(token);
//	if (f) count = token.length();
//	if(count >res) res=count;
//
//	cout<<endl;
//	cout << res;
//
//}
//
//
//bool validPassword(string test)
//{
//	bool flag = true, upper=false;
//	int letter_count=0, digit_count=0;
//	for(int i=0; i<test.length(); i++)
//	{
//	if(isupper(test[i]) || islower(test[i])) letter_count++;
//	else if(isdigit(test[i])) digit_count++;
//	else flag = false;
//
//	}
//	if(letter_count %2 ==0 && digit_count %2 != 0) upper =true;
//	return flag && upper;
//}

