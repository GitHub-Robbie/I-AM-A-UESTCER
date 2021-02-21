#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int magic, guess;
	
	srand(time(NULL));
	magic = rand() % 100 + 1;
	
	do {
		printf("Please input your answer: ");
		scanf("%d", &guess);
	
		if (magic == guess)
			printf("Bingo!\n");
		else if (magic < guess)
			printf("Smaller!\n");
			else
				printf("Bigger!\n");
				
	} while (magic != guess);
	
	return 0;
}
