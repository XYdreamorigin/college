#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10


typedef struct Stack///��ջ�Ĵ洢�ṹ 
{
	char data;
	struct Stack *next;
}stack;

int InitStack(stack* S)//��ջ�ĳ�ʼ��
{
	//����һ����ջ��ջ��ָ���ÿ�
	S=NULL;
	return 1;
 } 
 
int Push(stack* S,char e)
{
	//��ջ������Ԫ��e
	stack* p=(stack* )malloc(sizeof(stack));
	p->data=e;
	p->next=S;
	S=p;
	return 1; 
}

char Pop(stack* S)
{
	//ɾ��S��ջ��Ԫ�أ���e������ֵ
	if(S==NULL)
		return 'F';   //ջ��
	char e;
	stack* p=(stack* )malloc(sizeof(stack));
	e=S->data;			//��ջ��Ԫ�ظ�ֵ��e 
	p=S;				//��p��ʱ����ջ��Ԫ�ؿռ䣬�Ա��ͷ� 
	S=S->next;			//�޸�ջ��ָ�� 
	delete p;			//�ͷ�ԭ��ջ��Ԫ�صĿռ� 
	return e; 
}

bool Full(stack S)  //�ж�ջ�еĸ����Ƿ����� 
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

bool Empty(stack* S)  //�ж�ջ�Ƿ�Ϊ�� 
{
	if(S==NULL)
		return 1;
	else 
		return 0;
}


/*int InitQueue(void)
{
	stack* S1,*S2;			//��������ջ 
	InitStack(S1);
	InitStack(S2);
	if(S1==NULL||S2==NULL)
		return 0;
	else
		return 1; 
}

int enQueue(stack* S1,stack* S2,char e)//�������
{
	char temp; 
	if(Full(S1)==1||Full(S2)==1)
	 	return 0;			//��������������� 
	else
	{
		if(Empty(S1)==1)		//���S1Ϊ�� 
		{
			while(S2!=NULL)
			{
				Pop(S2,temp);		//ɾ��S2ջ��Ԫ��temp,��������ֵ 
				Push(S1,temp);		//��Ԫ��temp����S1�� 
			}	
		}
		else
		{
			Push(S1,e);
			return 1;	
		}
	}
	Push(S1,e);	  //��Ԫ��e������� 
	return 1;
}

int deQueue(stack* S1,stack* S2,char e)
{
	char temp;
	if(Empty(S1)==1&&Empty(S2)==1)
		return 0;   //�����ѿղ��ܳ���
	else
	{
		if(Empty(S2)==1)
		{
			while(S1!=NULL)
			{
				Pop(S1,temp);		//ɾ��S1ջ��Ԫ��temp,��������ֵ 
				Push(S2,temp);		//��Ԫ��temp����S2�� 
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
		printf("�����뽫Ҫִ�еĲ���:\n");
		printf("0 ����\n1 ���\n2 ����\n3 �����Ƿ�������\n4 �����Ƿ�Ϊ��\n");
		scanf("%d",&choose);
		if(choose==0)
			break;
		else if(choose==1)
		{
			printf("�����뽫Ҫ������е��ַ�:\n");
			getchar();
			scanf("%c",&str);
			if(Full_queue(S1,S2)==1)
				printf("��������!�޷���ӣ�"); 
			else
			{
				if(Empty(&S1)==1)		//���S1Ϊ�� 
				{
					while(&S2!=NULL)
					{
											 //ɾ��S2ջ��Ԫ��temp,��������ֵ 
						Push(&S1,Pop(&S2));		//��Ԫ��temp����S1�� 
					}	
				}
				else
				{
					Push(&S1,str);	
				}
			}
			Push(&S1,str);	  //��Ԫ��e������� 

		}
		//else if	
	} 
	return 0;
}




