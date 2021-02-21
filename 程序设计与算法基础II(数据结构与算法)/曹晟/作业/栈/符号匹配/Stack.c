#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

Status Stack_Init(StackPtr *s)
{
	Status z = fail;
	StackPtr p = (StackPtr)malloc(sizeof(Stack));
	if (p)
	{
		p->top = -1;
		*s = p;
		z = success;
	}
	return z;
}

void Stack_Destroy(StackPtr *s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
		(*s)->top = -1;
	}
}

void Stack_Clear(StackPtr s)
{
	s->top = -1;
}

bool Stack_Empty(StackPtr s)
{
	return (s->top == -1);
}

bool Stack_Full(StackPtr s)
{
	return (s->top > MAXSTACK - 1);
}

Status Stack_Push(StackPtr s, StackEntry item)
{
	Status z = success;
	if (Stack_Full(s))
		s = overflow;
	else
	{
		s->top++;
		s->entry[s->top] = item;
	}
	return z;
}

Status Stack_Pop(StackPtr s, StackEntry *item)
{
	Status z = success;
	if (Stack_Empty(s))
		z = underflow;
	else
	{
		*item = s->entry[s->top];
		s->top--;
	}
	return z;
}

Status Stack_Top(StackPtr s, StackEntry *item)
{
	Status z = success;
	if (Stack_Empty(s))
		z = underflow;
	else
		*item = s->entry[s->top];
	return z;
}