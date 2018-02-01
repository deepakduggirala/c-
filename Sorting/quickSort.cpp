/*	
	Date: 13-05-2015
	Author: Deepak Duggirala
	Description: This program implements the quick sort on integer arrays
*/
#include<iostream>
#define SIZE 10

using namespace std;

void quickSort(int* A,int start,int end)
{
	//base case
	if(end-start == 0)
		return;
	//partitioning
	int pivot,temp,L,H;
	pivot = A[start];
	L = start+1;
	for(H=start+1;H<end;H++)
	{
		if(A[H]<=pivot)
		{
			if(L!=H)
			{
				temp = A[L];
				A[L] = A[H];
				A[H] = temp;
			}
			L++;
		}
	}
	//move pivot into place
	temp = pivot;
	A[start] = A[L-1];
	A[L-1] = pivot;
	//Recursive calls
	quickSort(A,start,L-1);
	quickSort(A,L,end);
}

int main()
{
	int data[SIZE] = {12, 43, -56, 23, 54, 1, 0, 87, 34, -90};
	quickSort(data,0,SIZE);
	for(int i=0;i<SIZE;i++)
	{
		cout<<data[i]<<", ";
	}
}
