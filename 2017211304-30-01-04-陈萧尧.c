#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
		int data;   //数据域 
		struct node *nextPtr; //下一个结点的地址 （指针域） 
}STR,*PSTR;
   
PSTR create_list()//建立链表 
{
	PSTR head,currentPtr,previousPtr;// head为头结点的地址，currentPtr为当前结点的地址，previousPtr为上一节点的地址。 
	head=(PSTR)malloc(sizeof(STR));
	if(head==NULL)
	{
		printf("Memory allocation failure");
		exit;                              //判断内存是否分配成功 
	} else                                 //分配成功 
	{
		head->nextPtr=NULL;
		previousPtr=head;
		printf("Please input a series of integers:");
		do
		{
			currentPtr=(PSTR)malloc(sizeof(STR));
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

void find_max_min_sum(PSTR head)  //寻找最大值最小值与计算总和 
{
		int max,min,sum=0; //最大值最小值与和 
		PSTR tail=head->nextPtr;//tail为存放下一节点的地址 
		max=tail->data;
	    min=tail->data;
	    while(tail->data!=-1)
	    {
	    	if(tail->data>max)
	    	{
	    		max=tail->data;
			}
			else if(tail->data<min)
			{
				min=tail->data;
			}
			sum=sum+tail->data;
			tail=tail->nextPtr;
		}
		printf("The maximum,minmum and the total are:%d %d %d\n",max,min,sum);
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
	find_max_min_sum(head);
	memory_del(head);//n内存释放 
	return 0;
}

