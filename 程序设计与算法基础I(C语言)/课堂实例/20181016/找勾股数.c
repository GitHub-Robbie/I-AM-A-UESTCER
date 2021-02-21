#include <stdio.h>

int main()
{
	int a, b, c;
	for (a = 0; a <= 10000; ++a)
		for (b = 0; b <= 10000; ++b)
			for (c = 0; c <= 10000; ++c) 
			if (a*a + b*b == c*c)
				printf("%d,%d,%d\n", a, b, c);
	return 0;
}