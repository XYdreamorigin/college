#include<stdio.h>
#define SIZE 10
int A[SIZE+1]={0},C[SIZE+1]={0};


int main()
{
	void sort();
	int i;
	printf("请输入%d个数字\n",SIZE);
	for(i=1;i<=SIZE;i++)
		scanf("%d",&A[i]);
	sort();
	for(i=1;i<=SIZE;i++)
		printf("%d  ",A[i]);	
 } 
 
 void sort()
 {
 	int i,j,temp[SIZE];
 	for(i=1;i<=SIZE;i++) 
	{	//计数，同时复制A[]到temp[]  
		temp[i-1]=A[i]; 
		for(j=1;j<=SIZE;j++) 
		if(A[i]>A[j]) 
			C[i]++; 
	}
	for(i=1;i<=SIZE;i++) 
	A[C[i]+1]=temp[i-1];
 }
