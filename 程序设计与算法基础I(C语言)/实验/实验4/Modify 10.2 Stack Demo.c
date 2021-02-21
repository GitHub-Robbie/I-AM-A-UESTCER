#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACK_SIZE 200

char contents[STACK_SIZE];
int top = 0;

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void stack_overflow(void)
{

	exit(1);
}

char stack_underflow(void)
{

	return 0;
}

void push(char i)
{
	if (is_full())
		stack_overflow();
	else
		contents[top++] = i;
}

char pop(void)
{
	if (is_empty())
		stack_underflow();
	else
		return contents[--top];
}

int main()
{
	printf("Enter parentheses and/or braces: ");
	char ch;
	
	while(true)
	{
		ch = getchar();
		if (ch == '(' || ch == '{')
		{
			push(ch);
		}
		else if (ch == ')')
		{
			if(pop() != '(')
			{
				printf("Parentheses/braces are NOT nested properly\n");
				break;
			}
		}
		else if (ch == '}')
		{
			if(pop() != '{')
			{
				printf("Parentheses/braces are NOT nested properly\n");
				break;
			}
		}
		else if (ch =='\n')
		{
			if (is_empty())
			{
				printf("Parentheses/braces are nested properly\n");
			}
			else
			{
				printf("Parentheses/braces are NOT nested properly\n");
			}
			break;
		}
	}
	return 0;
}
