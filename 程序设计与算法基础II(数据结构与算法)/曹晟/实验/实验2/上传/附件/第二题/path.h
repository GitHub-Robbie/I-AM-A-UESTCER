#pragma once
#define MAXV 7
#define MAXSISE 100
#define INF 32767

typedef struct info
{
	char begin[10];
	char end[10];
	int weight;
} Info;

typedef struct name
{
	char name[10];
} Name;

typedef struct vertex
{
	int no;
	char name[10];
} VertexType;

typedef struct matgraph
{
	int edges[MAXV][MAXV];
	int n, e;
	VertexType vexs[MAXV];
} MatGraph;

typedef struct outputpath
{
	char path[50];
	int length;
	char begin[10];
	char end[10];
	int flag;
} Path;

typedef struct node
{
	char begin[10];
	char end[10];
	char path[50];
	int length;
	struct Node *next;
} Node, *Nodeptr;
typedef Nodeptr *LinkListPtr;

void Info_Input(int n, Info info[]);
void Create_File();
void Info_Output(int n, Info info[], FILE *fp);
void Graph_Init(MatGraph *g, int n, int edge, Info info[]);
void Floyd(MatGraph *g, int A[MAXV][MAXV], int path[MAXV][MAXV]);
void Dispath1(MatGraph *g, int A[][MAXV], int path[][MAXV]);
int Dispath_All(MatGraph *g, int A[][MAXV], int path[][MAXV], Path output[]);
int MatchNo(MatGraph *g, char name[10]);
void MatchName(MatGraph *g, int no);
void Path_Output(int n, Path output[], FILE *fp);
void Init_List(LinkListPtr list);
void Create_List(int n, Path output[], LinkListPtr list);
void List_Query(LinkListPtr list);