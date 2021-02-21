//root.c selective structure

#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c;
    double d, x1, x2, x3;

    printf("Please input a, b, c:");
    scanf("%lf%lf%lf", &a, &b, &c);

	d = b * b - 4 * a * c;
    if (d > 0)
	{
		x1 = (-b + sqrt(d)) / 2 / a;
    	x2 = (-b - sqrt(d)) / 2 / a;

    	printf("The roots are: %.3lf, %.3lf\n", x1, x2);
	}
	else if (fabs(d) < 1e-7)		//一个=表示赋值，==表示判断相等 
	{
			x1 = -b / 2 / a;
			printf("Two identical roots: %.3f\n", x1);
		}
	else
	{
		x1 = -b / 2 / a;
		x2 = sqrt(-d) / 2 / a;
		if (x2 > 0)
		{
			printf("root1: %.3lf+%.3lfi\n", x1, x2);
		    printf("root2: %.3lf-%.3lfi\n", x1, x2);
		}
		else
		{
			x3=fabs(x2);
			printf("root1: %.3lf%.3lfi\n", x1, x2);
			printf("root2: %.3lf+%.3lfi\n", x1, x3);
		}
	}
	return 0;
}
