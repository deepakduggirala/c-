#include<stdio.h>
#include<algorithm>
#define SIZE 11
using namespace std;

int main()
{
	int data[SIZE] = {1, 4, 2, 6, 23, 5, 57, 23, 4352, 4, 32};
	sort(data,data+SIZE);
	for(int i=0;i<SIZE;i++)
		printf("%d,",data[i]);
	printf("\n");
}
