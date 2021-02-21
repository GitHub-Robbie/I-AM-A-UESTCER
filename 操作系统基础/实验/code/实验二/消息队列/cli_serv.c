#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

struct msgform
{
    long mtype;
    char mtext[250];
}msg;

long REQ = 1;
int msgqid, pid, *pint;

void server()
{
    msgqid = msgget(1234,0666|IPC_CREAT);   //创建消息队列, 0666表示对内存有读／写／执行的权限, 返回队列ID
    msgrcv(msgqid,&msg,250,REQ,0);          //接收client的消息
    pint = (int *)msg.mtext;  
    pid = *pint;                            //获取client的pid
    printf("server端收到进程ID = %d.\n",pid);
    msg.mtype = pid;                        //消息类型为client的pid
    *pint = getpid();                       //将消息内容设置为server的id
    msgsnd(msgqid,&msg,250,0);
    exit(0);
}

void client()
{
    msgqid = msgget(1234,0666);             //打开消息队列, 0666表示对内存有读／写／执行的权限
    pid = getpid();                         //得到自己的pid
    pint = (int*)msg.mtext;                 //指向消息正文
    *pint = pid;                            //将正文改为自己的pid值
    msg.mtype = REQ;                        //设置消息类型
    msgsnd(msgqid,&msg,250,0);              //发送消息, 成功0, 错误-1
    msgrcv(msgqid,&msg,250,pid,0);          //接受server发的消息
    printf("client端收到进程ID = %d.\n", *pint);
    exit(0);
}

int main()
{
    int pid1 = fork();  //创建进程
    if(!pid1) server();

    int pid2 = fork();
    if(!pid2) client();
    
    wait(0);
    wait(0);
}
