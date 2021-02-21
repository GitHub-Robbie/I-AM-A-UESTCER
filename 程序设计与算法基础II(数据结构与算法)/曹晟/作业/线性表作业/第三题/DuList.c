#include <stdio.h>
#include <stdlib.h>
#include "DuLIst.h"

Status List_Init(DuListPtr L)
{
	Status s = fail;
	Ptr p;
	p = (Ptr)malloc(sizeof(DuLNode));
	*L = p;
	p->prior = *L;
	p->next = *L;
	s = success;
	return s;
}

void List_Destroy(DuListPtr L)
{
	List_Clear(L);
	Ptr p = NULL;
	if (p->prior == NULL && p->next == NULL)
		*L = NULL;
}

void List_Clear(DuListPtr L)
{
	Ptr p;
	p = *L;
	while (p->prior != NULL || p->next != NULL)
	{
		p->prior->next = p->next;
		p->next->prior = p->prior;
		free(p);
	}
}

bool List_Empty(DuListPtr L)
{
	return((*L)->prior == NULL && (*L)->next == NULL);
}

int List_Size(DuListPtr L)
{
	Ptr p;
	p = *L;
	int len = 1;
	if (p->next != *L)
	{
		p = p->next;
		len++;
	}
}

Status List_Retrieval(DuListPtr L, int pos, ElemType *elem)
{
	Status s = range_error;
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

Status List_Locate(DuListPtr L, ElemType elem, int *pos)
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

Status List_Insert(DuListPtr L, int pos, ElemType elem)
{
	int i = 1;
	Status s = fail;
	Ptr p, q = NULL;
	if (pos > 1)
	{
		if ((*L)->next == (*L) && (*L)->prior == (*L))
		{
			if (s != success)
			{
				p = (Ptr)malloc(sizeof(DuLNode));
				p->elem = elem;
				(*L)->next = p;
				(*L)->prior = p;
				p->next = (*L);
				p->prior = (*L);
				s = success;
			}
		}
		else
		{
			s = List_Find(L, pos - 1, &q);
			if (s == success)
			{
				p = (Ptr)malloc(sizeof(DuLNode));
				if (p)
				{
					p->elem = elem;
					q->next = p;
					p->prior = q;
					p->next = *L;
					(*L)->prior = p;
					s = success;
				}
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

Status List_Delete(DuListPtr L, int pos)
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

Status List_Prior(DuListPtr L, int pos, ElemType *elem)
{
	Status s;
	Ptr q = NULL;
	s = List_Find(L, pos, &q);
	if (s == success)
	{
		*elem = q->prior->elem;
		s = success;
	}
	return s;
}

Status List_Next(DuListPtr L, int pos, ElemType *elem)
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

Status List_Find(DuListPtr L, int pos, Ptr *pAddr)
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

void List_Print(DuListPtr L)
{
	Ptr p = *L;
	int i = 1;
	while (p->next != *L)
	{
		printf("%d   ", p->elem);
		p = p->next;
		if (i++ % 10 == 0)
			printf("\n");
	}
	if (p->next == *L)
		printf("%d  ", p->elem);
}