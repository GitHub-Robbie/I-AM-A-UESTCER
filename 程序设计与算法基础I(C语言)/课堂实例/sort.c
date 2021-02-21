#include <stdio.h>

#define N 10

int i, j;
void bubble_sort(int a[N])
{
	 for (i = 0; i < N - 1; ++i)
        for (j = 0; j < N - i - 1; ++j)
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
} 
int main()
{
    int a[N] = { 9, 2, 5, 3, 1, 8, 4, 6, 7, 0 };


   bubble_sort(a);

    for (i = 0; i < N; ++i)
        printf("%4d", a[i]);
	printf("\n");
    return 0;
}
