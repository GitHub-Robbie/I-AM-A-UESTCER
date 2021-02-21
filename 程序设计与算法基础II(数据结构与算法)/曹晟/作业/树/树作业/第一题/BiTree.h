#pragma once
typedef struct node
{
	int data;
	struct node *lchild, *rchild;
}Node, *NodePtr;

typedef struct Node {
	int data;
	Node *next;
}LinkQueueNode;

typedef struct {
	LinkQueueNode *Front;
	LinkQueueNode *Rear;
}LinkQueue;

Node* createTree(int preOrder[], int inOrder[], int N);
int getTreeHeight(Node* root);
int getTreeWidth(Node* root);
int countLeafNode(Node* root);
Node* mirrorCloneTree(Node* root);
void levelOrderTraversal(Node* root);
int init_Queue(LinkQueue *Q);
int EnterQueue(LinkQueue *Q, int x);
int Delete_Queue(LinkQueue *Q, int *x);
int Is_empty(LinkQueue *Q);
void destoryTree(Node** root);