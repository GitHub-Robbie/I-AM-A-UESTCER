#include <stdio.h>

int main()
{
	int i = 1, n;
	double sum = 0;

	printf("Enter n: ");
	scanf("%d", &n);
	
	do{
		sum += (1.0 / i);
		++i;
	} while (i <= n);
	
	printf("%lf\n", sum);
	return 0;
}
