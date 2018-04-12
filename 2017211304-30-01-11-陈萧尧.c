#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
		int data;   //������ 
		struct node *nextPtr; //��һ�����ĵ�ַ ��ָ���� 
}STR,*PSTR;

PSTR create_list()//�������� 
{
	PSTR head,currentPtr,previousPtr;// headΪͷ���ĵ�ַ��p1Ϊ��ǰ���ĵ�ַ��p2Ϊ��һ�ڵ�ĵ�ַ�� 
	head=(PSTR)malloc(sizeof(STR));
	if(head==NULL)
	{
		printf("Memory allocation failure");
		exit;                              //�ж��ڴ��Ƿ����ɹ� 
	} else                                 //����ɹ� 
	{
		head->nextPtr=NULL;
		previousPtr=head;
		printf("Please input a list A");
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



void list_patch(PSTR head3,PSTR head4)
{ 	
	PSTR head1=head3->nextPtr;
	PSTR head2=head4->nextPtr;
	int judge=0;
	while(head2->data!=head1->data)
    {	
		head1=head1->nextPtr;
		if(head1->data==-1)
	{break;
		}	
	}
	while(head1->data==head2->data)
	{
		head1=head1->nextPtr;
		head2=head2->nextPtr;
		if(head2->data==-1)
		{
			judge=1;
			break;
		}
	}
	if(judge==0)
	printf("listB is not the sub sequence of listA");
	else
	printf("listB is the sub sequence of listA");
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
	PSTR head1;
	PSTR head2;
	head1=create_list();
	head2=create_list();
    list_patch(head1,head2);
	memory_del(head1);//n�ڴ��ͷ� 
	memory_del(head2);
	return 0;
}







