#include <stdio.h>

float cal(float x, char ch, float y)
{
	switch (ch)
	{
		case '+': return(x + y); break;
		case '-': return(x - y); break;
		case '*': return(x * y); break;
		case '/': return(x / y); break;
	}
}

int main()
{
	char ch;
	float n;
	float a[50];
	int i = 0;
	
	printf("Enter an expression: ");

	scanf("%f", &n);
	scanf("%c", &ch);
	scanf("%f", &a[i]);
	n = cal(n, ch, a[i]);
	i++;
	scanf("%c", &ch);
	
	while (ch != '\n')
	{
		scanf("%f", &a[i]);
		n = cal(n, ch, a[i]);
		i++;
		scanf("%c", &ch);
	}
	printf("Value of expression: %g\n", n);
	return 0;
}
