#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grade_inquiry.h"

void Input_Student(Student s[], int n, FILE *fp)
{
	int i;
	printf("请按提示依次录入学生信息: \n");
	for (i = 0; i < n; i++)
	{
		printf("【%d】学号: ", i + 1);
		scanf("%d", &s[i].sno);
		printf("     姓名: ");
		scanf("%s", &s[i].sname);
		printf("     性别(M/F): ");
		scanf("%s", &s[i].sex);
		printf("     专业: ");
		scanf("%s", &s[i].major);

		fflush(stdin);
	}
	printf("\n");
	printf("**录入完成!**\n");

	fp = fopen("student.dat", "w");
	
	if (fp == NULL)
	{
		printf("Fail to open file!");
		exit(0);
	}

	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%d\t", s[i].sno);
		fprintf(fp, "%s\t", s[i].sname);
		fprintf(fp, "%s\t", s[i].sex);
		fprintf(fp, "%s\t", s[i].major);
		if(i!=n-1)
			fprintf(fp, "\n");
	}
	fclose(fp);
}

void Input_Course(Course c[], int n, FILE *fp)
{
	int i;
	
	printf("请按提示依次录入课程信息: \n");
	for (i = 0; i < n; i++)
	{

		printf("【%d】课程号: ", i + 1);
		scanf("%d", &c[i].cno);
		printf("     课程名称: ");
		scanf("%s", &c[i].cname);
		printf("     课时: ");
		scanf("%d", &c[i].classHours);

		fflush(stdin);
	}
	printf("\n");
	printf("**录入完成!**\n");

	fp = fopen("course.dat", "w");

	if (fp == NULL)
	{
		printf("Fail to open file!");
		exit(0);
	}

	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%d\t", c[i].cno);
		fprintf(fp, "%s\t", c[i].cname);
		fprintf(fp, "%d\t", c[i].classHours);
		if (i != n-1)
			fprintf(fp, "\n");
	}
	fclose(fp);
}

void Input_Grade(Grade g[], int n, FILE *fp)
{
	int i;
	printf("请按提示依次录入学生成绩: \n");
	for (i = 0; i < n; i++)
	{
	
		printf("【%d】学号: ", i + 1);
		scanf("%d", &g[i].sno);
		printf("     课程号: ");
		scanf("%d", &g[i].cno);
		printf("     成绩: ");
		scanf("%d", &g[i].score);

		fflush(stdin);
	}
	printf("\n");
	printf("**录入完成!**\n");

	fp = fopen("courseGrade.dat", "w");

	if (fp == NULL)
	{
		printf("Fail to open file!");
		exit(0);
	}

	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%d\t", g[i].sno);
		fprintf(fp, "%d\t", g[i].cno);
		fprintf(fp, "%d\t", g[i].score);
		if (i != n-1)
			fprintf(fp, "\n");
	}
	fclose(fp);
}

void Create_File()
{
	FILE *fp1;
	fp1 = fopen("student.dat", "w");
	if (!fp1)
	{
		printf("Fail to create file!");
		exit(0);
	}
	fclose(fp1);

	FILE *fp2;
	fp2 = fopen("student.dat", "w");
	if (!fp2)
	{
		printf("Fail to create file!");
		exit(0);
	}
	fclose(fp2);

	FILE *fp3;
	fp3 = fopen("student.dat", "w");
	if (!fp3)
	{
		printf("Fail to create file!");
		exit(0);
	}
	fclose(fp3);

	FILE *fp4;
	fp4 = fopen("studentGrade.dat", "w");
	if (!fp4)
	{
		printf("Fail to create file!");
		exit(0);
	}
	fclose(fp4);
}

void SortS(Student s[], int n)
{
	Student t[10];
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
		{
			if (s[j].sno > s[j + 1].sno)
			{
				memcpy(&t[0], &s[j], sizeof(Student));
				memcpy(&s[j], &s[j + 1], sizeof(Student));
				memcpy(&s[j + 1], &t[0], sizeof(Student));
			}
		}
}

