#include <stdio.h>

//global
int i = 0;

//parameter i is local, masking global i
int f(int i)
{
    //local static
    static int x = 1;
    ++x;
    return x + i;
    //after returned, local static x holds the latest value 
}

int g(int a)
{
    //local
    int x = 1;
    ++x;
    return x + i + a; //no masking, this i is global
    //after returned, local x expired
}

int main()
{
    int j;
    for (j = 0; j < 3; ++j)
        printf("%5d,%5d\n", f(j), g(j));
    
    return 0;
}