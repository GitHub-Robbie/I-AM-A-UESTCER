#include <stdio.h>
int main()
{
	int c = 0, ch;
	ch = getchar();
	while(ch != '\n')
		{
		if (ch >= '0' && ch <= '9')
	 		{
		 	++c;	
		 	}
		ch = getchar();
		}
	printf("%d\n",c);
	return 0;
}
