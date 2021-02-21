#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct {
	int width;
	char result;
} Square;

struct {
	int width;
	int height;
	char result;
} Triangle;

struct {
	int width;
	int height;
	char result;
} Parallelogram;

struct {
	int width;
	int width2;
	int height;
	char result;
} Trapezoid;

int main()
{
	int n;
	int i = 1;
	int answer;
//	char review[];
	while(1) {
	srand((unsigned) time(NULL));
	n = rand()%4 + 1;
	switch (n) {
		case 1: {
			printf("%d. Square => width = %d, area = ?", i, Square.width = rand()%10);
			scanf("%d", &answer);
			if(answer == Square.width * Square.width) {
			printf("correct\n");
			Square.result = 'V';
			}
			else {
				printf("wrong\n");
				Square.result = 'X';
			}
			
		} break;
		case 2: {
			printf("%d. Triangle => width = %d, height = %d, area = ?", i, Triangle.width = rand()%10, Triangle.height = rand()%10);
			scanf("%d", &answer);
			if(answer == 0.5 * Triangle.width * Triangle.height) {
			printf("correct\n");
			Triangle.result = 'V';
			}
			else {
				printf("wrong\n");
				Triangle.result = 'X';
			}
			
		} break;
		case 3: {
			printf("%d. Parallelogram => width = %d, height = %d, area = ?", i, Parallelogram.width = rand()%10, Parallelogram.height = rand()%10);
			scanf("%d", &answer);
			if(answer == Parallelogram.width * Parallelogram.height) {
			printf("correct\n");
			Parallelogram.result = 'V';
			}
			else {
				printf("wrong\n");
				Parallelogram.result = 'X';
			}
			
		} break;
		case 4: {
			printf("%d. Trapezoid => width = %d, width2 = %d, height = %d, area = ?", i, Trapezoid.width = rand()%10, Trapezoid.width2 = rand()%10, Trapezoid.height = rand()%10);
			scanf("%d", &answer);
			if(answer == (Trapezoid.width + Trapezoid.width2)*Trapezoid.height*0.5) {
			printf("correct\n");
			Trapezoid.result = 'V';
			}
			else {
				printf("wrong\n");
				Trapezoid.result = 'X';
			}
			
		} break;

				
}
	
	i++;
	}
	return 0;
}

