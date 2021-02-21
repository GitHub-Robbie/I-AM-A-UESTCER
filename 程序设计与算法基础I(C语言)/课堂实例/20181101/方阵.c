#include <stdio.h>
int main()
{
	#define N 15
	int i, j;
	int a[N][N];
	
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			a[i][j] = i * N + j + 1;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
			printf("%4d", a[i][j]);
		putchar('\n');
	}
	
	return 0;
}
