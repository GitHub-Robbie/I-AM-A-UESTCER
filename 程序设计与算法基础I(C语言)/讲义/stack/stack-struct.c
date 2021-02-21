#include <stdio.h>
#include <stdlib.h>

//type alias
//you can substitute 'int' with any type, such as float
typedef int value_type;
typedef int bool;

#define MAX_DEPTH 1024

struct stack_tag
{
    value_type storage[MAX_DEPTH];
    int top;
};
typedef struct stack_tag stack;
typedef stack* stack_pointer;

bool is_full(stack_pointer s) { return s->top == MAX_DEPTH; }
bool is_empty(stack_pointer s) { return s->top == 0; }

void overflow() 
{
    printf("Push failed: the stack is full.\n");
    exit(EXIT_FAILURE);
}

void underflow() 
{
    printf("Pop failed: the stack is empty.\n");
    exit(EXIT_FAILURE);
}

void init(stack_pointer s)
{
    s->top = 0;
}

void push(stack_pointer s, value_type e)
{
    if (is_full(s))
        overflow();
    else
        s->storage[s->top++] = e;
}

value_type pop(stack_pointer s)
{
    if (is_empty(s))
        underflow();
    else
        return s->storage[--s->top];
}

int main()
{
    stack S, *pS = &S;
    int i;
    value_type t;

    init(pS);

    for (i = 0; i <=4; ++i) push(pS, i);

    t = pop(pS);
    printf("%d, %d\n", t, pop(pS));

    pop(pS); pop(pS); pop(pS); 
    pop(pS); //this will cause underflow

    return 0;
}