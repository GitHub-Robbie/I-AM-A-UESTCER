#include <stdio.h>
int main()
{
	int a[10] =
	{ 9, 7, 3, 4, 0, 2, 6, 1, 5, 8 };
	int key, i;
	
	scanf("%d", &key);
	
	for (i = 0; i < 10; ++i)
		if (key == a[i])
		{
			printf("%d\n", i + 1);
			break;
		}
 	
	if (i == 10) printf("Not found.\n");

	return 0;
}
