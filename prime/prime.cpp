/*
 * prime.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: maheshrajusaripalli
 */

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing

/***** Complete this program. *****/


void compute_primes(bool prime_bool[ ]);
void print_primes(bool prime_bool[ ]);


/**
 * The main: Compute and print the prime numbers up to MAX_NUMBER.
 */
int main()
{
bool  prime_bool[MAX_NUMBER];
for(int i=0;i<=MAX_NUMBER;i++)
{
	 prime_bool[i]=true;
}

compute_primes(prime_bool);
print_primes(prime_bool);
return 0;
}

void compute_primes(bool prime_bool[ ])
{
	for(int i=2;i*i<=1000;i++)
	{
		if(prime_bool[i])
		{
			for(int j=i*2;j<=MAX_NUMBER;j+=i)
			{
				prime_bool[j]=false;

			}
		}
	}

}

void print_primes(bool prime[ ])
{
	int count=1;
	for(int i=2;i<=MAX_NUMBER;i++)
	{
		if(prime[i])
		{
			if(count==ROW_SIZE){
				cout<<setw(3)<<i<< "\n";
				count=1;
			}
			else
			{
			cout<<setw(3)<<i<<" ";
			count++;
			}

		}

	}
	cout<<"\n"<<"\n"<<"Done!";
}




