/*	
	Date: 13-05-2015
	Author: Deepak Duggirala
	Description: This program implements the selection sort on integer arrays
*/
#include<iostream>
#define SIZE 10
using namespace std;

void selectionSort(int* a,int n)
/*
	a is the data array
	n is the size of the array
*/
{
	int i,startPos,minElemPos,temp;
	for(startPos=0;startPos<n;startPos++)
	{
	//scan segments A[0]...A[n-1], A[1]...A[n-1], ...
	//Locate positions of minimum elementin current segement
		minElemPos = startPos;
		for(i = minElemPos+1;i<n;i++)
		{
			if(a[i] < a[minElemPos])
			{
				minElemPos = i;
			}
		}
		//Move minimum element to start of current segment
		temp = a[startPos];
		a[startPos] = a[minElemPos];
		a[minElemPos] = temp;
	}
}
int main()
{
	int data[SIZE] = {12, 43, -56, 23, 54, 1, 0, 87, 34, -90};
	selectionSort(data,SIZE);
	for(int i=0;i<SIZE;i++)
	{
		cout<<data[i]<<", ";
	}
}
