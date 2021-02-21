#include <stdio.h>
#include<stdlib.h>
#include "critical path.h"

void CreateGraph(Vexnode* G, int vex, int arc)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int begin, end, weight;
	Arcnode *p;
	for (i = 0; i < vex; i++)
	{
		G[i].id = 0;
		G[i].firstarc = NULL;
	}
	for (i = 0; i < vex; i++)
		G[i].data = i + 1;
	for (k = 0; k < arc; k++)			//Â¼ÈëÈ¨Öµ
	{
		int a, b;
		scanf("%d%d%d", &a, &b, &weight);
		begin = a + 1;
		end = b + 1;
		p = (Arcnode*)malloc(sizeof(Arcnode));
		p->adjvex = end - 1;
		p->weight = weight;
		G[end - 1].id++;
		p->nextarc = G[begin - 1].firstarc;
		G[begin - 1].firstarc = p;
	}
}

int SearchMapPath(Vexnode* G, int vex, int arc)
{
	Path path1[MAX];
	int totaltime = 0;
	int m = 0;
	int i, j, k, t;
	char sv[MAX];
	int front, rear;
	int *topology, *vl, *ve, *el, *ee;
	front = rear = -1;
	t = 0;
	topology = (int*)malloc(vex * sizeof(int));
	vl = (int*)malloc(vex * sizeof(int));
	ve = (int*)malloc(vex * sizeof(int));
	el = (int*)malloc(arc * sizeof(int));
	ee = (int*)malloc(arc * sizeof(int));
	Arcnode *p;
	for (i = 0; i < vex; i++)
		ve[i] = 0;
	for (i = 0; i < vex; i++)
	{
		if (G[i].id == 0)
			topology[++rear] = i;
		m++;
	}
	while (front != rear)
	{
		front++;
		j = topology[front];
		m++;
		p = G[j].firstarc;
		while (p)
		{
			k = p->adjvex;
			G[k].id--;
			if (ve[j] + p->weight > ve[k])
				ve[k] = ve[j] + p->weight;
			if (G[k].id == 0)
				topology[++rear] = k;
			p = p->nextarc;
		}
	}
	if (m < vex)
	{
		printf("A loop was detected in this graph.\n");
		return 0;
	}
	totaltime = ve[vex - 1];
	for (i = 0; i < vex; i++)
		vl[i] = totaltime;
	for (i = vex - 2; i >= 0; i--)
	{
		j = topology[i];
		p = G[j].firstarc;
		while (p)
		{
			k = p->adjvex;
			if ((vl[k] - p->weight) < vl[j])
				vl[j] = vl[k] - p->weight;
			p = p->nextarc;
		}
	}
	i = 0;
	int n = 0;
	for (j = 0; j < vex; j++)
	{
		p = G[j].firstarc;
		while (p)
		{
			k = p->adjvex;
			ee[++i] = ve[j];
			el[i] = vl[k] - p->weight;
			if (el[i] == ee[i])
			{
				path1[n].begin = G[j].data;
				path1[n].end = G[k].data;
				n++;
				sv[t] = G[j].data; t++;
			}
			p = p->nextarc;
		}
	}
	int path2[MAX];
	int first, a, temp[MAX];
	int sum = 1;
	for (i = 0; i < n; i++)
	{
		temp[i] = path1[i].begin;
	}
	first = temp[0];
	for (i = 0; i < n; i++)
	{
		if (first > temp[i])
			first = temp[i];
	}
	path2[0] = first;
	int flag = 1;
	if (flag)
	{
		for (i = 0; i < n; i++)
		{
			if (path1[i].begin == first)
			{
				path2[1] = path1[i].end;
				break;
			}
			else
				flag = 0;
		}
	}
	for (j = 1; flag != 0; j++)
	{
		for (i = 0; i < n; i++)
		{
			if (path1[i].begin == path2[j])
			{
				path2[j+1] = path1[i].end;
				sum++;
				break;
			}
			else
				flag = 0;
		}
	}
	
	
	printf("max length: %d\n", totaltime);
	printf("%d", path2[0] - 1);
	for (i = 1; i <= sum; i++)
	{
		printf(" -> %d", path2[i] - 1);

	}
	printf("\n");
	return 1;
}
