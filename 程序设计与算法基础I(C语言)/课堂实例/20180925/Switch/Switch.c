#include <stdio.h>
int main()
{
	int s;
	scanf("%d", &s);
	
	switch (s / 10)				//case会继续执行直至程序结束 ，加break结束 
	{
	case 10: printf("Outstanding"); break;  //case 10之后的printf可以不写 
	case 9: printf("Outstanding"); break; 
	case 8: printf("Excellent"); break;
	case 7: printf("Acceptable"); break;
	case 6: printf("Poor"); break;
	default: printf("Bad"); 				//default必须放在所有条件之后 
	}
	return 0;
}
