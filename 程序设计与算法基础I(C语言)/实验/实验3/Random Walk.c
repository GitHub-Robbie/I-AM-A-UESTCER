#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X 10
#define Y 10
#define TRUE 1
#define FALSE 0

int main()
{
	int walk[X][Y] = {0};			//初始化为0 
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
 	y = rand()%Y;					//在X,Y内生成随机数 
 	
 	walk[x][y] = eng[k];		//填入A 
 	++k;
 	
 	while(k != 26 && count < 4)
 	{
	 	loca = rand()%4;			//随机生成0123代表四个方向 
	 	switch(loca)
	 	{
	 		case 0: 
	 		{
		 		if (walk[x-1][y] == 0 && ((x - 1) > 0))			//如果A左边没有填数且没有越界 
		 		{
		 			x = x - 1;
		 			walk[x][y] = eng[k++];
		 			up = down = left = right = 5;
		 			count = 0;
		 			break;
		 		}
		 		else if (up != loca)			//如果左边有数或越界，则将0赋给up，再重新生成随机数，直到生成的随机数不等于0为止 
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
