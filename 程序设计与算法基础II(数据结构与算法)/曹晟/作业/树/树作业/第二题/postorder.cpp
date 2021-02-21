#include <iostream>
using namespace std;

struct Node {
	int data;
	int size = 1;
	Node *lchild, *rchild;
	Node(int x = 0) { data = x; lchild = rchild = NULL; }
	void setChildNode(Node* l, Node* r) {
		lchild = l;
		rchild = r;
	}
};
Node* stack[20];

int generateEachNodeSize(Node* root) {//需要的话你可以把该函数的返回值改为int类型
	if (root != NULL)
	{
		root->size = 1 + generateEachNodeSize(root->lchild) + generateEachNodeSize(root->rchild);
		return root->size;
	}
	if (root == NULL)
		return 0;
}

Node* rankInPostorder(Node* t, int k, int i) {
	int n = 0;
	if (t != NULL)
	{
		
		if (t->lchild != NULL)
		{
			if (t->lchild->size >= k)
				t = t->lchild;
			else if (t->lchild->size < k)
			{
				if (t->rchild != NULL)
				{
					if (t->lchild->size + t->rchild->size >= k)
					{
						k = k - t->lchild->size;
						t = t->rchild;
					}
					else
					{
						stack[i] = t;
						n = 1;
					}
				}
				else
				{
					stack[i] = t;
					n = 1;
				}
			}
		}
		else if (t->lchild == NULL && t->rchild != NULL && t->rchild->size >= k)
			t = t->rchild;
		else if (t->lchild == NULL && t->rchild == NULL)
		{
			stack[i] = t;
			n = 1;
		}
		else
		{
			stack[i] = t;
			n = 1;
		}
		if (n == 0)
			rankInPostorder(t, k, i);
	}
	return t;
}
//计算每个节点的size的值


int main() {
	Node* root = new Node(1);
	Node* node_2 = new Node(2);
	Node* node_3 = new Node(3);
	Node* node_4 = new Node(4);
	Node* node_5 = new Node(5);
	Node* node_6 = new Node(6);
	Node* node_7 = new Node(7);
	Node* node_8 = new Node(8);
	root->setChildNode(node_2, node_3);
	node_2->setChildNode(node_4, node_5);
	node_3->setChildNode(NULL, node_7);
	node_5->setChildNode(node_6, NULL);
	node_4->setChildNode(NULL, node_8);
	generateEachNodeSize(root);
	for (int i = 1; i <= 8; i++) {
		rankInPostorder(root, i, i);
		Node* p = stack[i];
		printf("%d ", p->data);
	}
	printf("\n");
	system("pause");
	return 0;
}