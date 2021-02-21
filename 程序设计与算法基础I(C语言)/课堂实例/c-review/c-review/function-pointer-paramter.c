#include <stdio.h>

void f(int *i)
{
    ++*i;
    printf("in f(): formal paramter *i changed: %d\n", *i);
}

int main()
{
    int a = 0;

    printf("before f() called: %d\n", a);
    f(&a);
    printf("after f() called: %d\n", a);

    return 0;
}
