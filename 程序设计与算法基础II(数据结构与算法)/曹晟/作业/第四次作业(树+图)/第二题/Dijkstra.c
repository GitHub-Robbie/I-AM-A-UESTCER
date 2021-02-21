#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"

void CreateGraph(MatGraph *G, int n, int e)
{
	int vi, vj, w, i, j;
	G->n = n;
	G->e = e;
	for(i = 0; i < n; i++)
		for (j = 0; j < n; j++)		//图的初始化
		{
			if (i == j)
				G->edges[i][j] = 0;
			else
				G->edges[i][j] = INF;
		}
	for (i = 0; i < e; i++)			//边的信息
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		G->edges[a][b] = c;
	}
	for (i = 0; i < n; i++)
		G->vexs[i].no = i;
}

void DispGraph(MatGraph G)
{
	int i, j;
	for (i = 0; i < G.n; i++)
	{
		for (j = 0; j < G.n; j++)
		{
			if (G.edges[i][j] == INF)
				printf("%6s", "∞");
			else
				printf("6d", G.edges[i][j]);
		}
		printf("\n");
	}
}

void Dijkstra(MatGraph G, int v, int t)
{
	int dist[MAX], path[MAX];
	int S[MAX];
	int MINdis, i, j, u;
	for (i = 0; i < G.n; i++)
	{
		dist[i] = G.edges[v][i];
		S[i] = 0;
		if (G.edges[v][i] < INF)
			path[i] = v;
		else
			path[i] = -1;
	}
	S[v] = 1;
	path[v] = 0;
	for (i = 0; i < G.n - 1; i++)
	{
		MINdis = INF;
		for (j = 0; j < G.n; j++)
			if (S[j] == 0 && dist[j] < MINdis)
			{
				u = j;
				MINdis = dist[j];
			}
		S[u] = 1;
		for(j = 0; j < G.n; j++)
			if (S[j] == 0)
				if (G.edges[u][j] < INF && dist[u] + G.edges[u][j] < dist[j])
				{
					dist[j] = dist[u] + G.edges[u][j];
					path[j] = u;
				}
	}
	DisPath(G, dist, path, S, v, t);
}

void DisPath(MatGraph G, int dist[], int path[], int S[], int v, int t)
{
	int i, j, k;
	int apath[MAX], d;
//	for (i = 0; i < G.n; i++)
		if (S[t] == 1 && t != v)
		{
			printf("min distance: %d\n", dist[t]);
			d = 0;
			apath[d] = t;
			k = path[t];
			if (k == -1)
				printf("no path!");
			else
			{
				while (k != v)
				{
					d++;
					apath[d] = k;
					k = path[k];
				}
				d++; apath[d] = v;
				printf("%d", apath[d]);
				for (j = d - 1; j >= 0; j--)
					printf(" -> %d", apath[j]);
			}
		}
		printf("\n"); 
}