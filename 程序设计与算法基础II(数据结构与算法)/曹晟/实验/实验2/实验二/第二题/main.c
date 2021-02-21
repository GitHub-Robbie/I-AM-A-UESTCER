//2019.06.21
//���ݽṹ ʵ��� �ڶ���
//��԰���·����ѯϵͳ
//����: @���ݷ�
//ת����ע������

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"

int main()
{
	int n, edge;
	int i, j, k;
	int sum;
	Info info[MAXSISE];
	Path output[MAXSISE];
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	int A[MAXV][MAXV];
	int path[MAXV][MAXV];
	LinkListPtr list = NULL;
	//ͼ��ʼ��
	MatGraph *g;
	g = (MatGraph*)malloc(sizeof(MatGraph));

	int opt = 1;
	char yn;
	while (opt != 6)
	{
		system("cls");
		printf("*****************************************************\n");
		printf("*             ��ӭʹ�ù�԰���·����ѯϵͳ          *\n");
		printf("*****************************************************\n");
		printf("*\t      [1] ¼�뾰��·����Ϣ\t            *\n");
		printf("*\t      [2] ֱ�Ӳ�ѯָ����������·��        *\n");
		printf("*\t      [3] ��ѯ���о���Լ�����·��        *\n");
		printf("*\t      [4] ����·������\t\t            *\n");
		printf("*\t      [5] ���ٲ�ѯָ����������·��        *\n");
		printf("*\t      [6] �˳�����\t\t            *\n");
		printf("*****************************************************\n");
		printf("\n");
		printf("����������ѡ��: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			system("cls");
			printf("\t\t*��ǰ����: [1] ¼�뾰��·����Ϣ*\n");
			printf("˵��: \n��Ϣ¼���ʽ: ����A ����B ·������\n\n");
			printf("�����뾰�����: ");
			scanf("%d", &n);
			printf("������·������: ");
			scanf("%d", &edge);
			(*g).n = n;
			(*g).e = edge;
			printf("�밴��ʽ¼����Ϣ: \n\n");
			Info_Input(edge, info);
			Create_File();
			Info_Output(edge, info, fp1);
			Graph_Init(g, n, edge, info);
			printf("\n");
			printf("��Ϣ��¼����ɲ�����! \n");
			printf("�Ƿ񷵻�������? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
				case 'y': break;
				case 'n': exit(1);
			}
			break;
		case 2:
			system("cls");
			printf("\t*��ǰ����: [2] ֱ�Ӳ�ѯָ����������·��*\n");
			Floyd(g, A, path);
			Dispath1(g, A, path);
			printf("\n");
			printf("�Ƿ񷵻�������? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 3:
			system("cls");
			printf("\t*��ǰ����: [3] ��ѯ���о���Լ�����·��*\n");
			sum = Dispath_All(g, A, path, output);
			Path_Output(sum, output, fp2);
			printf("����·����ѯ��ɲ�����! \n");
			printf("�Ƿ񷵻�������? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 4:
			system("cls");
			printf("\t\t*��ǰ����: [4] ����·������*\n");
			Init_List(&list);
			Create_List(sum, output, &list);
			printf("\n");
			printf("���ļ����������! \n");
			printf("�Ƿ񷵻�������? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 5:
			system("cls");
			printf("\t*��ǰ����: [5] ���ٲ�ѯָ����������·��*\n");
			printf("\n");
			List_Query(&list);
			printf("\n");
			printf("�Ƿ񷵻�������? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		default:
			exit(1);
		}
	}

	system("pause");
	return 0;
}