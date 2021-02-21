#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define PHI 5       //哲学家人数

int count = 1;

/*全局变量*/
int chopsticks[PHI];
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;         //初始化条件变量
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;      //初始化互斥锁

void eat(long p_num)
{
    int s_time = rand() % 5 + 1;
    pthread_mutex_lock(&mutex);         //加锁

    if(p_num == 4)
        while(chopsticks[p_num] == 1 || chopsticks[0] == 1)
            pthread_cond_wait(&cond, &mutex);   //等待
    else
        while(chopsticks[p_num] == 1 || chopsticks[p_num+1] == 1)
            pthread_cond_wait(&cond, &mutex);   //等待
    
    /*拿到筷子后,将互斥量设置为占用*/
    chopsticks[p_num] = 1;
    if(p_num == 4)
        chopsticks[0] = 1;
    else
        chopsticks[p_num+1] = 1;
    
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);

    printf("[第%2d轮] %ld号哲学家：吃饭%d秒。\n", count++, p_num, s_time);
    sleep(s_time);      //吃饭时间
}

void think(long p_num)
{
    int s_time = rand() % 5 + 1;
    pthread_mutex_lock(&mutex);         //加锁
    
    /*开始思考后，将互斥量释放*/
    chopsticks[p_num] = 0;
    if(p_num == 4)
        chopsticks[0] = 0;
    else
        chopsticks[p_num+1] = 0;
    
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);

    printf("[第%2d轮] %ld号哲学家：思考%d秒。\n", count++, p_num, s_time);
    sleep(s_time);      //思考时间
}

void* thread_exec(void* i)
{
    long p_num = (long)i;
    while(1)
    {
        eat(p_num);
        think(p_num);
    }
}

int main()
{
    pthread_t philosophers[PHI];  //  线程ID
	long i;     //哲学家序号    

    for(i=0; i<PHI; i++)    //筷子状态初始化
        chopsticks[i] = 0;
    
    for(i=0; i<PHI; i++)    //创建线程
        pthread_create(&philosophers[i], NULL, &thread_exec, (void *)i);

    for(i=0; i<PHI; i++)    //等待线程结束
		pthread_join(philosophers[i], NULL);
    
    return 0;
}