void SortC(Course c[], int n)
{
	Course t[10];
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
		{
			if (c[j].cno > c[j + 1].cno)
			{
				memcpy(&t[0], &c[j], sizeof(Course));
				memcpy(&c[j], &c[j + 1], sizeof(Course));
				memcpy(&c[j + 1], &t[0], sizeof(Course));
			}
		}
}

void SortG(Grade g[], int n)
{
	Grade t[30];
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
		{
			if (g[j].cno > g[j + 1].cno)
			{
				memcpy(&t[0], &g[j], sizeof(Grade));
				memcpy(&g[j], &g[j + 1], sizeof(Grade));
				memcpy(&g[j + 1], &t[0], sizeof(Grade));
			}
		}
	Grade k[30];
	for (i = 0; i < n - i; i++)
		for (j = 0; j < n - 1 - i; j++)
		{
			if (g[j].sno > g[j + 1].sno)
			{
				memcpy(&k[0], &g[j], sizeof(Grade));
				memcpy(&g[j], &g[j + 1], sizeof(Grade));
				memcpy(&g[j + 1], &k[0], sizeof(Grade));
			}
		}
}

void Output_Student(Student s[], FILE *fp, int n)
{
	int i;
	if ((fp = fopen("student.dat", "r")) == NULL)
	{
		printf("Fail to open file!");
		exit(0);
	}
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%d", &s[i].sno);
		fscanf(fp, "%s", s[i].sname);
		fscanf(fp, "%s", s[i].sex);
		fscanf(fp, "%s", &s[i].major);
	}
	SortS(s, n);
}

void Output_Course(Course c[], FILE *fp, int n)
{
	int i;
	if ((fp = fopen("course.dat", "r")) == NULL)
	{
		printf("Fail to open file!");
		exit(0);
	}
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%d", &c[i].cno);
		fscanf(fp, "%s", c[i].cname);
		fscanf(fp, "%d", &c[i].classHours);
	}
	SortC(c, n);
}

void Output_Grade(Grade g[], FILE *fp, int n)
{
	int i;
	if ((fp = fopen("courseGrade.dat", "r")) == NULL)
	{
		printf("Fail to open file!");
		exit(0);
	}
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%d", &g[i].sno);
		fscanf(fp, "%d", &g[i].cno);
		fscanf(fp, "%d", &g[i].score);
	}
	SortG(g, n);
}

void Print_Student(Student s[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\t", s[i].sno);
		printf("%s\t", s[i].sname);
		printf("%s\t", s[i].sex);
		printf("%s\n", s[i].major);
	}
	printf("\n");
}

void Print_Course(Course c[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\t", c[i].cno);
		printf("%s\t\t", c[i].cname);
		printf("%d\n", c[i].classHours);
	}
	printf("\n");
}

void Print_Grade(Grade g[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\t", g[i].sno);
		printf("%d\t", g[i].cno);
		printf("%d\n", g[i].score);
	}
	printf("\n");
}

void SList_Create(StudentListPtr L, Student s[], int n)
{
	SPtr p;
	if (*L == NULL)
	{
		p = (SPtr)malloc(sizeof(student_node));
		if (p == NULL)
			return;
		*L = p;
		(*L)->next = NULL;
	}

	int i;
	for (i = n - 1; i >= 0; i--)
	{
		SPtr q;
		q = (SPtr)malloc(sizeof(student_node));
		q->next = NULL;
		q->sno = s[i].sno;
		strcpy(q->sname, s[i].sname);
		strcpy(q->sex, s[i].sex);
		strcpy(q->major, s[i].major);
		if ((*L)->next == NULL)
			(*L)->next = q;
		else
		{
			SPtr t;
			t = (SPtr)malloc(sizeof(student_node));
			t = (*L)->next;
			(*L)->next = q;
			q->next = t;
		}
	}
}

