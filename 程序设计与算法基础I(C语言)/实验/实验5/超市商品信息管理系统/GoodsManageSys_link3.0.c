#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define LEN sizeof(struct Goods)
#define MAX_ID_LEN 30
#define MAX_NAME_LEN 30
#define MAX_PRICE_LEN 30
#define MAX_DISCOUNT_LEN 30

struct Goods {
	char	id[MAX_ID_LEN];
    char	name[MAX_NAME_LEN];
    int  	price;
    char	discount[MAX_DISCOUNT_LEN];
    int		amount;
    int		remain;
    struct Goods *next;
};

void menu();
void start();
void welcome();
bool check();
char filename[30];

struct Goods *Create(int n);		//生成链表
struct Goods *Create(int n) 
{
	void menu_print_in(void);
	struct Goods *head;
	struct Goods *p1, *p2;
	
	system("cls");					//清屏
	
	int i;
	for(i = 1; i < n + 1; i++)
	{
		p1 = (struct Goods*)malloc(LEN);
		menu_print_in();
	bool check();
	
	FILE *fp;
	fp = fopen("goodsinfo.txt", "r");
	fscanf(fp, "%s\t%s\t%d\t%s\t%d\t%d\n", p1->id, p1->name, &p1->price, 
											p1->discount, &p1->amount, &p1->remain);
	p1->next = NULL;
	if(i == 1) 
	{
		head = p2 = p1;
	}
	else
	{
		p2->next = p1;
		p2 = p1;
	}
	
	} 
	printf("%s", Goods->id);
	return(head);
}

bool check(){
	FILE *fp = fopen("goodsinfo.txt", "r");
    //file not exist
    if (!fp) {
        printf("商品信息初始化文件不存在！我们将为您新建一个^_^！\n");
        FILE *fp = fopen("goodsinfo.txt", "w");
        fclose(fp);

        return false;
    }
        //file already exist
    else {
        int temp;
        //res for try to read file if file null feof() can't determine whether file is null or not
        int res = fscanf(fp, "%d", &temp);
        fclose(fp);
        if (res <= 0)
            return false;
        else
            return true;
    }
}

void menu_print_in()
{
	printf("----------------------------------------------");
	printf("id	name	price	discount	amount	remain");
	printf("----------------------------------------------");
}
int main()
{
}
