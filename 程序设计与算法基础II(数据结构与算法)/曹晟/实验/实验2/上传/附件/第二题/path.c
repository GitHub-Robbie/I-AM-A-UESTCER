#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"

Name temp1[MAXSISE];

void Info_Input(int n, Info info[])
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		char ch[10];
		scanf("%s", &ch);
		strcpy(info[i].begin, &ch);
		scanf("%s", &ch);
		strcpy(info[i].end, &ch);
		scanf("%d", &info[i].weight);
	}
}

void Create_File()
{
	FILE *fp1, *fp2;
	fp1 = fopen("info.dat", "w");
	fp2 = fopen("AllPath.dat", "w");
	if ((!fp1)||(!fp2))
	{
		printf("Fail to create file!");
		exit(0);
	}
	fclose(fp1);
	fclose(fp2);
}

void Info_Output(int n, Info info[], FILE *fp)
{
	int i = 0;
	fp = fopen("info.dat", "w");
	if (fp == NULL)
	{
		printf("Fail to open file!");
		exit(0);
	}

	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%s\t", info[i].begin);
		fprintf(fp, "%s\t", info[i].end);
		fprintf(fp, "%d\t", info[i].weight);
		if (i != n - 1)
			fprintf(fp, "\n");
	}
	fclose(fp);
}

void Graph_Init(MatGraph *g, int n, int edge, Info info[])
{
	int i, j, k = 2;
	int flag = 0;
	Name temp[MAXV];
	strcpy(temp[0].name, info[0].begin);
	strcpy(temp[1].name, info[0].end);
	i = 0;
	//初始化
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			(*g).edges[i][j] = INF;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (i == j)
				(*g).edges[i][j] = 0;
		}
	for (i = 0; i < n; i++)
	{
		(*g).vexs[i].no = 0;
		strcpy((*g).vexs[i].name, "0");
	}
	i = 0;
	for (j = 1; j < edge; j++)
	{
		flag = 0;
		while (strcmp(info[j].begin, temp[i].name) != 0 && i < k)
			i++;
		if (strcmp(info[j].begin, temp[i].name) == 0)
		{
			flag = 1;
			i = 0;
		}
		if (flag != 1)
		{
			strcpy(temp[k].name, info[j].begin);
			i = 0;
			k++;
		}
	}

	i = 0;
	for (j = 1; j < edge; j++)
	{
		flag = 0;
		while (strcmp(info[j].end, temp[i].name) != 0 && i < k)
			i++;
		if (strcmp(info[j].end, temp[i].name) == 0)
		{
			flag = 1;
			i = 0;
		}
		if (flag != 1)
		{
			strcpy(temp[k].name, info[j].end);
			i = 0;
			k++;
		}
	}
	for (i = 0; i < n; i++)
	{
		(*g).vexs[i].no = i;
		strcpy((*g).vexs[i].name, temp[i].name);
	}
	k = 0;
	for (i = 0; i < (*g).n; i++)
		for (j = 0; j < (*g).n; j++)
		{
			if (strcmp((*g).vexs[i].name, info[k].begin) == 0 && strcmp((*g).vexs[j].name, info[k].end) == 0)
			{
				(*g).edges[i][j] = info[k].weight;
				k++;
				i = 0; j = 0;
			}
		}
	
	for (i = 0; i < (*g).n; i++)
		for (j = 0; j < (*g).n; j++)
		{
			if (j > i)
				(*g).edges[j][i] = (*g).edges[i][j];
		}
}

void Floyd(MatGraph *g, int A[MAXV][MAXV], int path[MAXV][MAXV])
{
	int i, j, k;
	for (i = 0; i < (*g).n; i++)
		for (j = 0; j < (*g).n; j++)
		{
			A[i][j] = (*g).edges[i][j];
			if (i != j && (*g).edges[i][j] < INF)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}
	for (k = 0; k < (*g).n; k++)
	{
		for (i = 0; i < (*g).n; i++)
			for (j = 0; j < (*g).n; j++)
				if (A[i][j] > A[i][k] + A[k][j])
				{
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = path[k][j];
				}
	}
}

void Dispath1(MatGraph *g, int A[][MAXV], int path[][MAXV])
{
	//第一部分: 任意两点之间的最短路径
	char begin[10];
	char end[10];
	char name[10];
	printf("请输入起点: ");
	scanf("%s", begin);
	fflush(stdin);
	printf("请输入终点: ");
	scanf("%s", end);
	int i, j, k, s;
	i = MatchNo(g, begin);
	j = MatchNo(g, end);
	int apath[MAXV], d;
	if (A[i][j] != INF && i != j)
	{
		printf("\n");
		printf("从%s到%s的最短路径为: ", begin, end);
		k = path[i][j];
		d = 0; apath[d] = j;
		while (k != -1 && k != i)
		{
			d++; apath[d] = k;
			k = path[i][k];
		}
		d++; apath[d] = i;
		printf("%s", begin);
		for (s = d - 1; s >= 0; s--)
		{
			MatchName(g, apath[s]);
			strcpy(name, temp1[0].name);
			printf("<->%s", name);
		}
		printf("\n");
		printf("路径长度为: %d\n", A[i][j]);
	}
}

