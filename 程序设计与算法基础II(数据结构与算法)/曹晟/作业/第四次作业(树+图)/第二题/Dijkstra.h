#pragma once
#define MAX 100
#define INF 32767
typedef char InfoType;

typedef struct
{
	int no;
	InfoType info;
} VertexType;

typedef struct
{
	int edges[MAX][MAX];
	int n, e;
	VertexType vexs[MAX];
} MatGraph;

void CreateGraph(MatGraph *G, int n, int e);
void DispGraph(MatGraph G);
void Dijkstra(MatGraph G, int v, int t);
void DisPath(MatGraph G, int dist[], int path[], int S[], int v, int t);
