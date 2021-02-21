#include <stdio.h>

void find(int a[], int len, int* max1, int* pos1, int* max2, int* pos2)
{
    int i;

    for (*max1 = a[0], i = 0; i < len; ++i)
        if (*max1 < a[i])
        {
            *max1 = a[i];
            *pos1 = i;
        }

    for (*max2 = a[0], i = 0; i < len; ++i)
        if (*max2 < a[i] && i != *pos1)
        {
            *max2 = a[i];
            *pos2 = i;
        }
}

int main()
{
    int a[] = {2, 5, 3, 9, 6, 1, 0, 7, 8, 4};
    int max1, pos1, max2, pos2;

    find(a, 10, &max1, &pos1, &max2, &pos2);
    printf("max1=%d@%d, max2=%d@%d\n", max1, pos1, max2, pos2);

    return 0;
}
