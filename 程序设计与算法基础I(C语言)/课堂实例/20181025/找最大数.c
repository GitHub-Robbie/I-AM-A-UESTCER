#include <stdio.h>

#define LEN 10

int main()
{
	int a[LEN];
	int i = 1, b = 0;
	int max;
	
	for (i = 0; i < LEN; ++i)
		scanf("%d", &a[i]);
	
	for (i = LEN - 1; i >= 0; --i)
		if (max < a[i])
			max = a[i], b = i+1;
	
	for (i = 0; i < LEN; ++i)
		printf("%4d", a[i]);
	
	printf("\nThe max is: %d\n", max);
	printf("The position is: %d\n", b);
	
	return 0;
}
