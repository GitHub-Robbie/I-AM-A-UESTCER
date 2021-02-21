#include <stdio.h>
int main()
{
	int n, i, sd;
	
	printf("Enter number of days in month: ");
	scanf("%d", &n);
	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &sd);
	putchar('\n');
	if(sd == 7)		
	{
		for (i = 1; i < sd; i++)
			printf("   ");
		
		for (i = 1; i <= n; i++)
		{	if ((sd + i - 1) % 7 == 0)
			printf("%2d\n", i);
		
			else 
				printf("%2d ", i);
		}	
	}
	else
	{
		for (i = 1; i < sd; i++)
		printf("   ");
		
		for (i = 1; i <= n; i++)
		{	if ((sd + i - 1) % 7 == 0)
			printf("%2d\n", i);
		
			else if(i == n) 
				printf("%2d", i);
				else 
				printf("%2d ", i);
		}	
		putchar('\n');
		}
	return 0;
}
