#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main()
{
	char ch;
	StackPtr stack;
	StackEntry e;
	Status z;
	printf("栈的作业：符号配对\n");
	printf("Please enter an expression(end with #): ");
	z = Stack_Init(&stack);
	ch = getchar();
	while (z == success)
	{
		if (ch == '(' || ch == '[' || ch == '{')
			Stack_Push(stack, ch);
		else if (ch == ')')
		{
			Stack_Pop(stack, &e);
			if (e != '(')
			{
				printf("ERROR!\n");
				break;
			}
		}
		else if (ch == ']')
		{
			Stack_Pop(stack, &e);
			if (e != '[')
			{
				printf("ERROR!\n");
				break;
			}
		}
		else if (ch == '}')
		{
			Stack_Pop(stack, &e);
			if (e != '{')
			{
				printf("ERROR!\n");
				break;
			}
		}
		else if (ch == '#')
		{
			if (!Stack_Empty(stack))
				printf("Matched!\n");
			else
			{
				printf("ERROR!\n");
				break;
			}
		}
		ch = getchar();
	}
	system("pause");
	return 0;
}