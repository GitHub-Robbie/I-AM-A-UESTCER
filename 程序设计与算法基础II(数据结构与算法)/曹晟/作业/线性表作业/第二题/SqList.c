#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

Status List_Init(SqListPtr L)
{
	Status s = fail;
	if (L != NULL)
	{
		L->elem = (ElemType*)malloc((LIST_INIT_SIZE + 1) * sizeof(ElemType)); //为了保持逻辑储存和物理一致，在第一个位置(下标0)不放置元素
		if (L->elem)
		{
			L->list_size = LIST_INIT_SIZE;
			L->length = 0;
			s = success;
		}
	}
	return s;
}

void List_Destroy(SqListPtr L)
{
	if (L)
	{
		if (L->elem)
		{
			free(L->elem);
			L->elem = NULL;
			L->length = 0;
		}
	}
}

void List_Clear(SqListPtr L)
{
	if (L)
	{
		L->length = 0;
	}
}

bool List_Empty(SqListPtr L)
{
	return (L->length == 0);
}

int List_Size(SqListPtr L)
{
	return L->length;
}

Status List_Retrieval(SqListPtr L, int pos, ElemType *elem)
{
	Status s = range_error;
	if (L)
	{
		if (pos >= 1 && pos <= L->length)
		{
			*elem = L->elem[pos];
			s = success;
		}
	}
	return s;
}

Status List_Locate(SqListPtr L, ElemType elem, int *pos)
{
	Status s = range_error;
	int i = 1;
	if (L)
	{
		for (i = 1; i <= L->length; ++i)
		{
			if (L->elem[i] == elem)
			{
				*pos = i;
				s = success;
				break;
			}
		}
	}
	return s;
}

Status List_Insert(SqListPtr L, int pos, ElemType elem)
{
	Status s = range_error;
	int i;
	if (L)
	{
		if (pos >= 1 && pos <= L->length + 1)
		{
			if (L->length < L->list_size)
			{
				for (i = L->length; i >= pos; --i)
					L->elem[i + 1] = L->elem[i];				//把pos后移过后，i还自减了
				L->elem[i + 1] = elem;
				L->length++;
				s = success;
			}
		}
	}
	return s;
}

Status List_Delete(SqListPtr L, int pos)
{
	Status s = range_error;
	int i;
	if (L)
	{
		if (pos >= 1 && pos <= L->length)
		{
			for (i = pos + 1; i <= L->length; ++i)
				L->elem[i - 1] = L->elem[i];				//覆盖掉原来pos处的值
			L->length--;
			s = success;
		}
	}
	return s;
}

Status List_Prior(SqListPtr L, int pos, ElemType *elem)
{
	Status s = range_error;
	if (L)
	{
		if (pos > 1 && pos <= L->length)
		{
			*elem = L->elem[pos - 1];
			s = success;
		}
	}
	return s;
}

Status List_Next(SqListPtr L, int pos, ElemType *elem)
{
	Status s = range_error;
	if (L)
	{
		if (pos >= 1 && pos < L->length)
		{
			*elem = L->elem[pos + 1];
			s = success;
		}
	}
	return s;
}

void List_Print(SqListPtr L)
{
	int i;
	if (L)
	{
		for (i = 1; i <= L->length; ++i)
		{
			printf("%d   ", L->elem[i]);
			if (i % 10 == 0)
			{
				printf("\n");
			}
		}
	}
}