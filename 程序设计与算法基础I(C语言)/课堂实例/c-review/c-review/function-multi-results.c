#include <stdio.h>

void decompose(float a, int* int_part, float* fragment)
{
    *int_part = (int)a;
    *fragment = a - *int_part;
}

int main()
{
    float x = 3.1415;
    int i;
    float f;

    decompose(x, &i, &f);
    printf("%d, %g\n", i, f); //%g: remove trailing zeros

    return 0;
}