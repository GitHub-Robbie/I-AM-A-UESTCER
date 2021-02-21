#include <stdio.h>

#define CAPACITY 20

int main()
{
    int a[CAPACITY] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = 8; //数组目前的元素数量
    int pos;
    int i, n;

    for (i = 0; i < size; ++i) printf("%4d", a[i]);
    putchar('\n');
    
    scanf("%d", &n);

    //找到插入位置
    for (pos = 0; n > a[pos] && pos < size; ++pos);
    
    //腾位置
    for (i = size; i > pos; --i)
        a[i] = a[i - 1];

    //插入数据
    a[pos] = n;
    ++size;

    for (i = 0; i < size; ++i) printf("%4d", a[i]);
    putchar('\n');

    return 0;
}
