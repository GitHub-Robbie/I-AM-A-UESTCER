//2019.06.21
//数据结构 实验二 第二题
//公园最短路径查询系统
//作者: @汤泡饭
//转载请注明出处

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"

int main()
{
	int n, edge;
	int i, j, k;
	int sum;
	Info info[MAXSISE];
	Path output[MAXSISE];
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	int A[MAXV][MAXV];
	int path[MAXV][MAXV];
	LinkListPtr list = NULL;
	//图初始化
	MatGraph *g;
	g = (MatGraph*)malloc(sizeof(MatGraph));

	int opt = 1;
	char yn;
	while (opt != 6)
	{
		system("cls");
		printf("*****************************************************\n");
		printf("*             欢迎使用公园最短路径查询系统          *\n");
		printf("*****************************************************\n");
		printf("*\t      [1] 录入景点路径信息\t            *\n");
		printf("*\t      [2] 直接查询指定景点间最短路径        *\n");
		printf("*\t      [3] 查询所有景点对间的最短路径        *\n");
		printf("*\t      [4] 创建路径链表\t\t            *\n");
		printf("*\t      [5] 快速查询指定景点间最短路径        *\n");
		printf("*\t      [6] 退出程序\t\t            *\n");
		printf("*****************************************************\n");
		printf("\n");
		printf("请输入您的选择: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			system("cls");
			printf("\t\t*当前所在: [1] 录入景点路径信息*\n");
			printf("说明: \n信息录入格式: 景点A 景点B 路径长度\n\n");
			printf("请输入景点个数: ");
			scanf("%d", &n);
			printf("请输入路径条数: ");
			scanf("%d", &edge);
			(*g).n = n;
			(*g).e = edge;
			printf("请按格式录入信息: \n\n");
			Info_Input(edge, info);
			Create_File();
			Info_Output(edge, info, fp1);
			Graph_Init(g, n, edge, info);
			printf("\n");
			printf("信息已录入完成并保存! \n");
			printf("是否返回主界面? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
				case 'y': break;
				case 'n': exit(1);
			}
			break;
		case 2:
			system("cls");
			printf("\t*当前所在: [2] 直接查询指定景点间最短路径*\n");
			Floyd(g, A, path);
			Dispath1(g, A, path);
			printf("\n");
			printf("是否返回主界面? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 3:
			system("cls");
			printf("\t*当前所在: [3] 查询所有景点对间的最短路径*\n");
			sum = Dispath_All(g, A, path, output);
			Path_Output(sum, output, fp2);
			printf("所有路径查询完成并保存! \n");
			printf("是否返回主界面? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 4:
			system("cls");
			printf("\t\t*当前所在: [4] 创建路径链表*\n");
			Init_List(&list);
			Create_List(sum, output, &list);
			printf("\n");
			printf("从文件链表建立完成! \n");
			printf("是否返回主界面? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 5:
			system("cls");
			printf("\t*当前所在: [5] 快速查询指定景点间最短路径*\n");
			printf("\n");
			List_Query(&list);
			printf("\n");
			printf("是否返回主界面? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		default:
			exit(1);
		}
	}

	system("pause");
	return 0;
}