#include <stdio.h>
#define MAX 100
 
int main()
{
	char message[MAX];
	int i = 0;

	printf("Enter a message: ");
	for (i = 0; i < MAX; i++)
	{
		message[i] = getchar();
		if (message[i] == '\n')
			break;
	}
	
	printf("Reversal is: ");
	for (i--; i >= 0; i--)						//i--用的很好 
 		putchar(message[i]);
 	putchar('\n');
 	
	return 0;
}
