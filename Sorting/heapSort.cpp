/*	
	Date: 13-05-2015
	Author: Deepak Duggirala
	Description: This program implements the heap sort on integer arrays
*/
#include<iostream>

#define SIZE 10
#define LEFT(i) 2*i
#define RIGHT(i) 2*i+1
#define PARENT(i) i/2

using namespace std;

void heapify(int* A,int i,int heapSize)
/*
	O(lg(n))
	Maintains the heap property.
	Assumes that subtrees at left(i) and right(i) are heap sorted and i is out of place.
	i varies from 1 to heap size
*/
{
	int l,r,indexOfLargest,temp;
	l = LEFT(i);
	r = RIGHT(i);
	l--; r--; heapSize--; i--;
	if(l <= heapSize && A[l] > A[i])
	{
		indexOfLargest = l;
	}
	else
		indexOfLargest = i;
	if(r <= heapSize && A[r] > A[indexOfLargest])
		indexOfLargest = r;
	if(indexOfLargest != i)
	{
		temp = A[i];
		A[i] = A[indexOfLargest];
		A[indexOfLargest] = temp;
		heapify(A,++indexOfLargest, ++heapSize);
	}
}

void buildHeap(int* A,int arraySize)
/*
	O(n)
	builds a heap out of array A
*/
{
	for(int i = arraySize/2; i>=1;i--)
	{
		heapify(A,i,arraySize);
	}
}

void heapSort(int* A,int arraySize)
{
	int temp,heapSize;
	heapSize = arraySize;
	
	buildHeap(A,arraySize);
	for(int i=arraySize-1; i>=0; i--)
	{
		//exchange A[1] and A[i]
		temp = A[i];
		A[i] = A[0];
		A[0] = temp;;
		heapSize--;
		heapify(A,1,heapSize);
	}
}

int main()
{
	int data[SIZE] = {12, 43, -56, 23, 54, 1, 0, 87, 34, -90};
	heapSort(data,SIZE);
	for(int i=0;i<SIZE;i++)
	{
		cout<<data[i]<<", ";
	}
	
}