void CList_Create(CourseListPtr L, Course c[], int n)
{
	CPtr p;
	if (*L == NULL)
	{
		p = (CPtr)malloc(sizeof(course_node));
		if (p == NULL)
			return;
		*L = p;
		(*L)->next = NULL;
	}

	int i;
	for (i = n - 1; i >= 0; i--)
	{
		CPtr q;
		q = (CPtr)malloc(sizeof(course_node));
		q->next = NULL;
		q->cno = c[i].cno;
		strcpy(q->cname, c[i].cname);
		q->classHours = c[i].classHours;
		if ((*L)->next == NULL)
			(*L)->next = q;
		else
		{
			CPtr t;
			t = (CPtr)malloc(sizeof(course_node));
			t = (*L)->next;
			(*L)->next = q;
			q->next = t;
		}
	}
}

void GList_Create(GradeListPtr L, Grade g[], int n)
{
	GPtr p;
	if (*L == NULL)
	{
		p = (GPtr)malloc(sizeof(grade_node));
		if (p == NULL)
			return;
		*L = p;
		(*L)->next = NULL;
	}

	int i;
	for (i = n - 1; i >= 0; i--)
	{
		GPtr q;
		q = (GPtr)malloc(sizeof(grade_node));
		q->next = NULL;
		q->sno = g[i].sno;
		q->cno = g[i].cno;
		q->score = g[i].score;
		if ((*L)->next == NULL)
			(*L)->next = q;
		else
		{
			GPtr t;
			t = (GPtr)malloc(sizeof(grade_node));
			t = (*L)->next;
			(*L)->next = q;
			q->next = t;
		}
	}
}

void Print_StudentList(StudentListPtr L, int n)
{
	SPtr p = (*L)->next;
	while (p->next != NULL)
	{
		printf("%d\t", p->sno);
		printf("%s\t", p->sname);
		printf("%s\t", p->sex);
		printf("%s\n", p->major);
		p = p->next;
	}
	printf("%d\t", p->sno);
	printf("%s\t", p->sname);
	printf("%s\t", p->sex);
	printf("%s\n", p->major);
	printf("\n");
}

void Print_CourseList(CourseListPtr L, int n)
{
	CPtr p = (*L)->next;
	while (p->next != NULL)
	{
		printf("%d\t", p->cno);
		printf("%s\t\t", p->cname);
		printf("%d\n", p->classHours);
		p = p->next;
	}
	printf("%d\t", p->cno);
	printf("%s\t\t", p->cname);
	printf("%d\n", p->classHours);
	printf("\n");
}

void Print_GradeList(GradeListPtr L, int n)
{
	GPtr p = (*L)->next;
	while (p->next != NULL)
	{
		printf("%d\t", p->sno);
		printf("%d\t", p->cno);
		printf("%d\n", p->score);
		p = p->next;
	}
	printf("%d\t", p->sno);
	printf("%d\t", p->cno);
	printf("%d\n", p->score);
	printf("\n");
}

void Connect_All(Student s[], Course c[], Grade g[], Connect A[], int n1, int n2, int n3)
{
	int i = 0, j = 0, k = 0;
	for (i = 0; i < n3; i = i + n2)
	{
		for (j = 0; j < n2; j++)
		{
			A[i + j].sno = s[k].sno;
			strcpy(A[i + j].sname, s[k].sname);
			strcpy(A[i + j].sex, s[k].sex);
			strcpy(A[i + j].major, s[k].major);
		}
		k++;
	}
	
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < n3; j++)
		{
			if (s[i].sno == g[j].sno)
			{
				k = 0;
				A[j].cno = g[j].cno;
				A[j].score = g[j].score;
				++k;
				if (k == n2)
					break;
			}
		}
	}

	for (i = 0; i < n3; i++)
	{
		for (j = 0; j < n2; j++)
		{
			if (A[i].cno == c[j].cno)
				strcpy(A[i].cname, c[j].cname);
		}
	}
}

