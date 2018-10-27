#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxnum 2000
struct StackOp//��ȡ�������ջ
{
    char op[Maxnum];//ջ�Ĵ�С 
    int top;//��¼��ǰջ��λ�� 
} stackop;
struct StackNum//��ȡ�Ĳ�������ջ
{
    double num[Maxnum];//ջ�Ĵ�С
    int top;//��¼��ǰջ��λ�� 
} stacknum;
int GetLevel(char op)//�õ�����������ȵȼ�
{
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op == '^') return 3;
    if(op=='s'||op=='c'||op=='g'||op=='n') return 3;
    return 0;
}
double Add(double a,double b)//�ӷ����� 
{
    return a+b;
}
double Sub(double a,double b)//��������
{
    return a-b;
}
double Mul(double a,double b)//�˷�����
{
    return a*b;
}
int Div(double a,double b,double *result)//��������  aΪ����bΪ������ 
{
  //  if(b==0) return 0;
    *result=a/b;
    return 1;
}
double Pow(double a, double b)//������
{
    return pow(a,b);
}
double Sin(double a)//��������
{
    return sin(a);
}
double Cos(double a)//��������
{
    return cos(a);
}
double Log(double a)//��eΪ�׵���Ȼ��������
{
    return log(a);
}
double Log10(double a)//��10Ϊ�׵���Ȼ��������
{
    return log10(a);
}
int Calculate(double a,double b,char op,double *result) //����������������
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
	int length=strlen(str);//�����ַ������� 
	int cnt=0;//cnt��¼��ǰ����ջλ�� 
	int i;
	int ifnum=0;//���ǰһ���Ƿ�Ϊ���֣��б���������� 
	stackop.top=-1;//
	if(str[length-1]=='=') length--;//ȥ��=�� 
	//��һ�����Ǹ�������������Ƚ�0����ջ
	if(str[0]=='-')
    {
        post[cnt++]='0';
        post[cnt++]='#';
    }
    for(i=0; i<length; i++)
    {
        if(str[i]=='l') //��������ln,����һ��������log��Ҳ��һ�� 
			i=i+1;
        
        if(str[i]=='o') //����log��һ�����������һ����������������� 
			i=i+1;
        
        
			
		if(str[i]>='0'&&str[i]<='9'||str[i]=='.')
        {
            post[cnt++]=str[i];
            ifnum=1;
            continue;//������һ��ѭ�� 
        }
        if(ifnum)
        {
            post[cnt++]='#';
            ifnum=0;
        }
        if(str[i]=='('&&str[i+1]=='-')//����(-��� 
        {
            post[cnt++]='0';
            post[cnt++]='#';
        }
        
        if(str[i]=='(')  stackop.op[++stackop.top]=str[i]; //"("�������ջ 
        else if(str[i]==')')//ֱ����������ƥ��ġ���������� 
        {
            //����������������ջ 
			while(stackop.op[stackop.top]!='(')
            {
                post[cnt++]=stackop.op[stackop.top];
                stackop.top--;
            }
            stackop.top--;// ( ��ջ���ǲ���� 
        }
        //��ջ�ж� 
        //�������ջ��Ϊ�գ��ҵ�ǰ����������ȼ�<=ջ������������ȼ���ջ���������ջ
        //��ʱ�ų������в���sin��cos����������Դ�ʱstr[i]Ϊ s ���� c , 
        else if(stackop.top!=-1&&GetLevel(str[i])<=GetLevel(stackop.op[stackop.top]))
        {
            while(stackop.top!=-1&&GetLevel(str[i])<=GetLevel(stackop.op[stackop.top]))
            {
                
				post[cnt++]=stackop.op[stackop.top];
                stackop.top--;
            }
           //��ջ��ϣ���ǰ�����������ջ
            stackop.op[++stackop.top]=str[i];
        }
        //��ջ�ж� 
        //�����ǰ����������ȼ�>ջ������������ȼ�,ֱ��������ջ
        else 
			stackop.op[++stackop.top]=str[i];
        if(str[i]=='s'||str[i]=='c') //����sin,cos�������������������������� 
			i=i+2;
     
    }
    //
    if(ifnum) 
		post[cnt++]='#';
    //����ȫ����ջ��ϣ���������ջ��������ǿ�ջ��Ӧ�����γ�ջ 
    while(stackop.top!=-1)
    {
        post[cnt++]=stackop.op[stackop.top];
        stackop.top--;
    }
    post[cnt]='\0';
}
int ResultOp(char *post,double *result)//��׺���ʽ����
{
	int length=strlen(post),i;//�����׺���ʽ���� 
	double fnum;//С�����ִ������ 
    int num,cnt;//
    stacknum.top=-1;//��ʼ����ջ��ʶλ�ñ��� 
    for(i=0; i<length; i++)
    {
    	//�������ֲ��� 
    	if(post[i]>='0'&&post[i]<='9')
    	{
    		//��ʼ��С���������� 
			num=0;
			cnt=0; 
            fnum=0;
            //������������
            while(post[i]!='#'&&post[i]!='.')
            {
                num=num*10+post[i]-'0';//�ַ���ת���� 
                i++;//��׺���ʽ�ƶ�����һ���ַ� 
            }
            //����С������
			if(post[i]=='.')
            {
                i++;//��׺���ʽ�ƶ�����һ���ַ�
                while(post[i]!='#')
                {
                    fnum=fnum+(post[i]-'0')*1.0/powl(10,++cnt); 
                    i++;
                }
            }
            fnum+=num;//����С������������ 
            stacknum.num[++stacknum.top]=fnum;//ѹ����ջ 
		}
		//������������� 
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
        printf("��׺���ʽ��");
        printf("%s\n",post);
        if(ResultOp(post,&result)) printf("%.2f\n",result);
    }
    return 0;
}
