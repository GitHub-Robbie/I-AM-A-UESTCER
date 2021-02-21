/*采用链式存储结构的栈，并动态分配存储空间*/
#pragma once
#define bool int
#define MAXSTACK 100

typedef char StackEntry;

typedef enum Status
{
	success, fail, fatal, range_error, overflow, underflow
}Status;

typedef struct node
{
	StackEntry entry;
	struct node *next;
} StackNode, *StackNodePtr;

typedef struct stack
{
	StackNodePtr top;
} Stack, *StackPtr;

StackNodePtr NewNode(StackEntry item);
Status Stack_Init(StackPtr *s);				//因为要返回创建的栈，所以加*
void Stack_Clear(StackPtr s);
bool Stack_Empty(StackPtr s);
Status Stack_Push(StackPtr s, StackEntry item);
Status Stack_Pop(StackPtr s, StackEntry *item);
Status Stack_Top(StackPtr s, StackEntry *item);
