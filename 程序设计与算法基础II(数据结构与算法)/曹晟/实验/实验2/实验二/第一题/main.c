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
	printf("*        ����������ʽ�洢�����л��ͷ����л�     *\n");
	printf("*************************************************\n\n");
	printf("����������������Ϣ, ��#��ʾ�ս��: \n");
	InitBitree(B1);
	CreateBitree(&root1);
	printf("\n");
	printf("������B1�����ɹ�! \n\n");
	char B1order[MAXSIZE] = { '*' };
	char B2order[MAXSIZE] = { '*' };
	char B3order[MAXSIZE] = { '*' };
	char preorder[] = { '\0' };
	printf("�������л�: \n");
	PreorderTraverse(root1, B1order, i);
	PrintOrder(B1order);
	CreateFile();
	SaveToFile(B1order, fp);
	printf("�����Ѵ洢��preorder.dat�ļ���!\n");
	printf("\n");
	ReadFromFile(preorder, fp);
	printf("���ļ��ж�ȡ���гɹ�!\n");
	printf("\n");
	InitBitree(B2);
	CreateRecursive(preorder, root2);
	printf("�ݹ鷴���л�������B2�ɹ�!\n");
	InitBitree(B3);
	CreateNonrecursive(preorder, root3);
	printf("�ǵݹ鷴���л�������B3�ɹ�!\n");
	printf("\n");
	InorderTraverse(root1, B2order);
	printf("�ǵݹ����������B2����: \n");
	PrintOrder(B2order);

	PostorderTraverse(root1, B3order);
	printf("�ǵݹ���������B3����: \n");
	PrintOrder(B3order);
	printf("\n");
	printf("�Ƿ����ٶ�����B1��B2��B3? (y/n): ");
	scanf("%c", &yn);
	if (yn == 'y')
	{
		free(root1);
		free(root2);
		free(root3);
		printf("�������!\n");
	}
	else
		exit(1);
	system("pause");
	return 0;
}

