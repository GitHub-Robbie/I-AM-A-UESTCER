#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkbitree.h"

int i = 0;

void InitBitree(Bitreeptr tree)
{
	tree->root = NULL;
	tree->depth = 0;
	tree->length = 0;
}

int CreateBitree(Binodeptr *root)
{
	type input;
	input = getchar();
	getchar();
	if (input == '#')
	{
		*root = NULL;
		return 0;
	}
	else
	{
		*root = (Binode*)malloc(sizeof(Binode));
		if (!root)
			printf("Fail to create a tree!\n");
		(*root)->data = input;
		CreateBitree(&((*root)->lchild));
		CreateBitree(&((*root)->rchild));
	}
}

void PreorderTraverse(Binodeptr root, char order[])
{
	if (root == NULL)
	{
		order[i++] = '#';
		return;
	}
	order[i++] = root->data;
//	printf("%c", root->data);
	PreorderTraverse(root->lchild,order);
	PreorderTraverse(root->rchild,order);
}

void InorderTraverse(Binodeptr root, char order[])
{
	int i = 0;
	Binodeptr s[MAXSIZE];
	Binodeptr p = root;
	int top = -1;
	if (root == NULL)
		return;
	while (p != NULL || top != -1)
	{
		while (p != NULL)
		{
			if (top < MAXSIZE - 1)
				s[++top] = p;
			else
				printf("Overflow!\n");
			p = p->lchild;
		}
		if (top == -1)
			return;
		else
		{
			p = s[top--];
			if (p->lchild == NULL)
				order[i++] = '#';
			order[i++] = p->data;
			if (p->rchild == NULL)
				order[i++] = '#';
			p = p->rchild;
		}
	}
}

void PostorderTraverse(Binodeptr root, char order[])
{
	int i = 0;
	int flag = 0;
	Binodeptr s[MAXSIZE];
	Binodeptr r, t, p = root;
	int top = -1;
	do
	{
		if (p != NULL)
		{
			while (p != NULL)
			{
				s[++top] = p;
				p = p->lchild;
			}
			order[i++] = '#';
		}
		else
		{
			r = NULL;
			flag = 1;
			while (top != -1 && flag)
			{
				p = s[top];
				if (p->rchild == r)
				{
					if (p->rchild == NULL)
						order[i++] = '#';
					order[i++] = p->data;
					r = p;
					p = s[--top];
				}
				else
				{
					p = p->rchild;
					flag = 0;
				}
			}
		}
	} while (top != -1);
}

void PrintOrder(char order[])
{
	char *p = &order[0];
	printf("%c", *p);
	p++;
	while (*p != '\0')
	{
		printf(", %c", *p);
		p++;
	}
	printf("\n");
}

void CreateFile()
{
	FILE* fp;
	fp = fopen("preorder.dat", "w");
	if (!fp)
	{
		printf("Fail to create file!");
		exit(0);
	}
	fclose(fp);
}

void SaveToFile(char order[], FILE *fp)
{
	fp = fopen("preorder.dat", "w");
	if (fp == NULL)
	{
		printf("Fail to open file!");
		exit(0);
	}
	char *p = &order[0];
	while (*p != '\0')
	{
		fprintf(fp, "%c", *p);
		p++;
	}
	fclose(fp);
}

void ReadFromFile(char order[], FILE *fp)
{
	if ((fp = fopen("preorder.dat", "r")) == NULL)
	{
		printf("Fail to open file!");
		exit(0);
	}
	fscanf(fp, "%s", order);
}

int k = 0;
void CreateRecursive(char order[], Binodeptr *root)
{
	type input;
	input = order[k++];
	if (input == '#')
	{
		*root = NULL;
		return 0;
	}
	else
	{
		*root = (Binode*)malloc(sizeof(Binode));
		if (!root)
			printf("Fail to create a tree!\n");
		(*root)->data = input;
		CreateRecursive(order, &((*root)->lchild));
		CreateRecursive(order, &((*root)->rchild));
	}
}

void CreateNonrecursive(char order[], Binodeptr *root)
{
	*root = (Binode*)malloc(sizeof(Binode));
	int j = 0;
	type input;
	Binodeptr back, origin;
	back = (Binode*)malloc(sizeof(Binode));
	origin = (Binode*)malloc(sizeof(Binode));
	origin = *root;
	Binodeptr s[MAXSIZE];
	int top = -1;
	input = order[j++];
	(*root)->data = input;
	s[++top] = *root;
	input = order[j++];
	Binodeptr p, q, r;
	p = (Binodeptr)malloc(sizeof(Binode));
	(*root)->lchild = p;
	*root = (*root)->lchild;
	while (top != -1)
	{
		if (input != '#')
		{
			(*root)->data = input;
			s[++top] = *root;
			q = (Binodeptr)malloc(sizeof(Binode));
			(*root)->lchild = q;
			*root = (*root)->lchild;
			input = order[j++];
		}
		else if (input == '#')
		{
			*root = NULL;
			r = (Binodeptr)malloc(sizeof(Binode));
			s[top]->rchild = r;
			*root = s[top--]->rchild;
			input = order[j++];
		}
	}
	s[++top] = origin;
	r = (Binodeptr)malloc(sizeof(Binode));
	origin->rchild = r;
	*root = origin->rchild;
	while (top != -1)
	{
		if (input != '#')
		{
			(*root)->data = input;
			s[++top] = *root;
			q = (Binodeptr)malloc(sizeof(Binode));
			(*root)->lchild = q;
			*root = (*root)->lchild;
			input = order[j++];
		}
		else if (input == '#')
		{
			*root = NULL;
			r = (Binodeptr)malloc(sizeof(Binode));
			s[top]->rchild = r;
			*root = s[top--]->rchild;
			input = order[j++];
		}
	}
	*root = origin;
}

void Destroy(Binodeptr root)
{
	if (root == NULL)
		return;
	Destroy(root->lchild);
	Destroy(root->rchild);
	free(root);
}