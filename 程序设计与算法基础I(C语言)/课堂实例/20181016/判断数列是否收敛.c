#include <stdio.h>

int main()
{
	int i = 1, n;
	double sum = 0, sum2 = sum;

	printf("Enter n: ");
	scanf("%d", &n);
	
	do{
		sum2 = sum;
		sum += (1.0 / i);
		++i;
		if (sum - sum2 < 1E-30)
		{
			printf("0\n");
			break;
		}
	
	} while (1);
	

	return 0;
}
