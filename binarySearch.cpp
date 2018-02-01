/*	
	Date: 13-05-2015
	Author: Deepak Duggirala
	Description: This program implements the Binary search algorithm on (sorted) integer arrays
*/

#include<stdio.h>
#include<iostream>
#define SIZE 10
using namespace std;

int bSearch(int (&a)[SIZE],int key,int start,int end)
/*
	a is the data array
	key is the search key
	start and end are the search range boundaries
*/
{
	start--; end--;
	int i;
	while(1)
	{
		i = (start+end)/2;
		if(key == a[i])
			break;
		else if(key < a[i])
			end = i-1;
		else
			start = i+1;
	}
	return i+1;
}

int main()
{
	int a[SIZE] = {12,23,65,78,99,100,234,45,654,7865};
	cout<<bSearch(a,78,1,10)<<endl;
}
