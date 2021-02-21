#pragma once
#define MAXSIZE 100
#define bool int

typedef struct student
{
	int sno;
	char sname[10];
	char sex[8];
	char major[20];
} Student;

typedef struct course
{
	int cno;
	char cname[MAXSIZE];
	int classHours;
} Course;

typedef struct grade
{
	int sno;
	int cno;
	int score;
} Grade;

typedef struct connect
{
	int sno;
	char sname[10];
	char sex[8];
	char major[20];
	int cno;
	char cname[MAXSIZE];
	int score;
} Connect;

typedef struct student_node
{
	int sno;
	char sname[10];
	char sex[5];
	char major[20];
	struct student_node *next;
}student_node, StudentList, *SPtr;
typedef SPtr *StudentListPtr;

typedef struct course_node
{
	int cno;
	char cname[MAXSIZE];
	int classHours;
	struct course_node *next;
}course_node, CourseList, *CPtr;
typedef CPtr *CourseListPtr;

typedef struct grade_node
{
	int cno;
	int sno;
	int score;
	struct grade_node *next;
}grade_node, GradeList, *GPtr;
typedef GPtr *GradeListPtr;

typedef struct connect_node
{
	int sno;
	char sname[10];
	char sex[8];
	char major[20];
	int cno;
	char cname[MAXSIZE];
	int score;
	struct connect_node *next;
}connect_node, ConnectList, *APtr;
typedef APtr *ConnectListPtr;

typedef struct stack
{
	int top;
	Student sreverse[MAXSIZE];
}Stack, *StackPtr;

typedef struct queue_node
{
	Connect Queue[MAXSIZE];
	struct queue_node *next;
}queue_node, *QueueNodePtr;

typedef struct queue
{
	queue_node *front;
	queue_node *rear;
}queue, *QueuePtr;

void Create_File();
void Input_Student(Student s[], int n, FILE *fp);
void Input_Course(Course c[], int n, FILE *fp);
void Input_Grade(Grade g[], int n, FILE *fp);
void Input_All(Connect A[], int n, FILE *fp);
void Output_Student(Student s[], FILE *fp, int n);
void Output_Course(Course c[], FILE *fp, int n);
void Output_Grade(Grade g[], FILE *fp, int n);
void Print_Student(Student s[], int n);
void Print_Course(Course c[], int n);
void Print_Grade(Grade g[], int n);
void Print_All(Connect A[], int n);
void Print_StudentList(StudentListPtr L, int n);
void Print_CourseList(CourseListPtr L, int n);
void Print_GradeList(GradeListPtr L, int n);
void Print_AllList(ConnectListPtr L, int n);
void SortS(Student s[], int n);
void SortC(Course c[], int n);
void SortG(Grade g[], int n);
void Sort_All(Connect A[], int n);
void SList_Create(StudentListPtr L, Student s[], int n);
void CList_Create(CourseListPtr L, Course c[], int n);
void GList_Create(GradeListPtr L, Grade g[], int n);
void AList_Create(ConnectListPtr L, Connect A[], int n);
void Connect_All(Student s[], Course c[], Grade g[], Connect A[], int n1, int n2, int n3);
int Inquiry_Cno(Connect A[], Connect ICno[], int n1, int cno, int n2, Connect ICno1[]);
int Inquiry_Sno(Connect A[], Connect ISno[], int n1, int sno, int n2, Connect ISno1[]);

void Stack_Init(Stack *s);
void Stack_Push(StackPtr s, StudentListPtr L, int n);
void Stack_Pop(StackPtr s, Student rs[], int n);

void Queue_Init(QueuePtr q);
void Queue_EnQueue(QueuePtr q, Connect A[], int n);
bool Queue_Empty(QueuePtr q);
void Print_Queue(QueuePtr q, int n);

