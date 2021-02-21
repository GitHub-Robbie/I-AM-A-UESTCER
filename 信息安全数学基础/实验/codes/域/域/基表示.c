#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[8] = { 0 };

void AddOne(int a[])
{
	int i = 0;
	for (i = 0; i < 8; i++)
	{
		if (a[i] == 0)
		{
			a[i] = 1;
			break;
		}
		else if (a[i] == 1)
		{
			a[i] = 0;
			while (i != 8)
			{
				if (a[i + 1] == 0)
				{
					a[i + 1] = 1;
					break;
				}
				else if (a[i + 1] == 1)
				{
					a[i + 1] = 0;
					i++;
				}
			}
			break;
		}
	}
}

int main()
{
	int i, j;
	for (i = 0; i < 256; i++)
	{
		for (j = 7; j >= 0; j--)
		{
			if (a[j] != 0)
				printf("x^%d ", j);
		}
		if (i == 0)
			printf("0");
		printf("\n");
		AddOne(a);
	}
	system("pause");
	return 0;
}