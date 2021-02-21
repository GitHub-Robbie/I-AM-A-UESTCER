#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int get_data()
{
    int buf[10];
    int fd = open("data.txt",O_RDONLY);
    if(fd<0)
    {
        printf("打开文件失败!\n");
        exit(1);
    }
    else
    {
        int size = read(fd, buf, 2);
        if(size<0)
        {
            printf("文件读取失败!\n");
            exit(1);
        }
        else
            return buff[0];
    }
}

int main()
{
    int data = get_data();
    printf("数据：%d", data);
    return 0;
}