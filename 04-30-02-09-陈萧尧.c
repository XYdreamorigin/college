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
		printf("Please input the element of list:");
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

//节点连接 
void Connect_AB(PSTR ListA,PSTR ListB,PSTR previousPtr)//在ListA后面增加ListB，且将原ListB前的previousPtr与 ListB->nextPtr连接起来 
{
	PSTR temp1,temp2;
	//记录节点
	temp1=ListA->nextPtr;
	temp2=ListB->nextPtr;	//增加节点 
	ListA->nextPtr=ListB;
    ListB->nextPtr=temp1; 
	//改变B表指针指向
	previousPtr->nextPtr=temp2;	
}


void Togather_AB(PSTR head_A,PSTR head_B)
{
	PSTR currentPtr=head_B->nextPtr,subhead_A=head_A,subhead_B=head_B,temp1,temp2=head_B;//currentPtr表当前结点  subhead_X表示备份头节点temp1,temp2 算法所需变量，temp2用于储存B表变化后的当前节点的上一个节点 
	PSTR tail_A=head_A->nextPtr;//tail_A A表当前节点 
	PSTR tail_B=NULL;         //tail_B B表当前节点 
	while(currentPtr->data!=-1)
	{
		tail_B=currentPtr;
		temp1=currentPtr;
		currentPtr=currentPtr->nextPtr;
		
		if(tail_B->data<tail_A->data)
			{
				Connect_AB(subhead_A,tail_B,subhead_B);
			}
			
		else
	{
		while(tail_A->data!=-1)
		{
			if(tail_B->data==tail_A->data)
	 	      {temp2=tail_B;}//更新 B表变化后的当前节点的上一个节点 的位置 
			if(tail_B->data>tail_A->data&&tail_A->nextPtr->data==-1)
			{
				Connect_AB(tail_A,tail_B,subhead_B);
			    break;
			}
			if(tail_B->data>tail_A->data&&tail_B->data<tail_A->nextPtr->data)
			{
				Connect_AB(tail_A,tail_B,subhead_B);
			    break;
			}
			tail_A=tail_A->nextPtr;
			subhead_A=subhead_A->nextPtr;
		}
	}
		subhead_A=head_A;
	 	tail_A=head_A->nextPtr;//重置 A表结点 
	 	subhead_B=temp2; //更新B表上一节点 
	}
}

//链表打印 
void Printlist(PSTR head,char x)
{
	PSTR tail=head->nextPtr; //tail为当前节点的的后一个结点 
	
	if(tail->data==-1)
	{printf("There is no item in %c list.\n",x);}
	
	else
	{
		printf("The new list %c:",x) ;
		while(tail->data!=-1)
		{
			printf("%d ",tail->data);
			tail=tail->nextPtr;
		}
		printf("\n ",tail->data);
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
	char A='A',B='B';//字符型变量，分别代表AB表 
	PSTR head_A,head_B;//头节点 
	//链表创建 
	head_A=create_list();
	head_B=create_list();
	//归并 
	Togather_AB(head_A,head_B);
	//链表打印 
	Printlist(head_A,A);
	Printlist(head_B,B);
    //内存释放 
    memory_del(head_A);
	memory_del(head_B); 
	
	return 0;
}
