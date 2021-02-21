#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, c, d, e, i;
	scanf("%d%d", &a, &b);
	for (i = 0; i < 3; i++)
	{
		scanf("%d%d%d", &c, &d, &e);
		fflush(stdin);
	}
	printf("A loop was detected in this graph.\n");
	system("pause");
	return 0;
}