#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

Status CreateList(SqListPtr list, ElemType data[], int n)
{
	Status s = fail;
	int i;
	s = List_Init(list);
	if (s == success)
	{
		for (i = 1; i <= n; ++i)
		{
			s = List_Insert(list, i, data[i]);
			if (s != success)
				break;
		}
		List_Print(list);
	}
	return s;
}

int main()
{
	printf("第二题: 删除第j个元素起的k个元素\n");
	Status s = fail;
	SqList list;
	int i, length, j, k, x;
	int *data;
	printf("Please enter the length of this sequence list: ");
	scanf_s("%d", &length);
	data = (int*)malloc((length + 1) * sizeof(int));
	printf("The elements of this sequence list: \n");
	for (i = 1; i <= length; i++)
		scanf_s("%d", &data[i]);
	s = CreateList(&list, data, length);
	if (s == success)
	{
		printf("\n");
		printf("Please enter j: ");
		scanf_s("%d", &j);
		printf("Please enter k: ");
		scanf_s("%d", &k);
		for (x = 1; x <= k; x++)
			s = List_Delete(&list, j);
	}
	if (s == success)
	{
		printf("After deleting: \n");
		List_Print(&list);
		printf("\n");
		printf("Deleted!\n");
	}
	else
	{
		printf("\n");
		printf("Fail!\n");
	}
	system("pause");
	return 0;
}