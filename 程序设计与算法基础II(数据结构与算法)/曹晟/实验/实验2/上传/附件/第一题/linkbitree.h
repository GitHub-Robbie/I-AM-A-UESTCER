#pragma once
#define MAXSIZE 100
#define bool int
typedef char type;

typedef struct node
{
	type data;
	struct node* lchild;
	struct node* rchild;
} Binode;
typedef Binode* Binodeptr;

typedef struct tree
{
	Binodeptr root;
	int length;
	int depth;
} Bitree;
typedef Bitree* Bitreeptr;

void InitBitree(Bitreeptr tree);
int CreateBitree(Binodeptr *root);
void PreorderTraverse(Binodeptr root, char order[]);
void InorderTraverse(Binodeptr root, char order[]);
void PostorderTraverse(Binodeptr root, char order[]);
void PrintOrder(char order[]);
void SaveToFile(char order[], FILE *fp);
void CreateFile();
void ReadFromFile(char order[], FILE *fp);
void CreateRecursive(char order[], Binodeptr *root);
void CreateNonrecursive(char order[], Binodeptr *root);
void Destroy(Binodeptr root);
