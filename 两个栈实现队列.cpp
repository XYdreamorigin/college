#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10


typedef struct Stack///链栈的存储结构 
{
	char data;
	struct Stack *next;
}stack;

int InitStack(stack* S)//链栈的初始化
{
	//构造一个空栈，栈顶指针置空
	S=NULL;
	return 1;
 } 
 
int Push(stack* S,char e)
{
	//在栈顶插入元素e
	stack* p=(stack* )malloc(sizeof(stack));
	p->data=e;
	p->next=S;
	S=p;
	return 1; 
}

char Pop(stack* S)
{
	//删除S的栈顶元素，用e返回其值
	if(S==NULL)
		return 'F';   //栈空
	char e;
	stack* p=(stack* )malloc(sizeof(stack));
	e=S->data;			//将栈顶元素赋值给e 
	p=S;				//用p临时保存栈顶元素空间，以备释放 
	S=S->next;			//修改栈顶指针 
	delete p;			//释放原来栈顶元素的空间 
	return e; 
}

bool Full(stack S)  //判断栈中的个数是否已满 
{
	int size=0;
	stack* head;
	head=&S;
	while(head!=NULL)
	{	
		size++;
		head=head->next;
	}
	if(size>=MAX_SIZE)
		return 1;
	else
		return 0;
} 

bool Empty(stack* S)  //判断栈是否为空 
{
	if(S==NULL)
		return 1;
	else 
		return 0;
}


/*int InitQueue(void)
{
	stack* S1,*S2;			//建立两个栈 
	InitStack(S1);
	InitStack(S2);
	if(S1==NULL||S2==NULL)
		return 0;
	else
		return 1; 
}

int enQueue(stack* S1,stack* S2,char e)//进入队列
{
	char temp; 
	if(Full(S1)==1||Full(S2)==1)
	 	return 0;			//队列已满不能入队 
	else
	{
		if(Empty(S1)==1)		//如果S1为空 
		{
			while(S2!=NULL)
			{
				Pop(S2,temp);		//删除S2栈顶元素temp,并返回其值 
				Push(S1,temp);		//将元素temp放入S1中 
			}	
		}
		else
		{
			Push(S1,e);
			return 1;	
		}
	}
	Push(S1,e);	  //将元素e放入队列 
	return 1;
}

int deQueue(stack* S1,stack* S2,char e)
{
	char temp;
	if(Empty(S1)==1&&Empty(S2)==1)
		return 0;   //队列已空不能出队
	else
	{
		if(Empty(S2)==1)
		{
			while(S1!=NULL)
			{
				Pop(S1,temp);		//删除S1栈顶元素temp,并返回其值 
				Push(S2,temp);		//将元素temp放入S2中 
			}
		}
		else
		{
			Push(S2,e);
			return 1;
		}
	}
	Push(S2,e);
	return 1;
}
*/
bool Full_queue(stack S1,stack S2)
{
	return Full(S1)||Full(S2);
}
/*
bool Empty_queue(stack* S1,stack* S2)
{
	return Empty(S1)||Empty(S2);
}*/

int main(void)
{	
	stack S1,S2;
	InitStack(&S1);
	InitStack(&S2);
	int choose;
	char str; 
	while(1)
	{
		printf("请输入将要执行的操作:\n");
		printf("0 结束\n1 入队\n2 出队\n3 队列是否已满？\n4 队列是否为空\n");
		scanf("%d",&choose);
		if(choose==0)
			break;
		else if(choose==1)
		{
			printf("请输入将要进入队列的字符:\n");
			getchar();
			scanf("%c",&str);
			if(Full_queue(S1,S2)==1)
				printf("队列已满!无法入队！"); 
			else
			{
				if(Empty(&S1)==1)		//如果S1为空 
				{
					while(&S2!=NULL)
					{
											 //删除S2栈顶元素temp,并返回其值 
						Push(&S1,Pop(&S2));		//将元素temp放入S1中 
					}	
				}
				else
				{
					Push(&S1,str);	
				}
			}
			Push(&S1,str);	  //将元素e放入队列 

		}
		//else if	
	} 
	return 0;
}




