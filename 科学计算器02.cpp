#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxnum 2000
struct StackOp//存取运算符的栈
{
    char op[Maxnum];//栈的大小 
    int top;//记录当前栈顶位置 
} stackop;
struct StackNum//存取的操作数的栈
{
    double num[Maxnum];//栈的大小
    int top;//记录当前栈顶位置 
} stacknum;
int GetLevel(char op)//得到运算符的优先等级
{
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op == '^') return 3;
    if(op=='s'||op=='c'||op=='g'||op=='n') return 3;
    return 0;
}
double Add(double a,double b)//加法运算 
{
    return a+b;
}
double Sub(double a,double b)//减法运算
{
    return a-b;
}
double Mul(double a,double b)//乘法运算
{
    return a*b;
}
int Div(double a,double b,double *result)//除法运算  a为除数b为被除数 
{
  //  if(b==0) return 0;
    *result=a/b;
    return 1;
}
double Pow(double a, double b)//幂运算
{
    return pow(a,b);
}
double Sin(double a)//正弦运算
{
    return sin(a);
}
double Cos(double a)//余弦运算
{
    return cos(a);
}
double Log(double a)//以e为底的自然对数运算
{
    return log(a);
}
double Log10(double a)//以10为底的自然对数运算
{
    return log10(a);
}
int Calculate(double a,double b,char op,double *result) //对两个数进行运算
{
    switch(op)
    {
    case '+':
        *result=Add(a,b);
        return 1;
    case '-':
        *result=Sub(a,b);
        return 1;
    case '*':
        *result=Mul(a,b);
        return 1;
    case '/':
        return Div(a,b,result);
    case '^':
        *result = Pow(a, b);
        return 1;
    case 's'://sin
        *result = sin(a);
        return 1;
    case 'c'://cos
        *result = cos(a);
        return 1;
    case 'n'://ln
        *result = log(a);
        return 1;
    case 'g'://log10
        *result = log10(a);
        return 1;
    default:
        return 0;
    }
}
void GetPost(char *str,char *post)
{
	int length=strlen(str);//计算字符串长度 
	int cnt=0;//cnt记录当前数字栈位置 
	int i;
	int ifnum=0;//标记前一个是否为数字，判别符号与数字 
	stackop.top=-1;//
	if(str[length-1]=='=') length--;//去除=号 
	//第一个数是负数的情况处理：先将0置入栈
	if(str[0]=='-')
    {
        post[cnt++]='0';
        post[cnt++]='#';
    }
    for(i=0; i<length; i++)
    {
        if(str[i]=='l') //假如遇到ln,则走一步，遇到log，也走一步 
			i=i+1;
        
        if(str[i]=='o') //遇到log走一步到这里，再走一步则会跳到数字区域 
			i=i+1;
        
        
			
		if(str[i]>='0'&&str[i]<='9'||str[i]=='.')
        {
            post[cnt++]=str[i];
            ifnum=1;
            continue;//进行下一次循环 
        }
        if(ifnum)
        {
            post[cnt++]='#';
            ifnum=0;
        }
        if(str[i]=='('&&str[i+1]=='-')//处理(-情况 
        {
            post[cnt++]='0';
            post[cnt++]='#';
        }
        
        if(str[i]=='(')  stackop.op[++stackop.top]=str[i]; //"("入运算符栈 
        else if(str[i]==')')//直至遇到与其匹配的“）”运算符 
        {
            //将（）里的运算符出栈 
			while(stackop.op[stackop.top]!='(')
            {
                post[cnt++]=stackop.op[stackop.top];
                stackop.top--;
            }
            stackop.top--;// ( 出栈但是不输出 
        }
        //出栈判定 
        //运算符的栈不为空，且当前运算符的优先级<=栈顶运算符的优先级，栈顶运算符出栈
        //此时排除了所有不是sin和cos的情况，所以此时str[i]为 s 或者 c , 
        else if(stackop.top!=-1&&GetLevel(str[i])<=GetLevel(stackop.op[stackop.top]))
        {
            while(stackop.top!=-1&&GetLevel(str[i])<=GetLevel(stackop.op[stackop.top]))
            {
                
				post[cnt++]=stackop.op[stackop.top];
                stackop.top--;
            }
           //出栈完毕，当前运算符入运算栈
            stackop.op[++stackop.top]=str[i];
        }
        //入栈判定 
        //如果当前运算符的优先级>栈顶运算符的优先级,直接入运算栈
        else 
			stackop.op[++stackop.top]=str[i];
        if(str[i]=='s'||str[i]=='c') //遇到sin,cos函数，则走两步进入数字区域 
			i=i+2;
     
    }
    //
    if(ifnum) 
		post[cnt++]='#';
    //数字全部入栈完毕，处理运算栈，如果不是空栈，应该依次出栈 
    while(stackop.top!=-1)
    {
        post[cnt++]=stackop.op[stackop.top];
        stackop.top--;
    }
    post[cnt]='\0';
}
int ResultOp(char *post,double *result)//后缀表达式运算
{
	int length=strlen(post),i;//计算后缀表达式长度 
	double fnum;//小数部分处理变量 
    int num,cnt;//
    stacknum.top=-1;//初始化数栈标识位置变量 
    for(i=0; i<length; i++)
    {
    	//处理数字部分 
    	if(post[i]>='0'&&post[i]<='9')
    	{
    		//初始化小数整数变量 
			num=0;
			cnt=0; 
            fnum=0;
            //处理整数部分
            while(post[i]!='#'&&post[i]!='.')
            {
                num=num*10+post[i]-'0';//字符型转整形 
                i++;//后缀表达式移动到下一个字符 
            }
            //处理小数部分
			if(post[i]=='.')
            {
                i++;//后缀表达式移动到下一个字符
                while(post[i]!='#')
                {
                    fnum=fnum+(post[i]-'0')*1.0/powl(10,++cnt); 
                    i++;
                }
            }
            fnum+=num;//整合小数与整数部分 
            stacknum.num[++stacknum.top]=fnum;//压入数栈 
		}
		//处理运算符部分 
		else
        {
            double a,b,c;
            b=stacknum.num[stacknum.top];
            stacknum.top--;
            if(post[i]=='s'||post[i]=='c'||post[i]=='g'||post[i]=='n') Calculate(b,0,post[i],&c);
            else
            {
            	a=stacknum.num[stacknum.top];
                stacknum.top--;
                Calculate(a,b,post[i],&c);
			}
            
            stacknum.num[++stacknum.top]=c;
        }
    }
    *result=stacknum.num[stacknum.top];
    return 1;
	}
int main()
{
    char str[Maxnum],post[Maxnum];
    double result;
    while(gets(str)!=NULL)
    {
        GetPost(str,post);
        printf("后缀表达式：");
        printf("%s\n",post);
        if(ResultOp(post,&result)) printf("%.2f\n",result);
    }
    return 0;
}
