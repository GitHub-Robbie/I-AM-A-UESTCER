#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkbitree.h"

int main()
{
	Bitreeptr B1, B2, B3;
	Binodeptr root1;
	Binodeptr *root2, *root3;
	char yn;
	int i = 0;
	FILE* fp = NULL;
	B1 = (Bitree*)malloc(sizeof(Bitree));
	B2 = (Bitree*)malloc(sizeof(Bitree));
	B3 = (Bitree*)malloc(sizeof(Bitree));
	root1 = (Binode*)malloc(sizeof(Binode));
	root2 = (Binodeptr*)malloc(sizeof(Binodeptr));
	root3 = (Binodeptr*)malloc(sizeof(Binodeptr));
	B1->root = root1;
	B2->root = (*root2);
	B3->root = (*root3);
	printf("*************************************************\n");
	printf("*        二叉树的链式存储、序列化和反序列化     *\n");
	printf("*************************************************\n\n");
	printf("请输入二叉树结点信息, 以#表示空结点: \n");
	InitBitree(B1);
	CreateBitree(&root1);
	printf("\n");
	printf("二叉树B1创建成功! \n\n");
	char B1order[MAXSIZE] = { '*' };
	char B2order[MAXSIZE] = { '*' };
	char B3order[MAXSIZE] = { '*' };
	char preorder[] = { '\0' };
	printf("先序序列化: \n");
	PreorderTraverse(root1, B1order, i);
	PrintOrder(B1order);
	CreateFile();
	SaveToFile(B1order, fp);
	printf("序列已存储至preorder.dat文件中!\n");
	printf("\n");
	ReadFromFile(preorder, fp);
	printf("从文件中读取序列成功!\n");
	printf("\n");
	InitBitree(B2);
	CreateRecursive(preorder, root2);
	printf("递归反序列化创建树B2成功!\n");
	InitBitree(B3);
	CreateNonrecursive(preorder, root3);
	printf("非递归反序列化创建树B3成功!\n");
	printf("\n");
	InorderTraverse(root1, B2order);
	printf("非递归中序遍历树B2序列: \n");
	PrintOrder(B2order);

	PostorderTraverse(root1, B3order);
	printf("非递归后序遍历树B3序列: \n");
	PrintOrder(B3order);
	printf("\n");
	printf("是否销毁二叉树B1、B2、B3? (y/n): ");
	scanf("%c", &yn);
	if (yn == 'y')
	{
		free(root1);
		free(root2);
		free(root3);
		printf("销毁完毕!\n");
	}
	else
		exit(1);
	system("pause");
	return 0;
}

