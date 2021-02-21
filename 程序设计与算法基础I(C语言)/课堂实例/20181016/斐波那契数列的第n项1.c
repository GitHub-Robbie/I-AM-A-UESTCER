#include <stdio.h>

int main()
{
	int t = 0, a1 = 1, a2 = 1, i = 3, n;
	
	printf("Enter n: ");
	scanf("%d", &n);
	
	do {
		t = a1 + a2;
		a1 = a2;
		a2 = t;
		++i;
	
		} while(i <= n);
 	
	 printf("%d", t);
	
	return 0;
}