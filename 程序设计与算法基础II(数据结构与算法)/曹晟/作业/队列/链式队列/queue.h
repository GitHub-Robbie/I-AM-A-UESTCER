#pragma once
#define bool int
#define MAXQUEUE 100

typedef char QueueEntry;

typedef enum Status
{
	success, fail, fatal, range_error, overflow, underflow
} Status;

typedef struct node
{
	QueueEntry entry;
	struct node *next;
} QueueNode, *QueueNodePtr;

typedef struct queue
{
	QueueNode *front;
	QueueNode *rear;
} Queue, *QueuePtr;

Status Queue_Init(QueuePtr *q);
bool Queue_Empty(QueuePtr q);
Status Queue_EnQueue(QueuePtr q, QueueEntry item);
Status Queue_DeQueue(QueuePtr q, QueueEntry *item);
Status Queue_Front(QueuePtr q, QueueEntry *item);