int Dispath_All(MatGraph *g, int A[][MAXV], int path[][MAXV], Path output[])
{
	int i, j, k, s;
	int sum = 1;
	int way = 0;
	int apath[MAXV], d;
	char begin1[10];
	char end1[10];
	char name1[10];
	for (i = 0; i < (*g).n; i++)
		for (j = 0; j < (*g).n; j++)
		{
			if (A[i][j] != INF && i != j)
			{
				MatchName(g, i);
				strcpy(begin1, temp1[0].name);
				MatchName(g, j);
				strcpy(end1, temp1[0].name);
//				printf("【%d】从%s到%s的最短路径为: \n", sum, begin1, end1);
				strcpy(output[way].end, end1);
				sum++;
				k = path[i][j];
				d = 0; apath[d] = j;
				while (k != -1 && k != i)
				{
					d++; apath[d] = k;
					k = path[i][k];
				}
				d++; apath[d] = i;
//				printf("      %s", begin1);
				strcpy(output[way].path, begin1);
				strcpy(output[way].begin, begin1);
				for (s = d - 1; s >= 0; s--)
				{
					MatchName(g, apath[s]);
					strcpy(name1, temp1[0].name);
//					printf("<->%s", name1);
					strcat(output[way].path, "<->");
					strcat(output[way].path, name1);
				}
//				printf("\n");
//				printf("      路径长度为: %d\n", A[i][j]);
				output[way++].length = A[i][j];
//				printf("\n");
			}
		}
	for (i = 0; i < sum - 1; i++)
		output[i].flag = 0;

	Path output_1[MAXSISE];
	k = 0;
	for (i = 0; i < sum - 1; i++)
		for (j = 0; j < sum - 1; j++)
		{
				if (strcmp(output[i].begin, output[j].end) == 0 && strcmp(output[j].begin, output[i].end) == 0)
				{
					if (output[i].flag != 1)
					{
						memcpy(&output_1[k++], &output[i], sizeof(Path));
						output[j].flag = 1;
						j = 0;
						break;
					}
				}
		}
	int tag = 1;
	printf("\n");
	for (i = 0; i < k - 1; i++)
	{
		printf("【%d】%s到%s之间最短路径为: \n", tag++, output_1[i].begin, output_1[i].end);
		printf("     %s\n", output_1[i].path);
		printf("     路径长度为: %d\n", output_1[i].length);
	}
	printf("\n");
	return sum - 1;
}

int MatchNo(MatGraph *g, char name[10])
{
	int i;
	for (i = 0; i < (*g).n; i++)
	{
		if (strcmp((*g).vexs[i].name, name) == 0)
			return (*g).vexs[i].no;
	}
}

void MatchName(MatGraph *g, int no)
{
	int i;
	for (i = 0; i < (*g).n; i++)
		if ((*g).vexs[i].no == no)
			strcpy(temp1[0].name, (*g).vexs[i].name);
}

void Path_Output(int n, Path output[], FILE *fp)
{
	int i = 0;
	fp = fopen("AllPath.dat", "w");
	if (fp == NULL)
	{
		printf("Fail to open file!");
		exit(0);
	}

	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%s\t", output[i].path);
		fprintf(fp, "%d\t", output[i].length);
		if (i != n - 1)
			fprintf(fp, "\n");
	}
	fclose(fp);
}

void Init_List(LinkListPtr list)
{
	Nodeptr p;		//头结点
	if (*list == NULL)
	{
		p = (Nodeptr)malloc(sizeof(Node));
		if (p == NULL)
			printf("Fatal!");
		*list = p;
		(*list)->next = NULL;
	}
}

void Create_List(int n, Path output[], LinkListPtr list)
{
	Nodeptr p, r;
	p = (Nodeptr)malloc(sizeof(Node));
	r = (Nodeptr)malloc(sizeof(Node));
	(*list)->next = p;
	(*list)->next = r;
	p->next = NULL;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		Nodeptr q;
		q = (Nodeptr)malloc(sizeof(Node));
		strcpy(q->begin, output[i].begin);
		strcpy(q->end, output[i].end);
		strcpy(q->path, output[i].path);
		q->length = output[i].length;
		q->next = p;
		r->next = q;
		r = q;
	}
	
}

void List_Query(LinkListPtr list)
{
	char begin[10];
	char end[10];
	printf("请输入起点: ");
	scanf("%s", begin);
	fflush(stdin);
	printf("请输入终点: ");
	scanf("%s", end);
	Nodeptr p;
	p = (Nodeptr)malloc(sizeof(Node));
	p = (*list)->next;
	while (p != NULL)
	{
		if (strcmp(p->begin, begin) == 0 && strcmp(p->end, end) == 0)
		{
			printf("\n");
			printf("从%s到%s的最短路径为: \n", begin, end);
			printf("%s\n", p->path);
			printf("路径长度为: %d\n", p->length);
		}
		p = p->next;
	}
}
