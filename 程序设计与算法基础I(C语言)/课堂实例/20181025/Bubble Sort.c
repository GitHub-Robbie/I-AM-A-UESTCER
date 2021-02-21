#include <stdio.h>

#define LEN 10

int main()
{
	int a[LEN]={10,9,8,7,6,5,4,3,2,1};
	int i, j;
		
	for (i = 0; i < LEN - i - 1; ++i)
		for (j = 0; j < LEN - i; ++j)
		if (a[j] > a[j + 1])
		{
			int t = a[j];
			a[j] = a[j + 1];
			a[j + 1] = t;
		}
	
	for (i = 0; i < LEN; ++i)
		printf("%4d", a[i]);
	
	return 0;
}
