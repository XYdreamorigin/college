#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int pos[100],n=0;//pos数组记录t中元素在s中的位置，n为总个数

int length(char *S)
{
	return strlen(S);
}


char* Sub(char*S,int pos,int len)
{
	char*res=(char*)malloc(sizeof(char)*len);
	for(int i=pos,j=0;j<=len;j++,i++)
	{
		res[j]=S[i];
	}
	return res;
}
char* Concat(char *S,char*T)
{
	S=(char*)realloc(S,sizeof(char)*strlen(T));
	for(int i=strlen(S),j=0;j<strlen(T);i++,j++)
	{
		S[i]=T[j];
	}
	return S;
} 

bool Equal(char a,char* B)//判断字符a是否是字符串B里面的元素
{
	for(int i=0;i!=length(B);i++)
	{
		if(a==B[i])
		{
			return true;
		}
	}
	return false;
 } 
 
int main()
{
	char *S,*T;
	int Ssize,Tsize;
	printf("请输入字符串S的长度及其字符串：\n");
	scanf("%d",&Ssize);
	getchar();
	S=(char*)malloc(sizeof(char)*Ssize);
	gets(S);
	printf("请输入字符串T的长度及其字符串：\n");
	scanf("%d",&Tsize);
	getchar();
	T=(char*)malloc(sizeof(char)*Tsize);
	gets(T);
	int i;
	char *r=(char*)malloc(sizeof(char));
	r[0]=NULL;
	for(i=0;i!=length(S);i++)
	{
		if(Equal(S[i],T)!=1)
		{
			char *temp=(char*)malloc(sizeof(char)*1);
			temp=Sub(S,i,1);
			r=Concat(r,temp);
			pos[n++]=i;
		}
	}
	
	if(r==NULL)
	{
		printf("s串中的所有字符均在t串中出现！\n");
		return 0;
	}
	
	printf("s串中出现t串中不出现的合串为：\n");
	puts(r);
	printf("位置依次是：\n");
	for(int i=0;i!=n;i++)
	{
		printf("%d  ",pos[i]);
	 } 
	 return 0;
}

















