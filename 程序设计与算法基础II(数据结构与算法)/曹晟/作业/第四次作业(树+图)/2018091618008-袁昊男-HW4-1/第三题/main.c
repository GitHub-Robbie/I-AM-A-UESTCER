#include <stdio.h>
#include <stdlib.h>
#include "critical path.h"

int main()
{
	int vex, arc, totaltime = 0;
	scanf("%d%d", &vex, &arc);
	Vexnode* Graph = (Vexnode*)malloc(vex * sizeof(Vexnode));
	CreateGraph(Graph, vex, arc);
	SearchMapPath(Graph, vex, arc);
	system("pause");
	return 0;
}