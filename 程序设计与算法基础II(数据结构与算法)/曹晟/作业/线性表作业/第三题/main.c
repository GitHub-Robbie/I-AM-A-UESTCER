#include <stdio.h>
#include <stdlib.h>
#include "DuLIst.h"
#define MAX_LENGTH 100

Status CreateList(DuListPtr list, ElemType data[], int n)
{
	Status s = fail;
	int i;
	s = List_Init(list);
	if (s == success)
	{
		for (i = 1; i <= n; ++i)
		{
			s = List_Insert(list, i, data[i - 1]);
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
	printf("第三题: 逆序输出元素\n");
	printf("Please enter length: ");
	scanf_s("%d", &length);
	data = (int*)malloc((length + 1) * sizeof(int));
	printf("Please enter elements: \n");
	for (i = 0; i < length; ++i)
		scanf_s("%d", &data[i]);
	Ptr list = NULL;
	s = CreateList(&list, data, length);
	printf("\n");
	printf("After reverse: \n");
	Ptr p, q;
    p = (Ptr)malloc(sizeof(DuLNode));
	q = (Ptr)malloc(sizeof(DuLNode));
	p = list;
	q = list;
	int k = 1;
	p = p->prior;
	do
	{
		printf("%d   ", p->elem);
		if (k++ % 10 == 0)
			printf("\n");
		p = p->prior;
	} while (p->next != list);
	system("pause");
	return 0;
}