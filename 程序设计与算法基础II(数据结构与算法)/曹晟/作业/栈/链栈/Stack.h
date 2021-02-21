/*������ʽ�洢�ṹ��ջ������̬����洢�ռ�*/
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
Status Stack_Init(StackPtr *s);				//��ΪҪ���ش�����ջ�����Լ�*
void Stack_Clear(StackPtr s);
bool Stack_Empty(StackPtr s);
Status Stack_Push(StackPtr s, StackEntry item);
Status Stack_Pop(StackPtr s, StackEntry *item);
Status Stack_Top(StackPtr s, StackEntry *item);
