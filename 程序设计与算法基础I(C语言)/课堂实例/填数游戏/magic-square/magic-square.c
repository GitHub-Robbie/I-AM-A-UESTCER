#include <stdio.h>
int main()
{
	#define MAXN 19
	unsigned a[MAXN][MAXN] = {0};
	unsigned N, m = 1;
	int i, j; //shouldn't be unsigned, because would be negative
	
	do { 
		printf("Please input a length(<%d):", MAXN);
		scanf("%d", &N);
	} while (N > MAXN || N % 2 == 0);
		
	i = 0; j = N / 2;
	while (m <= N * N)
	{
		if (a[i][j] == 0)
		{
			a[i][j] = m++;
			--i; if (i < 0) i += N;
			++j; if (j >= N) j -= N;
		}
		else
		{
			i += 2; if (i >= N) i -= N;
			--j; if (j < 0) j += N;
		}
	}
	
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
			printf("%4d", a[i][j]);
		putchar('\n');
	}
		
	return 0;
}