void Print_All(Connect A[], int n)
{
	int i;
	printf("\n");
	printf("学号\t姓名\t性别\t专业\t课程号\t课程名称\t成绩\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", A[i].sno);
		printf("%s\t", A[i].sname);
		printf("%s\t", A[i].sex);
		printf("%s\t", A[i].major);
		printf("%d\t", A[i].cno);
		printf("%s\t\t", A[i].cname);
		printf("%d\n", A[i].score);
	}
	printf("\n");
}

void Sort_All(Connect A[], int n)
{
	Connect t[30];
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
		{
			if (A[j].score < A[j + 1].score)
			{
				memcpy(&t[0], &A[j], sizeof(Connect));
				memcpy(&A[j], &A[j + 1], sizeof(Connect));
				memcpy(&A[j + 1], &t[0], sizeof(Connect));
			}
		}
	Connect k[30];
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
		{
			if (A[j].cno > A[j + 1].cno)
			{
				memcpy(&k[0], &A[j], sizeof(Connect));
				memcpy(&A[j], &A[j + 1], sizeof(Connect));
				memcpy(&A[j + 1], &k[0], sizeof(Connect));
			}
		}
}

void AList_Create(ConnectListPtr L, Connect A[], int n)
{
	APtr p;
	if (*L == NULL)
	{
		p = (APtr)malloc(sizeof(connect_node));
		if (p == NULL)
			return;
		*L = p;
		(*L)->next = NULL;
	}

	int i;
	for (i = n - 1; i >= 0; i--)
	{
		APtr q;
		q = (APtr)malloc(sizeof(connect_node));
		q->next = NULL;
		q->sno = A[i].sno;
		strcpy(q->sname, A[i].sname);
		strcpy(q->sex, A[i].sex);
		strcpy(q->major, A[i].major);
		q->cno = A[i].cno;
		strcpy(q->cname, A[i].cname);
		q->score = A[i].score;
		if ((*L)->next == NULL)
			(*L)->next = q;
		else
		{
			APtr t;
			t = (APtr)malloc(sizeof(connect_node));
			t = (*L)->next;
			(*L)->next = q;
			q->next = t;
		}
	}
}

void Print_AllList(ConnectListPtr L, int n)
{
	printf("学号\t姓名\t性别\t专业\t课程号\t课程名称\t成绩\n");
	APtr p = (*L)->next;
	while (p->next != NULL)
	{
		printf("%d\t", p->sno);
		printf("%s\t", p->sname);
		printf("%s\t", p->sex);
		printf("%s\t", p->major);
		printf("%d\t", p->cno);
		printf("%s\t\t", p->cname);
		printf("%d\n", p->score);
		p = p->next;
	}
	printf("%d\t", p->sno);
	printf("%s\t", p->sname);
	printf("%s\t", p->sex);
	printf("%s\t", p->major);
	printf("%d\t", p->cno);
	printf("%s\t\t", p->cname);
	printf("%d\n", p->score);
	printf("\n");
}

void Input_All(Connect A[], int n, FILE *fp)
{
	int i;
	fp = fopen("studentGrade.dat", "w");

	if (fp == NULL)
	{
		printf("Fail to open file!");
		exit(0);
	}

	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%d\t", A[i].sno);
		fprintf(fp, "%s\t", A[i].sname);
		fprintf(fp, "%s\t", A[i].sex);
		fprintf(fp, "%s\t", A[i].major);
		fprintf(fp, "%d\t", A[i].cno);
		fprintf(fp, "%s\t", A[i].cname);
		fprintf(fp, "%d\t", A[i].score);
		if (i != n - 1)
			fprintf(fp, "\n");
	}
	fclose(fp);
}

