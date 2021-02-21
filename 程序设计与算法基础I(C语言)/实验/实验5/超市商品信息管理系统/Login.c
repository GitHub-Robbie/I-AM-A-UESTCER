#include <stdio.h>
#include <string.h> 
int main()
{
	int land();
	if (land() == 0)
	{
		printf("ok");
	}
	else if(land() == -1)
	{
		printf("fail");
	}
	return 0;
}

int land()
{
	int i =3;
	char ch[]={"37642749YHNcx"};
	char input[20] = {0};
	
	while (i)
	{
		printf("shuru:");
		scanf("%s", input);
		if(!strcmp(ch,input))
		{
			return 0;
		}
		else{
			i--;
			printf("fail,left%d\n",i);
		}
	}
	if(i==0)
	{
		return (-1);
	}
	return 0;
}
