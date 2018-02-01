/*	
	Date: 13-05-2015
	Author: Deepak Duggirala
	Description: This program implements the insertion sort on integer arrays
*/
#include<iostream>
#define SIZE 10
using namespace std;

void insertionSort(int* a,int n)
/*
	a is the data array
	n is the size of the array
*/
{
	int pos,nextPos,temp;
	for(pos=1; pos<n;pos++)
	{
		//Build longer and longer sorted segments
		//In each iteration A[0]...A[pos-1] is already sorted
		//Move first element after sorted segment left till it is in the correct place
		nextPos = pos;
		while(nextPos>0 && a[nextPos]<a[nextPos-1])
		{
			temp = a[nextPos];
			a[nextPos] = a[nextPos-1];
			a[nextPos-1] = temp;
			nextPos = nextPos-1;
		}
	}
}
int main()
{
	int data[SIZE] = {12, 43, -56, 23, 54, 1, 0, 87, 34, -90};
	insertionSort(data,SIZE);
	for(int i=0;i<SIZE;i++)
	{
		cout<<data[i]<<", ";
	}
}
