#include<stdio.h>
//��һ��.c�ļ�1���Ƶ���һ���ļ�2�У�Ҫ����˵��ļ�1�е�ע�͡�
//ע�����ͣ���ע�ͷ���ͷ�������е�ע�͡���һ��������ɸù��ܡ�
main()
{
       /*cfPtr1��ָ�򱻸����ļ���ָ�룬cfPtr2�Ǹ��Ƴ����ļ�*/
       FILE *cfPtr1,*cfPtr2;
       /*ch1,ch2�Ǵ洢��ǰ�ַ��ı���*/
       char ch1,ch2;
       /*�������ļ�*/
       if((cfPtr1=fopen("ceshier.c","r"))==NULL)
              printf("FILE ceshier.c count not be opened\n");
       else{
              if((cfPtr2=fopen("clinet2.c","w"))==NULL)
                     printf("FILE clinet2.c count not be opened\n");
              else{
                     fscanf(cfPtr1,"%c%c",&ch1,&ch2);
                     while(!feof(cfPtr1)){
                            /*����ע�ͷ�ʱ������ͬһ��������֮����ַ�*/
                            if(ch1=='/'&&ch2=='/'){
                                   while(ch1!='\n'){
                                          ch1=fgetc(cfPtr1);
                                   }
                                   fprintf(cfPtr2,"\n");
                                   fscanf(cfPtr1,"%c%c",&ch1,&ch2);
                            }
                            /*����ע�ͷ�ʱ���������е�����*/
                            else if(ch1=='/'&&ch2=='*'){
                                   while(ch1!='*'||ch2!='/'){
                                          ch1=ch2;
                                          ch2=fgetc(cfPtr1);
                                   }
                                   fscanf(cfPtr1,"%c%c",&ch1,&ch2);
                            }
                            /*��cfPtr1ָ����ļ��е��������ַ�����cfPtr2ָ����ļ���*/
                            else{
                                   fprintf(cfPtr2,"%c",ch1);
                                   ch1=ch2;
                                ch2=fgetc(cfPtr1);
                            }
                     }
                     /*�ر��ļ�*/
                     fclose(cfPtr2);
                     fclose(cfPtr1);
              }
       }
       return 0;
}
