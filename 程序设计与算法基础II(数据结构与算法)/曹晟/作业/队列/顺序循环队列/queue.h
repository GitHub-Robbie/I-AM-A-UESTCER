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

Status Queue_Init(QueuePtr *q);				//���Ҫ�Զ��С�ջ������в���������ʹ��ָ���ָ�룻�����Ĳ����ǶԶ��С�ջ�ڲ���Ԫ�ز������ʲ���Ҫ
void Queue_Destroy(QueuePtr *q);
void Queue_Clear(QueuePtr q);
bool Queue_Empty(QueuePtr q);
bool Queue_Full(QueuePtr q);
Status Queue_EnQueue(QueuePtr q, QueueEntry item);
Status Queue_DeQueue(QueuePtr q, QueueEntry *item);
int Queue_Size(QueuePtr q);