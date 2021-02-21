#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

Status List_Init(LinkListPtr L)
{
	Status s = fail;
	Ptr p;
	if (*L == NULL)
	{
		p = (Ptr)malloc(sizeof(Node));
		if (p == NULL)
			return s;
		*L = p;
		(*L)->next = *L;
		s = success;
	}
	return s;
}

void List_Destroy(LinkListPtr L)
{
	List_Clear(L);
	if (*L)
		*L = NULL;
}

void List_Clear(LinkListPtr L)
{
	Ptr p;
	if (*L)
	{
		p = *L;
		while (p->next=NULL)
		{
			*L = p->next;
			free(p);
			p = *L;
		}
	}
}

bool List_Empty(LinkListPtr L)
{
	return (*L == NULL);
}

int List_Size(LinkListPtr L)
{
	int len = 1;
	Ptr p = *L;
	while (p->next!=*L)
	{
		len++;
		p = p->next;
	}
	return len;
}

Status List_Retrieval(LinkListPtr L, int pos, ElemType *elem)
{
	Status s=range_error;
	Ptr p = *L;
	int i = 1;
	while (p && i < pos)
	{
		++i;
		p = p->next;
	}
	if (p && i == pos)
	{
		*elem = p->elem;
		s = success;
	}
	return s;
}

Status List_Locate(LinkListPtr L, ElemType elem, int *pos)
{
	Status s = fail;
	int i = 1;
	Ptr p = *L;
	while (p)
	{
		if (p->elem == elem)
		{
			s = success;
			*pos = i;
			break;
		}
		++i;
		p = p->next;
	}
	return s;
}

Status List_Find(LinkListPtr L, int pos, Ptr *pAddr)
{
	Status s = range_error;
	Ptr p = *L;
	int i = 1;
	if (pos == 1)
	{

	}
	while (p && i < pos)
	{
		++i;
		p = p->next;
	}
	if (p && i == pos)
	{
		*pAddr = p;
		s = success;
	}
	return s;
}

Status List_Insert(LinkListPtr L, int pos, ElemType elem)
{
	
	int i = 1;
	Status s = fail;
	Ptr p, q = NULL;
	if (pos > 1)
	{
		s = List_Find(L, pos - 1, &q);
		if (s == success)
		{
			p = (Ptr)malloc(sizeof(Node));
			if (p)
			{
				p->elem = elem;
				p->next = q->next;
				q->next = p;
				s = success;
			}
		}
	}
	else
	{
		if (*L)
		{
			(*L)->elem = elem;
			s = success;
		}
	}
	return s;
}

Status List_Delete(LinkListPtr L, int pos)
{
	Status s = fail;
	int i = 1;
	Ptr p, q = NULL;
	s = List_Find(L, pos - 1, &q);
	if (s == success)
	{
		p = q->next;
		if (p)
		{
			q->next = p->next;
			free(p);
			p = NULL;
		}
	}
	return s;
}

Status List_Prior(LinkListPtr L, int pos, ElemType *elem)
{
	Status s;
	Ptr q = NULL;
	s = List_Find(L, pos - 1, &q);
	if (s == success)
	{
		*elem = q->elem;
		s = success;
	}
	return s;
}

Status List_Next(LinkListPtr L, int pos, ElemType *elem)
{
	Status s;
	Ptr q = NULL;
	s = List_Find(L, pos, &q);
	if (s == success)
	{
		if (q->next)
		{
			*elem = q->next->elem;
			s = success;
		}
		else
			s = fail;
	}
	return s;
}

void List_Print(LinkListPtr L)
{
	Ptr p = *L;
	int i = 1;
	while (p->next != *L)
	{
		printf("%d   ", p->elem);
		p = p->next;
		if (i++ % 10 == 0)				//注意是i++不是++i，在执行完if中的判断之后，i还要自加1；
			printf("\n");
	}
	if(p->next == *L)
		printf("%d   ", p->elem);
}
