#include<stdio.h>
#include<math.h>
#include<iostream>
#include<iomanip>
using namespace std;
void insertion_sort(int arr[],int n);
void print(int &arr);
int main()
{
	//int result;
	int arr[] = { 12, 22, 15, 111, 20};
	insertion_sort(arr,5);
	//print(arr);
	return 0;
}

void insertion_sort(int arr[],int n)
{
	int temp,j;
	for(int i=1; i < n; i++)
	{
		j = i;
		temp = arr[i];
		while(j>=1 && arr[j-1] > temp)
		{

			arr[j] = arr[j-1];
			j--;
 		}

		arr[j] = temp;

	}

	for(int i=0; i < n; i++)
	{
		cout << arr[i] << "  ";


	}

}

