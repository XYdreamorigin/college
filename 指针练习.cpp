#include<stdio.h>
#include<string.h>
int main()
{
	char str1[1024], str2[1024];
	char *st1=str1,*st2=str2;
	int flag=0;
	printf("请输入第一个字符串");
	gets(str1);
	printf("请输入第二个字符串");
	gets(str2);
	for (; *st1 !='\0'; st1++)//'\0' 表示ASCII为0的字符，意思使字符串结束,st1++因为数组地址是连续的。 
		if (*st1 == *str2)
		{
			for (; (*st2 != '\0') && (*st2 == *(st1+(st2-str2))); st2++);
			if (strlen(str2) == (st2-str2))//strlen函数从参数表示的位置往后找，找到第一个’/0‘，就是第一个串尾 
				flag++;
		}
	printf("字符串共%d个", flag);
}
 
