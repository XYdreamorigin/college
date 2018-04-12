#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
		int data;   //������ 
		struct node *nextPtr; //��һ�����ĵ�ַ ��ָ���� 
}STR,*PSTR;

PSTR create_list()//�������� 
{
	PSTR head,currentPtr,previousPtr,temp;// headΪͷ���ĵ�ַ��currentPtrΪ��ǰ���ĵ�ַ��previousPtrΪ��һ�ڵ�ĵ�ַ�� 
	head=(PSTR)malloc(sizeof(STR));
	if(head==NULL)
	{
		printf("Memory allocation failure");
		exit;                              //�ж��ڴ��Ƿ����ɹ� 
	} else                                 //����ɹ� 
	{
		head->nextPtr=NULL;
		previousPtr=head;
		printf("Please input a series of integers:\n");
		do
		{	currentPtr=(PSTR)malloc(sizeof(STR));
			if(currentPtr==NULL)
	         {
		      printf("Memory allocation failure");
	          exit;                              
	         } else
			    {
			 	scanf("%d",&currentPtr->data);
				currentPtr->nextPtr=NULL;//�������������� 
			 	previousPtr->nextPtr=currentPtr;
			 	previousPtr=currentPtr;
		        }
		}while(currentPtr->data!=-1);
	}
	
	return head;
}

void selection_sort(PSTR head)//ð������
{	
	int i,j,n=0;
	PSTR currentPtr,previousPtr,temp,tail,subhead;
	tail=head->nextPtr ;
		
	while(tail->data!=-1)//�����Ч�ڵ���� 
	{
		n++;
		tail=tail->nextPtr;
	}
	tail=head->nextPtr;
	
	for(i=0;i<n-1;i++)
	{
		subhead=head;
		previousPtr=head->nextPtr ;
		currentPtr=previousPtr->nextPtr ;
		for(j=0;j<n-1-i;j++)
		{
			if(previousPtr->data>currentPtr->data)
			{
				subhead->nextPtr=previousPtr->nextPtr;
				previousPtr->nextPtr=currentPtr->nextPtr;
				currentPtr->nextPtr=previousPtr;
				temp=previousPtr;
				previousPtr=currentPtr;
				currentPtr=temp;
			}
			subhead=subhead->nextPtr;
			currentPtr=currentPtr->nextPtr;
			previousPtr=previousPtr->nextPtr;
		}
	}
 } 
 
void Print(PSTR head)
{
	PSTR tail=head->nextPtr;
	while(tail->data!=-1)
	{
		if(head->nextPtr->data==-1)
		{
			printf("%d\n",head->data);
			head=head->nextPtr ;
			break;
		}
		else
		{
			printf("%d ",head->data);
			head=head->nextPtr;
		}
		
	}
}

void memory_del(PSTR head) //�����ڴ��ͷ� 
{
	PSTR headPtr=head;//headPtrΪ��ǰ����ַ 
	PSTR tempPtr=headPtr;// tempPtr���ڱ�����һ�ڵ�ĵ�ַ 
	while(headPtr!=NULL)
	{
	    tempPtr=headPtr;
		headPtr=headPtr->nextPtr;
		free(tempPtr);
	}
}

int main()//������ 
{
	PSTR head;
	head=create_list();
    selection_sort(head);
    Print(head->nextPtr);
	memory_del(head);//n�ڴ��ͷ� 
	return 0;
}
