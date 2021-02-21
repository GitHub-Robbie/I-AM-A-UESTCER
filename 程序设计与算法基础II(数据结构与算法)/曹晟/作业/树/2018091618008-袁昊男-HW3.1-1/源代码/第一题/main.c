#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

int main()
{
	int N;
	scanf("%d", &N);
	int* preOrder = (int*)malloc(N * sizeof(int));
	int* inOrder = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		scanf("%d", &preOrder[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &inOrder[i]);
	}
	Node* root = createTree(preOrder, inOrder, N);
	printf("�����ĸ߶���: %d\n", getTreeHeight(root));
	printf("�����Ŀ����: %d\n", getTreeWidth(root));
	printf("������Ҷ�ڵ������: %d\n", countLeafNode(root));
	Node* newTreeRoot = mirrorCloneTree(root);
	printf("�����ľ������Ĳ�α�������Ϊ:\n");
	levelOrderTraversal(newTreeRoot);
	destoryTree(&root);
	destoryTree(&newTreeRoot);
	return 0;
}