#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
		int data;   //数据域 
		struct node *nextPtr; //下一个结点的地址 （指针域） 
}STR,*PSTR;

PSTR create_list()//建立链表 
{
	PSTR head,currentPtr,previousPtr,temp;// head为头结点的地址，currentPtr为当前结点的地址，previousPtr为上一节点的地址。 
	head=(PSTR)malloc(sizeof(STR));
	if(head==NULL)
	{
		printf("Memory allocation failure");
		exit;                              //判断内存是否分配成功 
	} else                                 //分配成功 
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
				currentPtr->nextPtr=NULL;//设置链表结束标记 
			 	previousPtr->nextPtr=currentPtr;
			 	previousPtr=currentPtr;
		        }
		}while(currentPtr->data!=-1);
	}
	
	return head;
}

void selection_sort(PSTR head)//冒泡排序
{	
	int i,j,n=0;
	PSTR currentPtr,previousPtr,temp,tail,subhead;
	tail=head->nextPtr ;
		
	while(tail->data!=-1)//算出有效节点个数 
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
	PSTR head;
	head=create_list();
    selection_sort(head);
    Print(head->nextPtr);
	memory_del(head);//n内存释放 
	return 0;
}
