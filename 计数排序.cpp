#include <iostream>
using namespace std;
const int SIZE=10;
int A[SIZE],C[SIZE];

void csort()
{//�������� 
	int i,j,temp[SIZE];//temp[]���ڱ���A[] 
	for(i=0;i<SIZE;i++) 
	{	//������ͬʱ����A[]��temp[] 
		C[i]=0; temp[i]=A[i]; 
		for(j=0;j<SIZE;j++) 
		if(A[i]>A[j]) 
			C[i]++; 
	}
	for(i=0;i<SIZE;i++) 
	A[C[i]]=temp[i];
}
int main()
{
	int i;
	cout<<"������"<<SIZE<<"������"<<endl; 
	for(i=0;i<SIZE;i++) 
		cin>>A[i]; 
	csort(); 
	for(i=0;i<SIZE;i++) 
		cout<<A[i]<<" "; 
	cout<<endl; 
	return 0;
} 
