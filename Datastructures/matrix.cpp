#include<stdio.h>
#include<iostream>

using namespace std;

class Matrix
{
	int m[2][2];
	friend Matrix operator*(Matrix &A, Matrix &B);
	public:
		Matrix(int a11,int a12,int a21, int a22);
		void display(void);
		int getElem(int i,int j);
		void setElem(int i,int j,int val);
};

//Constructor
Matrix::Matrix(int a11=1,int a12=0,int a21=0, int a22=1)
{
	m[0][0] = a11;
	m[0][1] = a12;
	m[1][0] = a21;
	m[1][1] = a22;
}

//Get element
int Matrix::getElem(int i,int j)
{
	return m[i-1][j-1];
}

//Set element
void Matrix::setElem(int i,int j,int val)
{
	m[i-1][j-1] = val;
}

//Dispaly
void Matrix::display(void)
{
	cout<<m[0][0]<<" "<<m[0][1]<<endl;
	cout<<m[1][0]<<" "<<m[1][1]<<endl;
}

//Overloading multiplication operator
Matrix operator*(Matrix &A, Matrix &B)
{
	
	Matrix C;
	int x,i,j,k,sum;
	for(i=1;i<=2;i++)
	{
		for(j=1;j<=2;j++)
		{
			sum = 0;
			for(k=1;k<=2;k++)
			{
				sum+=A.getElem(i,k)*B.getElem(k,j);
			}
			C.setElem(i,j,sum);
		}
	}
	return C;
}



int main()
{
	Matrix a(1,2,3,4);
	Matrix I,result;
	result = a*I;
	result.display();
}
