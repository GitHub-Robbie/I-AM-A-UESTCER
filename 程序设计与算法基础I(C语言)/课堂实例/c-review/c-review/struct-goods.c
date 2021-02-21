//这个宏定义禁止编译器包scanf的错误
//它必须定义在所有头文件包含之前
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct
{
    unsigned id;
    char name[20];
    float price;
    unsigned repository;
} GOODS, *GOODSPTR;

GOODS goods[10] = { {1, "TV set", 5000, 100 },
			{2, "Dish Washer", 6000, 30 },
            {3, "Washing Machine", 4000, 60 },
			{4, "Micro Oven", 2500, 50 },
			{5, "Frige", 9000, 30 }
};
int size = 5;

//查找，返回指针
GOODSPTR find(GOODS g[], int len, unsigned id)
{
    int i;
    for (i = 0; i < len; ++i)
        if (g[i].id == id) return g + i; //=> return &g[i]
    
    return NULL;
}

//冒泡排序法。以name成员作为排序关键字
//思路：用关键字进行比较，然后整体交换，不能只交换关键字
void sort_by_name(GOODS g[], int len)
{
    int i, j;
    GOODS t;

    for (i = len - 1; i > 1; --i)
        for (j = 0; j < i; ++j)
            if (strcmp(g[j].name, g[j+1].name) > 0) //字符串不能直接比较
            {
                t = g[j]; //结构变量可以整体赋值
                g[j] = g[j+1]; 
                g[j+1] = t; 
            }
}

int main()
{
    GOODSPTR p;
    int i;
    unsigned id;

    printf("please input an id:");
    scanf("%u", &id);
    p = find(goods, size, id);
    if (p)
        printf("%s\n", p->name);
    else
        printf("Cannot find goods whose id is %u\n", id);

    printf("Now list sorted:\n");
    sort_by_name(goods, size);
    for (p = goods, i = 0; i < size; ++i, ++p)
        printf("%u,%s,%g,%u\n", p->id, p->name, p->price, p->repository);

    return 0;
}
