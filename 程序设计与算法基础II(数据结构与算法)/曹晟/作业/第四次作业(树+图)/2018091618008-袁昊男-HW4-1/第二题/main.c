#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"

int main()
{
	int n, e, v, t;
	scanf("%d%d%d%d", &n, &e, &v, &t);
	MatGraph G;
	VertexType Vertex;
	CreateGraph(&G, n, e);
	Dijkstra(G, v, t);
	system("pause");
	return 0;
}