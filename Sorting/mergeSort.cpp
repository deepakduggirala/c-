/*	
	Date: 13-05-2015
	Author: Deepak Duggirala
	Description: This program implements the merge sort on integer arrays
*/
#include<iostream>
#define SIZE 10
using namespace std;

void merge(int* A,int m,int* B,int n,int* C)
{
	int i,j,k;
	i=0;j=0;k=0;
	while(i<m && j<n)
	{
		if(A[i] <= B[j])
		{
			C[k] = A[i];
			k++;i++;
		}
		else
		{
			C[k] = B[j];
			k++;
			j++;
		}
	}
	while(i<m)
	{
		C[k] = A[i];
		k++;i++;
	}
	while(j<n)
	{
		C[k] = B[j];
		k++;
		j++;
	}
}

void mergeSort(int* A,int start,int end,int* B)
/*
	A is the data array
	start and end are boundary indices of the sorting range
	B is the sorted array
*/
{
	if(start-end == 0)
		B[0] = A[start];
	else
	{
		int mid;
		mid = (start+end)/2;
		
		int L[mid-start+1],R[end-mid];
		
		mergeSort(A,start,mid,L);
		mergeSort(A,mid+1,end,R);
		merge(L,mid-start+1,R,end-mid,B);
	}
}
int main()
{
	int data[SIZE] = {12, 43, -56, 23, 54, 1, 0, 87, 34, -90};
	int results[SIZE];
	mergeSort(data,0,SIZE-1,results);
	for(int i=0;i<SIZE;i++)
	{
		cout<<results[i]<<", ";
	}
}
