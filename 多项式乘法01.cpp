#include<stdio.h>
#include<stdlib.h>
struct linklist
{
	int time;//次数 
	int num;//系数 
	struct linklist* next;
};


//将两个链表相乘的结果放入新的链表中，并进行排序； 
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
				temp->time = temp_time;//进行次数排序时交换次数 

				temp_num = cur->num;
				cur->num = temp->num;
				temp->num = temp_num;//进行次数排序时交换系数 
			}
		}	
	}
	return C;
}
//建立长度为n的链表 
struct linklist* creatlist(int n)
{
	struct linklist*head, *temp;
	head = (linklist*)malloc(sizeof(linklist));
	head->num = 0;
	head->time = 0;
	temp = head;
	printf("请分别%d个系数和次数：", n);//例如 3(系数）5（次数） 
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
//合并同类项并删除多余项 
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
//主函数 
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
	printf("请输入A和B一元多项式的项的个数；");
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

