#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100

int Current = 0;

#define MAX_ID_LEN 30
#define MAX_NAME_LEN 30
#define MAX_PRICE_LEN 30
#define MAX_DISCOUNT_LEN 30

typedef struct {			//定义商品信息结构 
    char	id[MAX_ID_LEN];
    char	name[MAX_NAME_LEN];
    int  	price;
    char	discount[MAX_DISCOUNT_LEN];
    int		amount;
    int		remain;
} Info;

typedef struct node			//定义结点 
{
    Info data;
    struct node *next;
} List;

struct node *first = NULL;

bool check_nullfile(void)	//检查商品文件是否存在 
{
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


int main()
{
	check_nullfile(void);
	struct Goods *head;
	struct Goods *p1, *p2;
	
	int i;
	for(i = 1; i < 10 + 1; i++)
	{
		p1 = (struct Goods*)malloc(sizeof(struct Goods));
	
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
	printf("%s", p1->id);
     /**
     * 1.初始化一个链表
     * 2.循环显示商品管理系统的操作选择列表
     * 3.用户选择后调用相应的函数进行处理，处理完成后再度显示系统选择列表
     * 4.如果选择超出列表范围，则默认退出系统不存盘。
     */

    // TO DO YOUR WORK   
    return 0;
}