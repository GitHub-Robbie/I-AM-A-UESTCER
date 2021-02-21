#include <stdio.h>
int main()
{
	float m, n;
	printf("Enter an amount: ");
	scanf("%f", &m);
	n = 1.05 * m;
	printf("With tax added: $%.2f\n", n);
	return 0;
}
