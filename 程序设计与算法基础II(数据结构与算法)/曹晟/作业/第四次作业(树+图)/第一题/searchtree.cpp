#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
	int key;
	struct Node* parent;    //ע������Ľڵ�������ڵ�ָ��
	struct Node *lchild, *rchild;
}Node;

Node* createNode(int key) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->key = key;
	temp->lchild = temp->rchild = temp->parent = NULL;
	return temp;
}

//�����в���һ���ڵ�
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

//����������Сֵ�ڵ��λ��
Node* minimum(Node* root) {
	if (!root)
		return NULL;
	else if (!root->lchild)
		return root;
	else
		return minimum(root->lchild);
}

//���ظ����������������ʼ�ڵ��λ��
Node* begin(Node* root) {
	return minimum(root);
}

//����������������иýڵ����һ���ڵ��λ��
//����ýڵ��Ѿ������е����һ���ڵ㣬�򷵻�NULL
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

//�������������һ���ڵ����һ���ڵ��λ�ã�Ҳ����NULL
Node* end(Node* root) {
	return NULL;
}

int main() {
	Node* root = NULL;  //һ�ÿ���
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		insert(root, x);
	}

	//����һ���������
	for (Node* p = begin(root); p != end(root); p = next(p)) {
		printf("%d ", p->key);
	}
	printf("\n");
	system("pause");
	return 0;
}