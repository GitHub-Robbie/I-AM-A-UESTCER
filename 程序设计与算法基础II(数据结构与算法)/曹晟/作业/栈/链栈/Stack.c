#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

StackNodePtr NewNode(StackEntry item)
{
	StackNodePtr np;
	np = (StackNode*)malloc(sizeof(StackNode));
	if (np == NULL)
	{
		printf("Exhausted memory.\n");
		exit(0);
	}
	else
	{
		np->entry = item;
		np->next = NULL;
	}
	return np;
}

Status Stack_Init(StackPtr *s)
{
	StackNodePtr np;
	Status outcome = fail;
	*s = (StackPtr)malloc(sizeof(Stack));
	np = (StackNodePtr)malloc(sizeof(StackNode));
	if (np == NULL)
	{
		printf("Exhausted memory.\n");
		outcome = fatal;
	}
	else
	{
		np->next = NULL;
		(*s)->top = np;
		outcome = success;
	}
	return outcome;
}

void Stack_Clear(StackPtr s)
{
	StackNodePtr np = s->top->next;
	while (np)
	{
		s->top->next = np->next;
		free(np);
		np = s->top->next;
	}
	s->top->next = NULL;
}

bool Stack_Empty(StackPtr s)
{
	return(s->top->next == NULL);
}

Status Stack_Push(StackPtr s, StackEntry item)
{
	Status outcome = success;
	StackNodePtr np;
	np = (StackNodePtr)malloc(sizeof(StackNode));
	np->entry = item;
	if (np == NULL)
		outcome = overflow;
	else if (s->top->next == NULL)
	{
		np->next == NULL;
		s->top->next = np;
	}
	else
	{
		np->next = s->top->next;
		s->top->next = np;
	}
	return outcome;
}

Status Stack_Pop(StackPtr s, StackEntry *item)
{
	Status outcome = success;
	if (Stack_Empty(s))
		outcome = overflow;
	else
	{
		StackNodePtr np = s->top->next;
		s->top->next = np->next;
		*item = np->entry;
		free(np);
	}
	return outcome;
}

Status Stack_Top(StackPtr s, StackEntry *item)
{
	Status outcome = success;
	if (Stack_Empty(s))
		outcome = underflow;
	else
		*item = s->top->next->entry;
	return outcome;
}