#pragma once
#define bool int
#define MAXQUEUE 100

typedef char QueueEntry;

typedef enum Status
{
	success, fail, fatal, range_error, overflow, underflow
} Status;

typedef struct queue
{
	int front, rear;
	QueueEntry entry[MAXQUEUE];
} Queue, *QueuePtr;

Status Queue_Init(QueuePtr *q);				//如果要对队列、栈本身进行操作，必须使用指针的指针；其他的操作是对队列、栈内部的元素操作，故不需要
void Queue_Destroy(QueuePtr *q);
void Queue_Clear(QueuePtr q);
bool Queue_Empty(QueuePtr q);
bool Queue_Full(QueuePtr q);
Status Queue_EnQueue(QueuePtr q, QueueEntry item);
Status Queue_DeQueue(QueuePtr q, QueueEntry *item);
int Queue_Size(QueuePtr q);