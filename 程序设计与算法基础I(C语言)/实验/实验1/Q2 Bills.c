#include <stdio.h>
int main()
{
	int m, a, b, c, d;
	printf("Enter a dollar amount: ");
	scanf("%d", &m);
 	a = m / 20;
 	b = (m - a * 20) / 10;
 	c = (m - a * 20 - b * 10) / 5;
 	d = (m - a * 20 - b * 10 - c * 5)/1;
 	printf("$20 bills: %d\n", a);
 	printf("$10 bills: %d\n", b);
 	printf("$5 bills: %d\n", c);
 	printf("$1 bills: %d\n", d);
	return 0;
}
