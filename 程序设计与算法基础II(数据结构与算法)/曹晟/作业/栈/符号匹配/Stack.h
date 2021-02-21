/*采用顺序存储结构的栈，并动态分配存储空间*/
#pragma once
#define bool int
#define MAXSTACK 100

typedef char StackEntry;

typedef enum Status
{
	success, fail, fatal, range_error, overflow, underflow
}Status;

typedef struct stack
{
	int top;
	StackEntry entry[MAXSTACK];
} Stack, *StackPtr;

Status Stack_Init(StackPtr *s);
void Stack_Destroy(StackPtr *s);
void Stack_Clear(StackPtr s);
bool Stack_Empty(StackPtr s);
bool Stack_Full(StackPtr s);
Status Stack_Push(StackPtr s, StackEntry item);
Status Stack_Pop(StackPtr s, StackEntry *item);
Status Stack_Top(StackPtr s, StackEntry *item);
