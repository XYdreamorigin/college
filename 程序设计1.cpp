
#include <stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp = fopen("p1.txt", "r");
	int Cap = 0, Low = 0, Dig = 0, Oth = 0;
	char ch;
	int line = 1;
	int max=0, min=0,temp=0;
	char a[25],c[25];
	int b[25] = { 0 };
	int d[25] = { 0 }; 
	int i,j,k;
	j=65;k=97;
	for (i = 0; i <26; i++)
		{
			a[i] = j;
			j++;
			c[i] = k;
			k++;
		
		}
	
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch <= 90 && ch >= 65)
			Cap++;
		else if (ch >= 97 && ch <= 122)
			Low++;
		else if (ch <= 57 && ch >= 48)
			Dig++;
		else
			Oth++;
	
		if(ch==10)
		{
			if(max==0)
			max=temp;
			if(min==0)
			min=temp;
			if (temp > max)
			max = temp;
			else if(temp<min&&temp!=0)
			min = temp;
	
			line++;
			temp=0;
			
		}
		else
		temp++;
		for(i=0;i<26;i++)
		{
			if (a[i]==ch)
			b[i]++;
			else if (c[i]==ch)
			d[i]++;	
		}	

	}	
	
	
	printf("The result is:\n\nTask1:\ncapital:%d\nlowercase:%d\ndigit:%d\nothers:%d", Cap, Low, Dig, Oth);
	printf("\n\nTask2\nline:%d\n%d characters in max line.\n%d characters in min line.", line, max, min);
	printf("\n\nTask3\nCAPITAL:\n");
	for (i = 0; i <26; i++)
	{
		if((i+1)%4==0&&i!=0)
		printf("%c:%d\n", a[i], b[i]);
		else
		printf("%c:%d\t", a[i], b[i]);
	}
		
	printf("\nLOWERCASE:\n");

	for (j = 0; j < 26; j++)
	{
		if((j+1)%4==0&&j!=0)
		printf("%c:%d\n", c[j], d[j]);
		else
		printf("%c:%d\t", c[j], d[j]);
	}
	system("pause");
	fclose(fp); 
    return 0;
}
//#include"stdafx.h"
