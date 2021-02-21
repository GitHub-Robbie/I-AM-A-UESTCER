#include <stdio.h>

#define CAPACITY 20

void print(int x[], int len)
{
    int i;
    for (i = 0; i < len; ++i) printf("%4d", x[i]);
    putchar('\n');
}

int insert(int x[], int len, int v)
{
    int pos, i;
    //找到插入位置
    for (pos = 0; v > x[pos] && pos < len; ++pos);
    
    //腾位置
    for (i = len; i > pos; --i)
        x[i] = x[i - 1];

    //插入数据
    x[pos] = v;
    return ++len;
}

int main()
{
    int a[CAPACITY] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = 8; //数组目前的元素数量
    int n;

    print(a, size);
    
    scanf("%d", &n);
    size = insert(a, size, n);

    print(a, size);

    return 0;
}
