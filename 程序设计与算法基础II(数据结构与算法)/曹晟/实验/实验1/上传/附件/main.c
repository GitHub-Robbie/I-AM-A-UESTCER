#include <stdio.h>
#include <stdlib.h>
#include "grade_inquiry.h"

#define N 10
#define course 3

int main()
{
	Student s1[N], s2[N], rs[N];
	Course c1[course], c2[course];
	Grade g1[N*course], g2[N*course];
	Connect A[N*course], ICno[N], ICno1[N], ISno[course], ISno1[course];
	StudentListPtr SList = NULL;
	CourseListPtr CList = NULL;
	GradeListPtr GList = NULL;
	ConnectListPtr AList = NULL;
	StudentListPtr RSList = NULL;

	Create_File();
	FILE *fp1 = NULL, *fp2 = NULL, *fp3 = NULL, *fp4 = NULL;

	int opt = 1;
	int cno;
	int k;
	int sno;
	int q;
	char yn;
	Stack *s = NULL;
	StackPtr ptr = NULL;
	QueuePtr queue;
	while (opt != 12)
	{
		system("cls");
		printf("*****************************************************\n");
		printf("*             ��ӭʹ��ѧ���ɼ���ѯϵͳ!             *\n");
		printf("*****************************************************\n");
		printf("*\t      [1] ¼��ѧ����Ϣ\t\t            *\n");
		printf("*\t      [2] ¼��γ���Ϣ\t\t            *\n");
		printf("*\t      [3] ¼��ɼ���Ϣ\t\t            *\n");
		printf("*\t      [4] ��ȡ����ʾѧ����Ϣ\t            *\n");
		printf("*\t      [5] ��ȡ����ʾ�γ���Ϣ\t            *\n");
		printf("*\t      [6] ��ȡ����ʾ�ɼ���Ϣ\t            *\n");
		printf("*\t      [7] ��ѯ����ѧ�����пγ̵Ŀ��Գɼ�    *\n");
		printf("*\t      [8] ��ѯָ���γ̺ŵ�����ѧ�����Գɼ�  *\n");
		printf("*\t      [9] ��ѯָ��ѧ��ѧ�������п��Գɼ�    *\n");
		printf("*\t      [10] ʹ��ջ��ѧ����Ϣ����\t\t    *\n");
		printf("*\t      [11] ʹ����ʽ�������[7]\t\t    *\n");
		printf("*\t      [12] �˳�����\t\t\t    *\n");
		printf("*****************************************************\n");
		printf("\n");
		printf("˵��: ѧ����4λ����, ��1001; \n      �γ̺���6λ����, ��201801; \n      �ɼ�������������.\n");
		printf("\n");
		printf("����������ѡ��: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			system("cls");
			printf("\t\t*��ǰ����: [1] ¼��ѧ����Ϣ*\n");
			printf("\n");
			Input_Student(s1, N, fp1);
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
			printf("\t\t*��ǰ����: [2] ¼��γ���Ϣ*\n");
			printf("\n");
			Input_Course(c1, course, fp2);
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
			printf("\t\t*��ǰ����: [3] ¼��ɼ���Ϣ*\n");
			printf("\n");
			Input_Grade(g1, N*course, fp3);
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
			printf("\t\t*��ǰ����: [4] ��ȡ����ʾѧ����Ϣ*\n");
			printf("\n");
			Output_Student(s2, fp1, N);
			SList_Create(&SList, s2, N);
			printf("����ѧ����Ϣ: \n");
			printf("ѧ��\t����\t�Ա�\tרҵ\n");
			//Print_Student(s2, N);
			Print_StudentList(&SList, N);
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
			printf("\t\t*��ǰ����: [5] ��ȡ����ʾ�γ���Ϣ*\n");
			printf("\n");
			Output_Course(c2, fp2, course);
			CList_Create(&CList, c2, course);
			printf("���пγ���Ϣ: \n");
			printf("�γ̺�\t�γ�����\t��ʱ\n");
			//Print_Course(c2, course);
			Print_CourseList(&CList, course);
			printf("�Ƿ񷵻�������? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 6:
			system("cls");
			printf("\t\t*��ǰ����: [6] ��ȡ����ʾ�ɼ���Ϣ*\n");
			printf("\n");
			Output_Grade(g2, fp3, N*course);
			GList_Create(&GList, g2, N*course);
			printf("���гɼ���Ϣ: \n");
			printf("ѧ��\t�γ̺�\t�ɼ�\n");
			//Print_Grade(g2, N*course);
			Print_GradeList(&GList, N*course);
			printf("�Ƿ񷵻�������? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 7:
			system("cls");
			printf("\t*��ǰ����: [7] ��ѯ����ѧ�����пγ̵Ŀ��Գɼ�*\n");
			printf("\n");
			Connect_All(s2, c2, g2, A, N, course, N*course);
			Sort_All(A, N*course);
			Input_All(A, N*course, fp4);
			AList_Create(&AList, A, N*course);
			printf("�ֿƳɼ��ܱ�: \n");
			printf("\n");
			Print_AllList(&AList, N*course);
			//Print_All(A, N*course);
			printf("�Ƿ񷵻�������? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 8:
			system("cls");
			printf("\t*��ǰ����: [8] ��ѯָ���γ̺ŵ�����ѧ�����Գɼ�*\n");
			printf("\n");
			printf("���������ѯ�γ̺�: ");
			scanf("%d", &cno);
			k = Inquiry_Cno(A, ICno, N*course, cno, N, ICno1);
			Print_All(ICno, N);
			printf("���гɼ�����60�ֵ�ѧ��: \n");
			Print_All(ICno1, k);
			printf("�Ƿ񷵻�������? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 9:
			system("cls");
			printf("\t*��ǰ����: [9] ��ѯָ��ѧ��ѧ�������п��Գɼ�*\n");
			printf("\n");
			printf("���������ѯѧ��: ");
			scanf("%d", &sno);
			q = Inquiry_Sno(A, ISno, N*course, sno, course, ISno1);
			Print_All(ISno, course);
			printf("���гɼ�����60�ֵĿγ�: \n");
			Print_All(ISno1, q);
			printf("�Ƿ񷵻�������? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 10:
			system("cls");
			printf("\t\t*��ǰ����: [10] ʹ��ջ��ѧ����Ϣ����*\n");
			printf("\n");
			ptr = (StackPtr)malloc(sizeof(Stack));
			s = (StackPtr)malloc(sizeof(Stack));
			Stack_Init(&s);
			ptr = s;
			Stack_Push(&ptr, &SList, N);
			Stack_Pop(&ptr, rs, N);
			SList_Create(&RSList, rs, N);
			printf("����ѧ����Ϣ(����): \n");
			printf("ѧ��\t����\t�Ա�\tרҵ\n");
			Print_StudentList(&RSList, N);
			printf("�Ƿ񷵻�������? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 11:
			system("cls");
			printf("\t\t*��ǰ����: [11] ʹ����ʽ�������[7]*\n");
			printf("\n");
			Queue_Init(&queue);
			Queue_EnQueue(queue, A, N*course);
			Print_Queue(queue, N*course);
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