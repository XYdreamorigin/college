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
				currentPtr->nextPtr=NULL;//�������������� 
			 	previousPtr->nextPtr=currentPtr;
			 	previousPtr=currentPtr;
		        }
		}while(currentPtr->data!=-1);
	}
	return head;
}

//�ڵ����� 
void Connect_AB(PSTR ListA,PSTR ListB,PSTR previousPtr)//��ListA��������ListB���ҽ�ԭListBǰ��previousPtr�� ListB->nextPtr�������� 
{
	PSTR temp1,temp2;
	//��¼�ڵ�
	temp1=ListA->nextPtr;
	temp2=ListB->nextPtr;	//���ӽڵ� 
	ListA->nextPtr=ListB;
    ListB->nextPtr=temp1; 
	//�ı�B��ָ��ָ��
	previousPtr->nextPtr=temp2;	
}


void Togather_AB(PSTR head_A,PSTR head_B)
{
	PSTR currentPtr=head_B->nextPtr,subhead_A=head_A,subhead_B=head_B,temp1,temp2=head_B;//currentPtr��ǰ���  subhead_X��ʾ����ͷ�ڵ�temp1,temp2 �㷨���������temp2���ڴ���B��仯��ĵ�ǰ�ڵ����һ���ڵ� 
	PSTR tail_A=head_A->nextPtr;//tail_A A��ǰ�ڵ� 
	PSTR tail_B=NULL;         //tail_B B��ǰ�ڵ� 
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
	 	      {temp2=tail_B;}//���� B��仯��ĵ�ǰ�ڵ����һ���ڵ� ��λ�� 
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
	 	tail_A=head_A->nextPtr;//���� A���� 
	 	subhead_B=temp2; //����B����һ�ڵ� 
	}
}

//�����ӡ 
void Printlist(PSTR head,char x)
{
	PSTR tail=head->nextPtr; //tailΪ��ǰ�ڵ�ĵĺ�һ����� 
	
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
	char A='A',B='B';//�ַ��ͱ������ֱ����AB�� 
	PSTR head_A,head_B;//ͷ�ڵ� 
	//������ 
	head_A=create_list();
	head_B=create_list();
	//�鲢 
	Togather_AB(head_A,head_B);
	//�����ӡ 
	Printlist(head_A,A);
	Printlist(head_B,B);
    //�ڴ��ͷ� 
    memory_del(head_A);
	memory_del(head_B); 
	
	return 0;
}
