#include <stdio.h>
int main()
{
	int s;
	scanf("%d", &s);
	
	switch (s / 10)				//case�����ִ��ֱ��������� ����break���� 
	{
	case 10: printf("Outstanding"); break;  //case 10֮���printf���Բ�д 
	case 9: printf("Outstanding"); break; 
	case 8: printf("Excellent"); break;
	case 7: printf("Acceptable"); break;
	case 6: printf("Poor"); break;
	default: printf("Bad"); 				//default���������������֮�� 
	}
	return 0;
}
