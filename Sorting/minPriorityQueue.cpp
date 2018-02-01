/*
	Author: Deepak Duggirala
	Date:	17-08-2015
	Description:Implementation of Minimum Priority Queue
*/
#include<iostream>

#define Left(i) 2*i
#define Right(i) 2*i+1
#define Parent(i) i/2

using namespace std;

void minHeapify(int A[], int i,int heapSize);
void buildHeap(int A[],int arraySize);
int minHeapExtractMin(int A[],int& heapSize);
void minHeapDecreaseKey(int A[],int i,double key);

//Heapify algorithm for min-heap
/*
	O(lg(n))
	Maintains the heap property.
	Assumes that subtrees at left(i) and right(i) are heap sorted and i is out of place.
	i varies from 1 to heap size
*/
void minHeapify(int A[], int i,int heapSize)
{
	int smallestElemIndex,l,r;
	int temp;
	l = Left(i);
	r = Right(i);
	l--; r--; heapSize--; i--;
	if(l<= heapSize && A[l] < A[i])
		smallestElemIndex = l;
	else
		smallestElemIndex = i;
	if(r<=heapSize && A[r] < A[smallestElemIndex])
		smallestElemIndex = r;
	if(smallestElemIndex != i)
	{
		temp = A[i];
		A[i] = A[smallestElemIndex];
		A[smallestElemIndex] = temp;
		minHeapify(A,++smallestElemIndex,++heapSize);
	}
}

//Build-Heap algorithm for min heap
void buildHeap(int A[],int arraySize)
/*
	O(n)
	builds a heap out of array A
*/
{
	for(int i = arraySize/2; i>=1;i--)
	{
		minHeapify(A,i,arraySize);
	}
}

//Extract maximum from min heap
/*
O(lg(n))
*/
int minHeapExtractMin(int A[],int& heapSize)
{
	if(heapSize < 1)
	{
		cout<<"Error: Heap underflow"<<endl;
	}
	else
	{
		int min = A[0];
		A[0] = A[heapSize-1];
		heapSize--;
		minHeapify(A,1,heapSize);
		return min;
	}
}


//Heap-Decrease-Key algorithm for min Heap
/*
O(lg(n))
*/
void minHeapDecreaseKey(int A[],int i,double key)
{
	int temp;
	if(key > A[i])
	{
		cout<<"Error: New key is smaller than current key"<<endl;
	}
	else
	{
		A[i] = key;
		while(i>1 && A[Parent(i)-1] > A[i-1])
		{
			temp = A[i-1];
			A[i-1] = A[Parent(i)-1];
			A[Parent(i)-1] = A[i-1];
			i = Parent(i);
		}
	}
}

