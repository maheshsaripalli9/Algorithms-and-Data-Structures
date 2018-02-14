#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

string encryption(string message);
string decryption(string CipherTxt);


int main(int argc, char **argv)
{
	 cout << "Enter the message: ";
	 string message;
	 cin >> message;
	 cout << "Message is :" << message;
	 //string encrypted=encryption(message);

	 cout << "\nEncrypted Message is : "  ;

	 cout << "\nDecrypted Message is: " << decryption(encrypted);
}

string encryption(string message)
{
	string CipherTxt = "";
	int a, b;
	cout<<"enter value a"<<endl;
	cin>>a;
	cout<<"enter value b"<<endl;
	cin>>b;
	char character;
	for (int i = 0; i < message.length(); i++)
	{
		character = (((a * message[i]) + b) % 26) + 65;
		CipherTxt = CipherTxt + character;
	}
	return CipherTxt;
}

string decryption(string CipherTxt)
{
	string message = "";
	int a_inv = 0;
	int flag = 0;
	int a, b;
	cout<<"enter value a"<<endl;
	cin>>a;
	cout<<"enter value b"<<endl;
	cin>>b;
	for (int i = 0; i < 26; i++)
	{
		flag = (a * i) % 26;
		if (flag == 1)	a_inv = i;
	}
	for (int i = 0; i < CipherTxt.length(); i++)
	{
	message = message + (char) (((a_inv * ((CipherTxt[i] - b)) % 26)) + 65);
	}
	return message;
}
