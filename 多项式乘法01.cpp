#include<stdio.h>
#include<stdlib.h>
struct linklist
{
	int time;//���� 
	int num;//ϵ�� 
	struct linklist* next;
};


//������������˵Ľ�������µ������У����������� 
struct linklist* sortlist(struct linklist* A, struct linklist* B) 
{
	struct linklist* curA = A, *curB = B, *C, *temp;
	C= (linklist*)malloc(sizeof(linklist));
	C->next = NULL;
	C->num = 0;
	C->time = 0;

	temp = C;

	while (curA!= NULL)
	{
		temp->time = curA->time + curB->time;
		temp->num = curA->num*curB->num;

		if(curA->next==NULL&&curB->next==NULL)
		{
			temp->next=NULL;
			break;
		}
			
		temp->next = (linklist*)malloc(sizeof(linklist));
		temp->next->num = 0;
		temp->next->time = 0;
		temp = temp->next;
		curB = curB->next;
		if (curB == NULL)
		{
			curB = B;
			curA = curA->next;
			if (curA == NULL)
			{
				break;
			}
		}
	}
	
	struct linklist*pre, *cur;
	int temp_time, temp_num;

	for (pre = C; pre->next != NULL; pre = pre->next)
	{
		
		for (cur = C; cur->next!= NULL; cur = cur->next)
		{
			temp=cur->next;
			if (cur->time<temp->time)
			{
				temp_time = cur->time;
				cur->time = temp->time;
				temp->time = temp_time;//���д�������ʱ�������� 

				temp_num = cur->num;
				cur->num = temp->num;
				temp->num = temp_num;//���д�������ʱ����ϵ�� 
			}
		}	
	}
	return C;
}
//��������Ϊn������ 
struct linklist* creatlist(int n)
{
	struct linklist*head, *temp;
	head = (linklist*)malloc(sizeof(linklist));
	head->num = 0;
	head->time = 0;
	temp = head;
	printf("��ֱ�%d��ϵ���ʹ�����", n);//���� 3(ϵ����5�������� 
	for (int i = 0; i<n; i++)
	{
		scanf("%d %d", &temp->num, &temp->time);
		if (i != n - 1)
		{
			temp->next = (linklist*)malloc(sizeof(linklist));
			temp->next->num = 0;
			temp->next->time = 0;
			temp = temp->next;
		}
		if (i == n - 1)
			temp->next = NULL;

	}
	return head;
}
//�ϲ�ͬ���ɾ�������� 
struct linklist* deletepoint(struct linklist*head)
{
	struct linklist* pre, *cur;
	pre = head;
	cur = pre->next;
	while (cur != NULL)
	{
		if (pre->time == cur->time)
		{
			pre->num = pre->num + cur->num;
			pre->next = cur->next;
			cur = pre->next;
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
	return head;
}
//������ 
int main(void)
{
	struct linklist* creatlist(int n);
	struct linklist* sortlist(struct linklist* A, struct linklist* B);
	struct linklist* deletepoint(struct linklist* head);

	struct linklist* headA, *headB, *headC, *temp;
	headA = (linklist*)malloc(sizeof(linklist));
	headB = (linklist*)malloc(sizeof(linklist));
	headC = (linklist*)malloc(sizeof(linklist));

	int lengthA, lengthB;
	printf("������A��BһԪ����ʽ����ĸ�����");
	scanf("%d %d", &lengthA, &lengthB);
	headA = creatlist(lengthA);
	headB = creatlist(lengthB);

	headC = sortlist(headA, headB);
	headC = deletepoint(headC);

	temp = headC;
	while (temp != NULL)
	{
		if(temp->next==NULL)
		{
			printf("%dX%d", temp->num, temp->time);
			temp = temp->next;
		}
		else
		{
			printf("%dX%d+", temp->num, temp->time);
			temp = temp->next;
		}
	
	}
	return 0;
}

