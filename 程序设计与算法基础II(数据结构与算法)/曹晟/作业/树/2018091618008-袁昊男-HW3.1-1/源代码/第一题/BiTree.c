#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

#define MAXSIZE 50

Node* createTree(int preOrder[], int inOrder[], int N)
{
	int i;
	int lpre[MAXSIZE], rpre[MAXSIZE];
	int lin[MAXSIZE], rin[MAXSIZE];
	int n1 = 0, n2 = 0;
	int m1 = 0, m2 = 0;
	if (N == 0)
		return NULL;
	Node* T = (Node*)malloc(sizeof(Node));
	T->data = preOrder[0];
	for (i = 0; i < N; i++)
	{
		if (i <= n1 && inOrder[i] != preOrder[0])
		{
			lin[n1++] = inOrder[i];
		}
		else if (inOrder[i] != preOrder[0])
		{
			rin[n2++] = inOrder[i];
		}
	}
	for (i = 1; i < N; i++)
	{
		if (i < (n1 + 1))
		{
			lpre[m1++] = preOrder[i];
		}
		else
		{
			rpre[m2++] = preOrder[i];
		}
	}
	T->lchild = createTree(lpre, lin, n1);
	T->rchild = createTree(rpre, rin, n2);
	return T;
}

int getTreeHeight(Node* root)
{
	int rheight = 0;
	int lheight = 0;
	if (root == NULL)
		return 0;
	if (root->lchild != NULL)
		lheight = getTreeHeight(root->lchild);
	else
		lheight = 0;
	if (root->rchild != NULL)
		rheight = getTreeHeight(root->rchild);
	else
		rheight = 0;
	return (rheight > lheight) ? rheight + 1 : lheight + 1;
}

int getTreeWidth(Node* root)
{
	int width[MAXSIZE];
	int i = 0;
	for (i = 0; i < MAXSIZE; i++)
		width[i] = 0;
	int maxwidth = 0;
	int floor = 1;
	if (root)
	{
		if (floor == 1)
		{
			width[floor]++;
			floor++;
			if (root->lchild)
				width[floor]++;
			if (root->rchild)
				width[floor]++;
		}
		else
		{
			floor++;
			if (root->lchild)
				width[floor]++;
			if (root->rchild)
				width[floor]++;
		}
		if (maxwidth < width[floor])
			maxwidth = width[floor];
		getTreeWidth(root->lchild);
		floor--;
		getTreeWidth(root->rchild);
	}
	return maxwidth + 1;
}

int countLeafNode(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->lchild == NULL && root->rchild == NULL)
	{
		return 1;
	}
	return countLeafNode(root->lchild) + countLeafNode(root->rchild);
}

Node* mirrorCloneTree(Node* root)
{
	if (root != NULL)
	{
		Node* pRight = root->rchild;
		Node* pLeft = root->lchild;
		root->lchild = mirrorCloneTree(pRight);
		root->rchild = mirrorCloneTree(pLeft);
	}
	return root;
}

void levelOrderTraversal(Node* root)
{
	if (root == NULL)
		return;
	LinkQueue LQ;
	init_Queue(&LQ);

	EnterQueue(&LQ, root);

	Node* temp;
	while (!Is_empty(&LQ))
	{
		if (Delete_Queue(&LQ, &temp))
			printf("%d ", temp->data);
		if (temp->lchild) EnterQueue(&LQ, temp->lchild);
		if (temp->rchild) EnterQueue(&LQ, temp->rchild);
	}
	printf("\n");

}

int init_Queue(LinkQueue *Q)
{
	Q->Front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (Q->Front != NULL) {
		Q->Rear = Q->Front;
		Q->Front->next = NULL;
		return 1;
	}
	else
		return 0;
}

int EnterQueue(LinkQueue *Q, int x)
{
	LinkQueueNode *NewNode;
	NewNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (NewNode != NULL) {
		NewNode->data = x;
		NewNode->next = NULL;
		Q->Rear->next = NewNode;
		Q->Rear = NewNode;
		return 1;
	}
	else
		return 0;
}

int Delete_Queue(LinkQueue *Q, int *x)
{
	if (Q->Front == Q->Rear) {
		return 0;
	}
	LinkQueueNode *p;

	p = Q->Front->next;
	Q->Front->next = p->next;
	if (Q->Rear == p) {
		Q->Rear = Q->Front;
	}
	*x = p->data;
	free(p);
	return 1;
}

int Is_empty(LinkQueue *Q)
{
	if (Q->Front == Q->Rear)
		return 1;
	return 0;
}

void destoryTree(Node** root)
{
	if (root == NULL)
	{
		return;
	}
	if (*root == NULL)
	{
		return;
	}
	destoryTree(&(*root)->lchild);
	destoryTree(&(*root)->rchild);
	free(root);
	*root = NULL;
	return;
}
