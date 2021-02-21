#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
	char ch;
	QueuePtr queue;
	QueueEntry e;
	Status z;
	printf("栈的作业：符号配对(只接受输入()[]{}#这几种符号)\n");
	printf("Please enter an expression(end with #): ");
	z = Queue_Init(&queue);
	ch = getchar();
	if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
	{
		while (z == success)
		{
			if (ch == '(' || ch == '[' || ch == '{')
				Queue_EnQueue(queue, ch);
			else if (ch == ')')
			{
				Queue_DeQueue(queue, &e);
				if (e != '(')
				{
					printf("ERROR!\n");
					break;
				}
			}
			else if (ch == ']')
			{
				Queue_DeQueue(queue, &e);
				if (e != '[')
				{
					printf("ERROR!\n");
					break;
				}
			}
			else if (ch == '}')
			{
				Queue_DeQueue(queue, &e);
				if (e != '{')
				{
					printf("ERROR!\n");
					break;
				}
			}
			else if (ch == '#')
			{
				if (Queue_Empty(queue))
					printf("Matched!\n");
				else
				{
					printf("ERROR!\n");
					break;
				}
			}
			ch = getchar();
		}
	}
	else
		printf("Illegal input!\n");
	system("pause");
	return 0;
}