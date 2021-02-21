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
	printf("该树的高度是: %d\n", getTreeHeight(root));
	printf("该树的宽度是: %d\n", getTreeWidth(root));
	printf("该树的叶节点个数是: %d\n", countLeafNode(root));
	Node* newTreeRoot = mirrorCloneTree(root);
	printf("该树的镜像树的层次遍历序列为:\n");
	levelOrderTraversal(newTreeRoot);
	destoryTree(&root);
	destoryTree(&newTreeRoot);
	return 0;
}