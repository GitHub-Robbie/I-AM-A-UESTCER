#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);
    if (n < 0)
    {
        putchar('-');
        n = -n;  //变为正数
    }

    //去掉末尾的0
    while (n % 10 == 0) n /= 10;

    while (n > 0)
    {
        printf("%d", n % 10);
        n /= 10;
    }

    return 0;
}