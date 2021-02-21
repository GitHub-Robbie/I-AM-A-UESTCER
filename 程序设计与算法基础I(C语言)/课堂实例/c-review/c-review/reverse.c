#include <stdio.h>

void reverse(char c)
{
   if (c != '\n')
    {
        reverse(getchar());
        putchar(c);
    }
}

int main()
{
    reverse(getchar());
    return 0;
}
