/*
 * spirals.cpp
 *
 *  Created on: Sep 8, 2017
 *      Author: maheshrajusaripalli
 *
 */
#include<iostream>
#include<string>
#include<iomanip>


using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

/***** Complete this program. *****/

void do_spiral(const int n, const int start);
void make_spiral(int n, int matrix[n][n],int start);
void print_spiral(int n, int matrix[n][n]);


/**
 * The main: Generate and print spirals of various sizes.
 */
int main()
{
    do_spiral(1, 1);
    do_spiral(5, 1);
    do_spiral(9, 11);
    do_spiral(12, 13);
    do_spiral(15, 17);
}

void do_spiral(const int n, const int start)
{
	cout<<"Spiral of size "<< n <<" starting at "<<start;

	if(n%2==0)
	{
		cout<<"***** Error: Size "<< n <<" must be odd.";
	}
	else
	{
	int matrix[n-1][n-1];
	make_spiral(n,matrix,start);
	print_spiral(n, matrix);
	return;
	}
}

void make_spiral(int n, int matrix[n][n], int start)
{

	int center=(n-1)/2;
	int c1=center++;
	int c2=center--;
	int r1=center++;
	int r2=center--;

	matrix[center][center]=start;
	int last_col=center;
	int last_row=center;
	while(!(last_row==(n-1) && last_col==(n-1)))
	{
		for(int j=last_col;j<=r2;j--)
		{
			matrix[j][c1]=++start;
		}
		for(int i=c1-1;i<=c2;i--)
		{
			matrix[r2][i]=++start;
		}
		for(int j=r2+1;j<=r1;j++)
		{
			matrix[j][c2]=++start;
		}
		for(int i=c2+1;i<=c1;i++)
		{
			matrix[r1][i]=++start;
			 last_col=i;
			 last_row=r1;
		}
		r1++;
		r2--;
		c1++;
		c2--;
	}

}

void print_spiral(int n, int matrix[n][n])
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			cout<<setw(3)<<matrix[i][j];
		}
		cout<<"\n";
	}
}
