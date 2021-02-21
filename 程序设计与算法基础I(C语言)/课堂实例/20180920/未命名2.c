#include <stdio.h>
#include <math.h>        

int main()
{
	int a, b, c;
	float x1, x2, delta;   
	
	scanf("%d%d%d",&a,&b,&c);
	
	delta=b*b-4*a*c;
	x1=(-b+sqrt(delta))/2/a; 
	x2=(-b-sqrt(delta))/2/a;

	printf("x1=%f, x2=%f\n",x1,x2);
	return 0;
}
