#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Status Queue_Init(QueuePtr *q)
{
	Status outcome = fatal;
	*q = (QueuePtr)malloc(sizeof(Queue));
	QueueNodePtr ptr = (QueueNodePtr)malloc(sizeof(QueueNode));
	if (ptr)
	{
		(*q)->front = (*q)->rear = ptr;
		ptr->next = NULL;
		outcome = success;
	}
	return outcome;
}

bool Queue_Empty(QueuePtr q)
{
	return(q->front->next == NULL && q->rear->next == NULL);
}

Status Queue_EnQueue(QueuePtr q, QueueEntry item)
{
	Status outcome = success;
	QueueNodePtr p;
	p = (QueueNodePtr)malloc(sizeof(QueueNode));
	if (p == NULL)
	{
		outcome = overflow;
		return outcome;
	}
	p->entry = item;
	p->next = NULL;
	if (Queue_Empty(q))		//书上错了这里；注意分两种情况：空队入队和非空队入队
	{
		q->front->next = p;
		q->rear = p;
	}
	else
	{
		q->front->next = p;
		p->next = q->rear;
		q->rear = p;
	}
}

Status Queue_DeQueue(QueuePtr q, QueueEntry *item)
{
	Status outcome = success;
	QueueNodePtr p;
	p = (QueueNodePtr)malloc(sizeof(QueueNode));
	if (Queue_Empty(q))
	{
		outcome = underflow;
		return outcome;
	}
	p = q->front->next;
	*item = p->entry;
	q->front->next = p->next;
	q->rear = q->front;
	if (q->front == p)
	{
		q->rear = q->front;
		q->front->next = NULL;
		free(p);
	}
	return outcome;
}

Status Queue_Front(QueuePtr q, QueueEntry *item)
{
	Status outcome = success;
	if (Queue_Empty(q))
	{
		outcome = underflow;
		return outcome;
	}
	*item = q->front->next->entry;
	return outcome;
}