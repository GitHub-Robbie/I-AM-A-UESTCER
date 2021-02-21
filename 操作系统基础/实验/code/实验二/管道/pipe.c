#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{ 
    int pid1, pid2;
    int fd[2];                          //管道描述符
    char outpipe[100], inpipe[100];     //存储字符串
    pipe(fd);                           //创建管道

    while((pid1 = fork()) == -1) ;      //父进程中返回子进程id, 子进程中返回0
    if(pid1==0)                         //子进程
    {
        close(fd[0]);                   //关闭读端
        lockf(fd[1],1,0);               //lockf()函数允许将文件区域用作信号量,1互斥锁定区域,0锁定字节数
        sprintf(outpipe, "Child process 1 is sending a message!"); 
        // printf("p1\n");
        write(fd[1],outpipe,50);        //向管道写
        sleep(3);
        lockf(fd[1],0,0);               //0解锁互斥区域
        exit(0);
    }
    else    //父进程返回
    {
        while((pid2 = fork()) == -1) ;  //出错返回-1
        if(pid2==0)
        { 
            sleep(1);                   //先阻塞，使pid1优先执行
            close(fd[0]);
            lockf(fd[1],1,0);
            sprintf(outpipe,"Child process 2 is sending a message!");
            // printf("p2\n");
            write(fd[1],outpipe,50);
            sleep(3);
            lockf(fd[1],0,0);
            exit(0);
        }
        else
        {
            waitpid(0, NULL, 0);        //等待当前所有子进程结束
            close(fd[1]);               //关闭写端
            read(fd[0],inpipe,50);      //从管道读
            printf("%s\n",inpipe);

            waitpid(0, NULL, 0);
            read(fd[0],inpipe,50);
            printf("%s\n",inpipe);
            exit(0);
        }
    }
}
