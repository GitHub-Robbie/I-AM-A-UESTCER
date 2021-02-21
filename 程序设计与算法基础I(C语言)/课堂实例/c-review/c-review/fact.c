#include <stdio.h>

//即使用了long long，依然面临溢出的问题
long long fact(long long n)
{
    if (n == 1) return 1;
    return n * fact(n - 1);
}

int main()
{
    printf("%ld, %ld\n", fact(5), fact(10));
    return 0;
}