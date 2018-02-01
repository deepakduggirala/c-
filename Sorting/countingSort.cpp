/*	
	Date: 13-05-2015
	Author: Deepak Duggirala
	Description: This program implements the counting sort on integer arrays
*/
#include<iostream>
#define SIZE 10
using namespace std;

void countingSort(int* A,int* B,int n,int k)
/*
	a is the data array
	n is the size of the array
	b is the sorted array
	1 to k is the range of the data values
*/
{
	int C[k+1];
	for(int i=1;i<=k;i++)
		C[i] = 0;
	for(int j=0;j<n;j++)
		C[A[j]]++;
	//C[i] now contains the number of elements equal to i
	for(int i=2;i<=k;i++)
		C[i] = C[i] + C[i-1];
	//C[i] now contains the number of elements less than or equal to i
	for(int j=n-1;j>=0;j--)
	{
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
}
int main()
{
	int data[SIZE] = {12, 43, 56, 54, 1, 40, 87, 34, 90,100};
	int result[SIZE+1];
	int k = 100;
	countingSort(data,result,SIZE,k);
	for(int i=1;i<=SIZE;i++)
	{
		cout<<result[i]<<", ";
	}
}
