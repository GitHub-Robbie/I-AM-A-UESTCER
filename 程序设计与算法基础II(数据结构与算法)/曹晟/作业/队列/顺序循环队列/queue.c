#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Status Queue_Init(QueuePtr *q)
{
	Status outcome = fatal;
	QueuePtr queueptr = (QueuePtr)malloc(sizeof(Queue));
	if (queueptr)
	{
		queueptr->front = queueptr->rear = -1;
		*q = queueptr;
		outcome = success;
	}
	return outcome;
}

void Queue_Destroy(QueuePtr *q)
{
	if (*q)
	{
		free(*q);
		*q = NULL;
	}
}

void Queue_Clear(QueuePtr q)
{
	q->front = q->rear = -1;
}

bool Queue_Empty(QueuePtr q)
{
	return(q->front == q->rear);
}

bool Queue_Full(QueuePtr q)
{
	return((q->rear + 1) % MAXQUEUE == q->front);		//少用一个数据空间，当数组只剩1个单元时认为队满；
}

Status Queue_EnQueue(QueuePtr q, QueueEntry item)
{
	Status outcome = overflow;
	if (!Queue_Full(q))
	{
		q->rear = (q->rear + 1) % MAXQUEUE;
		q->entry[q->rear] = item;
		outcome = success;
	}
	return outcome;
}

Status Queue_DeQueue(QueuePtr q, QueueEntry *item)
{
	Status outcome = underflow;
	if (!Queue_Empty(q))
	{
		q->front = (q->front + 1) % MAXQUEUE;
		*item = q->entry[q->front];
		outcome = success;
	}
	return outcome;
}

int Queue_Size(QueuePtr q)
{
	return((q->rear) - (q->front) % MAXQUEUE);
}