/*	
	Date: 14-05-2015
	Author: Deepak Duggirala
	Description: This program implements the bucket sort on integer arrays
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

#define SIZE 10

using namespace std;

void bucketSort(double* A,int n)
/*
	a is the data array
	n is the size of the array
*/
{
	//Create n empty buckets
    vector<double> B[n];
    //Insert elems in appropriate bucket
    for(int i=0;i<n;i++)
    	B[int(floor(n*A[i]))].push_back(A[i]);
    //Sort each bucket
    for(int i=0;i<n;i++)
    	sort(B[i].begin(),B[i].end());
    //Concatenate lists together in order
    int index = 0;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<B[i].size();j++)
    	{
    		A[index++] = B[i][j];
    	}
    }
}
int main()
{
	double data[SIZE] = {0.12, 0.43, 0.56, 0.23, 0.54, 0.1, 0.0, 0.87, 0.34, 0.90};
	bucketSort(data,SIZE);
	for(int i=0;i<SIZE;i++)
	{
		cout<<data[i]<<", ";
	}
}
