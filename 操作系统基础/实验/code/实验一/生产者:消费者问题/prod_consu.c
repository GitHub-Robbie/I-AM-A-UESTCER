#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PROD 3      //生产者数目
#define CONSU 4     //消费者数目
#define BUFF 10     //缓冲区数目

/*全局变量*/
int in = 0;         //放产品位置
int out = 0;        //取产品位置
int buff[BUFF] = {0};   //缓冲区初始化为0(无产品)
int producer_id = 0;    //生产者id
int consumer_id = 0;    //消费者id
int count = 1;
sem_t empty_sem;        //同步信号量, 满时阻止生产者放产品
sem_t full_sem;         //同步信号量, 空时阻止消费者取产品
pthread_mutex_t mutex;  //互斥信号量

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
        int size = read(fd, buf, 1);
        if(size<0)
        {
            printf("文件读取失败!\n");
            exit(1);
        }
        else
            return (buf[0]+rand()) % 10;
    }
}

void print_buff()
{
    int i;
    for(i = 0; i < BUFF; i++)
        printf("%d ", buff[i]);
    printf("\n");
}

void* producer(void* id)
{
    long p_id = (long)id;
    while(1)
    {
        sleep(1);
        int data = get_data();
        sem_wait(&empty_sem);           //信号量-1, 成功执行则说明可以放产品
        pthread_mutex_lock(&mutex);     //互斥锁

        in = in % BUFF;
        buff[in++] = data;
        printf("[第%2d轮] %ld号生产者向缓冲区放产品[%d]     缓冲区: ", count++, p_id, data);
        print_buff();

        pthread_mutex_unlock(&mutex);
        sem_post(&full_sem);            //信号量+1
    }
}

void* consumer(void* id)
{
    long c_id = (long)id;
    while(1)
    {
        sleep(3);
        sem_wait(&full_sem);            //信号量-1, 成功执行则说明可以取产品
        pthread_mutex_lock(&mutex);     //互斥锁

        out = out % BUFF;
        int data = buff[out];
        buff[out++] = 0;
        printf("[第%2d轮] %ld号消费者从缓冲区取产品[%d]     缓冲区: ", count++, c_id, data);
        print_buff();
        
        pthread_mutex_unlock(&mutex);
        sem_post(&empty_sem);            //信号量+1
    }
}

int main()
{
    pthread_t prod_id[PROD];        //生产者线程ID
    pthread_t consu_id[CONSU];      //消费者线程ID
    long i;
    int prod_ret[PROD];             //生产者线程创建结果
    int consu_ret[CONSU];           //消费者线程创建结果

    int empty_init = sem_init(&empty_sem, 0, BUFF); //初始值为BUFF
    int full_init = sem_init(&full_sem, 0, 0);      //初始值为0
    if(empty_init && full_init != 0)                //初始化失败
    {
        printf("初始化失败!\n");
        exit(1);
    }

    for(i=0; i<PROD; i++)           //创建生产者线程
    {
        prod_ret[i] = pthread_create(&prod_id[i], NULL, &producer, (void*)i);
        if(prod_ret[i] != 0)
        {
            printf("%ld号生产者进程创建失败。\n", i);
            exit(1);
        }
    }

    for(i=0; i<CONSU; i++)           //创建消费者线程
    {
        consu_ret[i] = pthread_create(&consu_id[i], NULL, &consumer, (void*)i);
        if(consu_ret[i] != 0)
        {
            printf("%ld号消费者进程创建失败。\n", i);
            exit(1);
        }
    }

    for(i=0; i<PROD; i++)
        pthread_join(prod_id[i], NULL);
    
    for(i=0; i<CONSU; i++)
        pthread_join(consu_id[i], NULL);
    
    exit(0);
}