#include <stdio.h>

int main()
{
	int i = 1, t = 3, n;
	double sum = 0;

	printf("Enter n: ");
	scanf("%d", &n);
	
	do{
		sum += (1.0 / t);
		t = t * 10 + 3;
		++i;
	} while (i <= n);
	
	printf("%lf\n", sum);
	return 0;
}
