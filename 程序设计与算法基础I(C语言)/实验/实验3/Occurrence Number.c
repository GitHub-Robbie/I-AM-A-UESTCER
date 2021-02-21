#include <stdio.h>
int main()
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char ch;
	int m = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, n = 0, j = 0;
	int i = 0;
	
	printf("Enter a number: ");
	ch = getchar();
	
	while (ch != '\n')
	{
		switch (ch)
		{
			case '0': m++; break;
			case '1': b++; break;
			case '2': c++; break;
			case '3': d++; break;
			case '4': e++; break;
			case '5': f++; break;
			case '6': g++; break;
			case '7': h++; break;
			case '8': n++; break;
			case '9': j++; break;
		}
		ch = getchar();
	}
	
	printf("Digit:		");
	
	printf("%d  %d  %d  %d  %d  %d  %d  %d  %d  %d", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
	printf("\n");
	printf("Occurrences:	%d%3d%3d%3d%3d%3d%3d%3d%3d%3d", m, b, c, d, e, f, g, h, n, j);
	printf("\n");
	return 0;
}
