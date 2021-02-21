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
		printf("*             欢迎使用学生成绩查询系统!             *\n");
		printf("*****************************************************\n");
		printf("*\t      [1] 录入学生信息\t\t            *\n");
		printf("*\t      [2] 录入课程信息\t\t            *\n");
		printf("*\t      [3] 录入成绩信息\t\t            *\n");
		printf("*\t      [4] 读取并显示学生信息\t            *\n");
		printf("*\t      [5] 读取并显示课程信息\t            *\n");
		printf("*\t      [6] 读取并显示成绩信息\t            *\n");
		printf("*\t      [7] 查询所有学生所有课程的考试成绩    *\n");
		printf("*\t      [8] 查询指定课程号的所有学生考试成绩  *\n");
		printf("*\t      [9] 查询指定学号学生的所有考试成绩    *\n");
		printf("*\t      [10] 使用栈将学生信息逆序\t\t    *\n");
		printf("*\t      [11] 使用链式队列完成[7]\t\t    *\n");
		printf("*\t      [12] 退出程序\t\t\t    *\n");
		printf("*****************************************************\n");
		printf("\n");
		printf("说明: 学号以4位输入, 如1001; \n      课程号以6位输入, 如201801; \n      成绩保留整数输入.\n");
		printf("\n");
		printf("请输入您的选择: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			system("cls");
			printf("\t\t*当前所在: [1] 录入学生信息*\n");
			printf("\n");
			Input_Student(s1, N, fp1);
			printf("是否返回主界面? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;

		case 2:
			system("cls");
			printf("\t\t*当前所在: [2] 录入课程信息*\n");
			printf("\n");
			Input_Course(c1, course, fp2);
			printf("是否返回主界面? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 3:
			system("cls");
			printf("\t\t*当前所在: [3] 录入成绩信息*\n");
			printf("\n");
			Input_Grade(g1, N*course, fp3);
			printf("是否返回主界面? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 4:
			system("cls");
			printf("\t\t*当前所在: [4] 读取并显示学生信息*\n");
			printf("\n");
			Output_Student(s2, fp1, N);
			SList_Create(&SList, s2, N);
			printf("所有学生信息: \n");
			printf("学号\t姓名\t性别\t专业\n");
			//Print_Student(s2, N);
			Print_StudentList(&SList, N);
			printf("是否返回主界面? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 5:
			system("cls");
			printf("\t\t*当前所在: [5] 读取并显示课程信息*\n");
			printf("\n");
			Output_Course(c2, fp2, course);
			CList_Create(&CList, c2, course);
			printf("所有课程信息: \n");
			printf("课程号\t课程名称\t课时\n");
			//Print_Course(c2, course);
			Print_CourseList(&CList, course);
			printf("是否返回主界面? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 6:
			system("cls");
			printf("\t\t*当前所在: [6] 读取并显示成绩信息*\n");
			printf("\n");
			Output_Grade(g2, fp3, N*course);
			GList_Create(&GList, g2, N*course);
			printf("所有成绩信息: \n");
			printf("学号\t课程号\t成绩\n");
			//Print_Grade(g2, N*course);
			Print_GradeList(&GList, N*course);
			printf("是否返回主界面? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 7:
			system("cls");
			printf("\t*当前所在: [7] 查询所有学生所有课程的考试成绩*\n");
			printf("\n");
			Connect_All(s2, c2, g2, A, N, course, N*course);
			Sort_All(A, N*course);
			Input_All(A, N*course, fp4);
			AList_Create(&AList, A, N*course);
			printf("分科成绩总表: \n");
			printf("\n");
			Print_AllList(&AList, N*course);
			//Print_All(A, N*course);
			printf("是否返回主界面? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 8:
			system("cls");
			printf("\t*当前所在: [8] 查询指定课程号的所有学生考试成绩*\n");
			printf("\n");
			printf("请输入待查询课程号: ");
			scanf("%d", &cno);
			k = Inquiry_Cno(A, ICno, N*course, cno, N, ICno1);
			Print_All(ICno, N);
			printf("其中成绩低于60分的学生: \n");
			Print_All(ICno1, k);
			printf("是否返回主界面? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 9:
			system("cls");
			printf("\t*当前所在: [9] 查询指定学号学生的所有考试成绩*\n");
			printf("\n");
			printf("请输入待查询学号: ");
			scanf("%d", &sno);
			q = Inquiry_Sno(A, ISno, N*course, sno, course, ISno1);
			Print_All(ISno, course);
			printf("其中成绩低于60分的课程: \n");
			Print_All(ISno1, q);
			printf("是否返回主界面? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 10:
			system("cls");
			printf("\t\t*当前所在: [10] 使用栈将学生信息逆序*\n");
			printf("\n");
			ptr = (StackPtr)malloc(sizeof(Stack));
			s = (StackPtr)malloc(sizeof(Stack));
			Stack_Init(&s);
			ptr = s;
			Stack_Push(&ptr, &SList, N);
			Stack_Pop(&ptr, rs, N);
			SList_Create(&RSList, rs, N);
			printf("所有学生信息(逆序): \n");
			printf("学号\t姓名\t性别\t专业\n");
			Print_StudentList(&RSList, N);
			printf("是否返回主界面? (y/n)");
			scanf("%s", &yn);
			switch (yn)
			{
			case 'y': break;
			case 'n': exit(1);
			}
			break;
		case 11:
			system("cls");
			printf("\t\t*当前所在: [11] 使用链式队列完成[7]*\n");
			printf("\n");
			Queue_Init(&queue);
			Queue_EnQueue(queue, A, N*course);
			Print_Queue(queue, N*course);
			printf("是否返回主界面? (y/n)");
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