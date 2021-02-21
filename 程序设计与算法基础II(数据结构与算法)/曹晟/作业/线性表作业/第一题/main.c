#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#define MAX_LENGTH 100

Status CreateList(LinkListPtr list, ElemType data[], int n)
{
	Status s = fail;
	int i;
	s = List_Init(list);
	if (s == success)
	{
		for (i = 1; i <= n; ++i)
		{
			s = List_Insert(list, i, data[i-1]);
			if (s != success)
				break;
		}
		List_Print(list);
	}
	return s;
}

int main()
{
	Status s;
	int *data;
	int i = 0;
	int length = 0;
	printf("第一题: 删除不带头结点的循环单链表中所有值为X的元素\n");
	printf("Please enter length: ");
	scanf_s("%d", &length);
	data = (int*)malloc((length + 1) * sizeof(int));
	printf("Please enter elements: ");
	for (i = 0; i < length; ++i)
		scanf_s("%d", &data[i]);
	Ptr list = NULL;
	s = CreateList(&list, data, length);
	int x;
	printf("\n");
	printf("Please enter the number you want to delete: ");
	scanf_s("%d", &x);

	Ptr p = (Ptr)malloc(sizeof(Node));
	Ptr q = (Ptr)malloc(sizeof(Node));
	p = list;
	if (p->elem == x)
	{
		q = list;
		p = p->next;
		while (q->next != list)
			q = q->next;
		q->next = p;
		list = p;
	}
	while (p->next != list)
	{
		if (p->next->elem == x)
		{
			q = p->next;
			p->next = q->next;
			free(q);
		}
		else
			p = p->next;
	}
	printf("After deleting: \n");
	List_Print(&list);
	printf("\n");
	system("pause");
	return 0;
}