#include <stdio.h>

int* max(int *a, int len)
{
    int max, i, j;
    for (max = a[0], j = i = 0; i < len; ++i)
        if (max < a[i])
        {
            max = a[i];
            j = i;
        }

    return a + j;  
}

int main()
{
    int a[] = {2, 5, 3, 9, 6, 1, 0, 7, 8, 4};
    int *p;

    p = max(a, 10);
    printf("the max is: %d@%d\n", *p, p - a);

    return 0; 
}