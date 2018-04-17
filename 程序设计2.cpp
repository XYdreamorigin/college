#include<stdio.h>

int main()
{
	char ch1,ch2;
	FILE *fp1 = fopen("p12in.c", "r");
	FILE *fp2 = fopen("p12out.c", "w");
	fscanf(fp1,"%c%c",&ch1,&ch2);
	while (!feof(fp1))
	{
		 if(ch1=='/'&&ch2=='/')
		 {
            while(ch1!='\n')
			{
            ch1=fgetc(fp1);
       		}
            fprintf(fp2,"\n");
            fscanf(fp1,"%c%c",&ch1,&ch2);
        }
		else if(ch1=='/'&&ch2=='*')
		{
        	while(ch1!='*'|| ch2!='/')
			{
           		ch1=ch2;
            	ch2=fgetc(fp1);
            }
            fscanf(fp1,"%c%c",&ch1,&ch2);
        }	
        else{
        fprintf(fp2,"%c",ch1);
        ch1=ch2;
        ch2=fgetc(fp1);
        }
        
       
	}
	fclose(fp2);
    fclose(fp1);
    return 0;
 } 
