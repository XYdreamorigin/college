#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
		int data;   //数据域 
		struct node *nextPtr; //下一个结点的地址 （指针域） 
}STR,*PSTR;

PSTR create_list()//建立链表 
{
	PSTR head,currentPtr,previousPtr;// head为头结点的地址，p1为当前结点的地址，p2为上一节点的地址。 
	head=(PSTR)malloc(sizeof(STR));
	if(head==NULL)
	{
		printf("Memory allocation failure");
		exit;                              //判断内存是否分配成功 
	} else                                 //分配成功 
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
				currentPtr->nextPtr=NULL;//设置链表结束标记 
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



void memory_del(PSTR head) //链表内存释放 
{
	PSTR headPtr=head;//headPtr为当前结点地址 
	PSTR tempPtr=headPtr;// tempPtr用于保存下一节点的地址 
	while(headPtr!=NULL)
	{
	    tempPtr=headPtr;
		headPtr=headPtr->nextPtr;
		free(tempPtr);
	}
}

int main()//主函数 
{
	PSTR head1;
	PSTR head2;
	head1=create_list();
	head2=create_list();
    list_patch(head1,head2);
	memory_del(head1);//n内存释放 
	memory_del(head2);
	return 0;
}







