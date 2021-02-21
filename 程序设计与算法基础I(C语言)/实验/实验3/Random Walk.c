#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X 10
#define Y 10
#define TRUE 1
#define FALSE 0

int main()
{
	int walk[X][Y] = {0};			//��ʼ��Ϊ0 
	char eng[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 
					'H', 'I', 'J', 'K', 'L', 'M', 'N', 
					'O', 'P', 'Q', 'R', 'S', 'T', 'U', 
					'V', 'W', 'X', 'Y', 'Z'};
	int i, j, k = 0;
	int count = 0;		 
	int up, down, left, right;
	int x, y, loca;
 
 	up = down = left = right = 5;
 	
 	srand((unsigned)time(NULL));
 	x = rand()%X;
 	y = rand()%Y;					//��X,Y����������� 
 	
 	walk[x][y] = eng[k];		//����A 
 	++k;
 	
 	while(k != 26 && count < 4)
 	{
	 	loca = rand()%4;			//�������0123�����ĸ����� 
	 	switch(loca)
	 	{
	 		case 0: 
	 		{
		 		if (walk[x-1][y] == 0 && ((x - 1) > 0))			//���A���û��������û��Խ�� 
		 		{
		 			x = x - 1;
		 			walk[x][y] = eng[k++];
		 			up = down = left = right = 5;
		 			count = 0;
		 			break;
		 		}
		 		else if (up != loca)			//������������Խ�磬��0����up�������������������ֱ�����ɵ������������0Ϊֹ 
		 		{
		 			up = loca;
		 			count++;
		 		}
		 		break;
		 	}
			case 1: 
	 		{
		 		if (walk[x+1][y] == 0 && ((x + 1) < 10))
		 		{
		 			x = x + 1;
		 			walk[x][y] = eng[k++];
		 			up = down = left = right = 5;
		 			count = 0;
		 			break;
		 		}
		 		else if (down != loca)
		 		{
		 			down = loca;
		 			count++;
		 		}
		 		break;	
	 		}
	 		case 2: 
	 		{
		 		if (walk[x][y-1] == 0 && ((y - 1) >= 0))
		 		{
		 			y = y - 1;
		 			walk[x][y] = eng[k++];
		 			up = down = left = right = 5;
		 			count = 0;
		 			break;
		 		}
		 		else if (left != loca)
		 		{
		 			left = loca;
		 			count++;
		 		}
		 		break;	
	 		}
	 		case 3: 
	 		{
		 		if (walk[x][y+1] == 0 && ((y + 1) < 10))
		 		{
		 			y = y + 1;
		 			walk[x][y] = eng[k++];
		 			up = down = left = right = 5;
		 			count = 0;
		 			break;
		 		}
		 		else if (right != loca)
		 		{
		 			right = loca;
		 			count++;
		 		}
		 		break;	
	 		}
		 	
	 	}
 	}
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			if (walk[i][j] == 0)
			printf("%c", '.');
			else
			printf("%c", walk[i][j]);
		}
	printf("\n");
	}
	return 0;
}
