#include<stdio.h>
#include<string.h>
int main()
{
	char str1[1024], str2[1024];
	char *st1=str1,*st2=str2;
	int flag=0;
	printf("�������һ���ַ���");
	gets(str1);
	printf("������ڶ����ַ���");
	gets(str2);
	for (; *st1 !='\0'; st1++)//'\0' ��ʾASCIIΪ0���ַ�����˼ʹ�ַ�������,st1++��Ϊ�����ַ�������ġ� 
		if (*st1 == *str2)
		{
			for (; (*st2 != '\0') && (*st2 == *(st1+(st2-str2))); st2++);
			if (strlen(str2) == (st2-str2))//strlen�����Ӳ�����ʾ��λ�������ң��ҵ���һ����/0�������ǵ�һ����β 
				flag++;
		}
	printf("�ַ�����%d��", flag);
}
 
