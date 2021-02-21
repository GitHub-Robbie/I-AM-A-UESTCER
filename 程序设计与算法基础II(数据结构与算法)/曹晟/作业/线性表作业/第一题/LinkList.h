#pragma once
#define ElemType int
#define bool int

typedef enum Status
{
	success, fail, fatal, range_error
}Status;

typedef struct Node
{
	ElemType elem;
	struct Node *next;
}Node, *Ptr;

typedef Ptr *LinkListPtr;

Status List_Init(LinkListPtr L);
void List_Destroy(LinkListPtr L);
void List_Clear(LinkListPtr L);
bool List_Empty(LinkListPtr L);
int List_Size(LinkListPtr L);
Status List_Retrieval(LinkListPtr L, int pos, ElemType *elem);
Status List_Locate(LinkListPtr L, ElemType elem, int *pos);
Status List_Insert(LinkListPtr L, int pos, ElemType elem);
Status List_Delete(LinkListPtr L, int pos);
Status List_Prior(LinkListPtr L, int pos, ElemType *elem);
Status List_Next(LinkListPtr L, int pos, ElemType *elem);
Status List_Find(LinkListPtr L, int pos, Ptr pAddr);
void List_Print(LinkListPtr L);
