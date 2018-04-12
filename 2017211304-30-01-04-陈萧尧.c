#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
		int data;   //������ 
		struct node *nextPtr; //��һ�����ĵ�ַ ��ָ���� 
}STR,*PSTR;
   
PSTR create_list()//�������� 
{
	PSTR head,currentPtr,previousPtr;// headΪͷ���ĵ�ַ��currentPtrΪ��ǰ���ĵ�ַ��previousPtrΪ��һ�ڵ�ĵ�ַ�� 
	head=(PSTR)malloc(sizeof(STR));
	if(head==NULL)
	{
		printf("Memory allocation failure");
		exit;                              //�ж��ڴ��Ƿ����ɹ� 
	} else                                 //����ɹ� 
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
				currentPtr->nextPtr=NULL;//�������������� 
			 	previousPtr->nextPtr=currentPtr;
			 	previousPtr=currentPtr;
		        }
		}while(currentPtr->data!=-1);
	}
	return head;
}

void find_max_min_sum(PSTR head)  //Ѱ�����ֵ��Сֵ������ܺ� 
{
		int max,min,sum=0; //���ֵ��Сֵ��� 
		PSTR tail=head->nextPtr;//tailΪ�����һ�ڵ�ĵ�ַ 
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
	find_max_min_sum(head);
	memory_del(head);//n�ڴ��ͷ� 
	return 0;
}

