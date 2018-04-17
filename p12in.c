#include<stdio.h>
//将一个.c文件1复制到另一个文件2中，要求过滤掉文件1中的注释。
//注释类型：以注释符开头或者其中的注释。用一个函数完成该功能。
main()
{
       /*cfPtr1是指向被复制文件的指针，cfPtr2是复制出的文件*/
       FILE *cfPtr1,*cfPtr2;
       /*ch1,ch2是存储当前字符的变量*/
       char ch1,ch2;
       /*打开两个文件*/
       if((cfPtr1=fopen("ceshier.c","r"))==NULL)
              printf("FILE ceshier.c count not be opened\n");
       else{
              if((cfPtr2=fopen("clinet2.c","w"))==NULL)
                     printf("FILE clinet2.c count not be opened\n");
              else{
                     fscanf(cfPtr1,"%c%c",&ch1,&ch2);
                     while(!feof(cfPtr1)){
                            /*遇到注释符时，跳过同一横中在它之后的字符*/
                            if(ch1=='/'&&ch2=='/'){
                                   while(ch1!='\n'){
                                          ch1=fgetc(cfPtr1);
                                   }
                                   fprintf(cfPtr2,"\n");
                                   fscanf(cfPtr1,"%c%c",&ch1,&ch2);
                            }
                            /*遇到注释符时，跳过其中的内容*/
                            else if(ch1=='/'&&ch2=='*'){
                                   while(ch1!='*'||ch2!='/'){
                                          ch1=ch2;
                                          ch2=fgetc(cfPtr1);
                                   }
                                   fscanf(cfPtr1,"%c%c",&ch1,&ch2);
                            }
                            /*将cfPtr1指向的文件中的内容逐字符复制cfPtr2指向的文件中*/
                            else{
                                   fprintf(cfPtr2,"%c",ch1);
                                   ch1=ch2;
                                ch2=fgetc(cfPtr1);
                            }
                     }
                     /*关闭文件*/
                     fclose(cfPtr2);
                     fclose(cfPtr1);
              }
       }
       return 0;
}
