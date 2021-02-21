#include <stdio.h>
int main()
{
	#define MAXN 20
	#define EAST 0
	#define SOUTH 1
	#define WEST 2
	#define NORTH 3
	int a[MAXN+2][MAXN+2]= {0};		//加一圈 
	int N, m = 1;
	int i, j;
	int dir = EAST;
	
	do { 
		printf("Please input a length(<%d):", MAXN);
		scanf("%d", &N);
	} while (N > MAXN);

	for (j = 0; j < N + 2; ++j)
		a[N+1][j] = a[0][j] = 1;
	for (i = 0; i < N + 2; ++i)
		a[i][0] = a[i][N+1] = 1;  //把最外面一圈变成1 
		
	i = j = 1;
	while (m <= N * N)
	{
		if (a[i][j] == 0)
		{
			a[i][j] = m++;
			switch (dir)
			{
			case EAST: ++j; break;
			case SOUTH: ++i; break;
			case WEST: --j; break;
			case NORTH: --i; break;	
			}
		}
		else
		{
			switch (dir)
			{
			case EAST: dir = SOUTH; 
			--j; ++i; break;
			
			case SOUTH: dir = WEST;
			--j; --i; break;
			
			case WEST: dir = NORTH;
			++j; --i; break;
			
			case NORTH: dir = EAST;
			++j; ++i; break;	
			}
		}
	}
	
	for (i = 1; i < N + 1; ++i)
	{
		for (j = 1; j < N + 1; ++j)
			printf("%4d", a[i][j]);
		putchar('\n');
	}
		
	return 0;
}
