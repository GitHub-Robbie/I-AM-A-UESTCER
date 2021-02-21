#pragma once
#define MAX 100
#define INF 32767
typedef int InfoType;

typedef struct Anode
{
	int adjvex;
	int weight;
	struct Anode *nextarc;
} Arcnode;

typedef struct Vnode
{
	InfoType data;
	int id;
	Arcnode *firstarc;
} Vexnode;

typedef struct path
{
	int begin;
	int end;
} Path;

void CreateGraph(Vexnode* G, int vex, int arc);
int SearchMapPath(Vexnode* G, int vex, int arc);