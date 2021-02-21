#include <stdio.h>

#define N 10

int main()
{
    int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int high, low, mid, x;

    printf("Please input a number:");
    scanf("%d", &x);

    high = N - 1; low = 0;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (a[mid] == x) break;
        else if (a[mid] < x) low = mid + 1;
        else high = mid - 1;
    }

    if (low > high) printf("%d not found!\n", x);
    else printf("found %d@%d\n", x, mid);

    return 0;
}