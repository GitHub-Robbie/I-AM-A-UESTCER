#pragma once
#define ElemType int
#define bool int

typedef enum Status
{
	success, fail, fatal, range_error
}Status;

typedef struct DuLNode {
	ElemType  elem;
	struct DuLNode *prior, *next;
} DuLNode, *Ptr;

typedef Ptr *DuListPtr;

Status List_Init(DuListPtr L);
void List_Destroy(DuListPtr L);
void List_Clear(DuListPtr L);
bool List_Empty(DuListPtr L);
int List_Size(DuListPtr L);
Status List_Retrieval(DuListPtr L, int pos, ElemType *elem);
Status List_Locate(DuListPtr L, ElemType elem, int *pos);
Status List_Insert(DuListPtr L, int pos, ElemType elem);
Status List_Delete(DuListPtr L, int pos);
Status List_Prior(DuListPtr L, int pos, ElemType *elem);
Status List_Next(DuListPtr L, int pos, ElemType *elem);
Status List_Find(DuListPtr L, int pos, Ptr *pAddr);
void List_Print(DuListPtr L);
