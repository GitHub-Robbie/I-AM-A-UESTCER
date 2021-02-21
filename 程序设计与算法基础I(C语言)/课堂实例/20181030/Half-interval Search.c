#include <stdio.h>
int main()
{
	int a[10] = 
	{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int low = 0, mid, high = 9;
	int key, i;

	scanf("%d", &key);
	
	while (low <= high)	
	{
		mid = (low + high) / 2;
		if (key == a[mid])
		{
			printf("%d\n", mid + 1);
			break;
		}
		else if (key < a[mid])
			high = mid - 1;
				else
					low = mid + 1;
	} 
	
	if (low > high) printf("-1\n");
	return 0;
}