int Inquiry_Cno(Connect A[], Connect ICno[], int n1, int cno, int n2, Connect ICno1[])
{
	int i, j = 0, k = 0;
	for (i = 0; i < n1; i++)
	{
		if (A[i].cno == cno)
		{
			memcpy(&ICno[j], &A[i], sizeof(Connect));
			j++;
		}
	}
	for (i = 0; i < n2; i++)
	{
		if (ICno[i].score < 60)
		{
			memcpy(&ICno1[k], &ICno[i], sizeof(Connect));
			k++;
		}
	}
	return k;
}

int Inquiry_Sno(Connect A[], Connect ISno[], int n1, int sno, int n2, Connect ISno1[])
{
	int i, j = 0, k = 0;
	for (i = 0; i < n1; i++)
	{
		if (A[i].sno == sno)
		{
			memcpy(&ISno[j], &A[i], sizeof(Connect));
			j++;
		}
	}
	for (i = 0; i < n2; i++)
	{
		if (ISno[i].score < 60)
		{
			memcpy(&ISno1[k], &ISno[i], sizeof(Connect));
			k++;
		}
	}
	return k;
}

void Stack_Init(Stack *s)
{
	s->top = -1;
}

void Stack_Push(StackPtr s, StudentListPtr L, int n)
{
	SPtr p = NULL;
	p = p = (SPtr)malloc(sizeof(student_node));
	p = (*L)->next;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		s->top++;
		s->sreverse[s->top].sno = p->sno;
		strcpy(s->sreverse[s->top].sname, p->sname);
		strcpy(s->sreverse[s->top].sex, p->sex);
		strcpy(s->sreverse[s->top].major, p->major);
		p = p->next;
	}
	++s->top;
}

void Stack_Pop(StackPtr s, Student rs[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		--s->top;
		rs[i].sno = s->sreverse[s->top].sno;
		strcpy(rs[i].sname, s->sreverse[s->top].sname);
		strcpy(rs[i].sex, s->sreverse[s->top].sex);
		strcpy(rs[i].major, s->sreverse[s->top].major);
	}
}

void Queue_Init(QueuePtr *q)
{
	*q = (QueuePtr)malloc(sizeof(queue));
	QueueNodePtr ptr = (QueueNodePtr)malloc(sizeof(queue_node));
	if (ptr)
	{
		(*q)->front = (*q)->rear = ptr;
		ptr->next = NULL;
	}
}

bool Queue_Empty(QueuePtr q)
{
	return(q->front->next == NULL && q->rear->next == NULL);
}

void Queue_EnQueue(QueuePtr q, Connect A[], int n)
{
	int i;
	for (i = n - 1; i >= 0; i--)
	{
		queue_node *p = (queue_node*)malloc(sizeof(queue_node));
		memcpy(p->Queue, &A[i], sizeof(Connect));
		p->next = NULL;
		if (Queue_Empty(q))
		{
			q->front->next = p;
			q->rear = p;
		}
		else
		{
			q->front->next = p;
			p->next = q->rear;
			q->rear = p;
		}
	}
}

void Print_Queue(QueuePtr q, int n)
{
	int i;
	queue_node *p = (queue_node*)malloc(sizeof(queue_node));
	p = q->front->next;
	printf("学号\t姓名\t性别\t专业\t课程号\t课程名称\t成绩\n");
	while (p->next != NULL)
	{
		printf("%d\t", p->Queue->sno);
		printf("%s\t", p->Queue->sname);
		printf("%s\t", p->Queue->sex);
		printf("%s\t", p->Queue->major);
		printf("%d\t", p->Queue->cno);
		printf("%s\t\t", p->Queue->cname);
		printf("%d\n", p->Queue->score);
		p = p->next;
	}
	printf("%d\t", p->Queue->sno);
	printf("%s\t", p->Queue->sname);
	printf("%s\t", p->Queue->sex);
	printf("%s\t", p->Queue->major);
	printf("%d\t", p->Queue->cno);
	printf("%s\t\t", p->Queue->cname);
	printf("%d\n", p->Queue->score);
	printf("\n");
}