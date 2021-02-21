#include "stdafx.h"
#include "stdio.h"

int compare(int a, int b) {
	int c;
	if (a < b) c = b - a;
	else c = a - b;
	printf("their sum is %d\n", c);
	printf("can you have the ability of reverse analysis\n");
	return c;
}

int main()
{
	printf("this is a simple ");
	printf("program you are annalyzing now!\n");
	int a = 57;
	int b = 60;
	if (a <= b) {
		a = 60;
		b = 57;
		compare(a, b);
	}
	else printf("hello do you have get the right result?no!it's not over\n");

	a = 50;
	b = 57;
	if (a < b) {
		compare(a, b);
	}
	printf("this is true end!but you should not relax yourself!!! be cafureful ");
	printf("trap congratulation! now is the end\n");
	return 0;
}