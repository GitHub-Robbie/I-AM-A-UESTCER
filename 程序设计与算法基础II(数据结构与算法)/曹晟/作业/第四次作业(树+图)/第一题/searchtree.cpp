#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
	int key;
	struct Node* parent;    //注意该树的节点包含父节点指针
	struct Node *lchild, *rchild;
}Node;

Node* createNode(int key) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->key = key;
	temp->lchild = temp->rchild = temp->parent = NULL;
	return temp;
}

//在树中插入一个节点
Node* insert(Node* &root, int key) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->key = key;
	p->lchild = NULL;
	p->rchild = NULL;

	if (root == NULL)
	{
		root = p;
		return root;
	}
	Node* q = root;
	Node* parent;
	do
	{
		parent = q;
		if (parent->key > key)
			q = parent->lchild;
		else
			q = parent->rchild;
	} while (q != NULL);

	if (parent->key > key)
	{
		parent->lchild = p;
		p->parent = parent;
	}
	else
	{
		parent->rchild = p;
		p->parent = parent;
	}
	return p;
}

//返回树中最小值节点的位置
Node* minimum(Node* root) {
	if (!root)
		return NULL;
	else if (!root->lchild)
		return root;
	else
		return minimum(root->lchild);
}

//返回该树中序遍历序列起始节点的位置
Node* begin(Node* root) {
	return minimum(root);
}

//返回中序遍历序列中该节点的下一个节点的位置
//如果该节点已经是序列的最后一个节点，则返回NULL
Node* next(Node* current) {
	if (current->rchild)
	{
		current = current->rchild;
		while (current->lchild)
			current = current->lchild;
		return current;
	}
	else if (current->parent->rchild == current && (!current->rchild))
		if (current->key > current->parent->parent->key)
			return NULL;
		else
			return current->parent->parent;
	else if (current->parent->parent == NULL && current->parent->lchild == current)
		return current->parent;
	else if ((!current->rchild) && current->parent->lchild == current)
		return current->parent;
}

//返回序列中最后一个节点的下一个节点的位置，也就是NULL
Node* end(Node* root) {
	return NULL;
}

int main() {
	Node* root = NULL;  //一棵空树
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		insert(root, x);
	}

	//进行一次中序遍历
	for (Node* p = begin(root); p != end(root); p = next(p)) {
		printf("%d ", p->key);
	}
	printf("\n");
	system("pause");
	return 0;
}