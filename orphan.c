#include <minix3/mthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define BUF_SIZE 200
void main(void){
pid_t pid ;
pid = fork();
if(pid==0){
   printf("i am a child process pid=%d ppid=%d\n", getpid(), getppid());
   sleep(30);
   printf("i am a child process after pid=%d ppid=%d\n", getpid(), getppid());
}
else{
printf("i am a parent process pid=%d ppid=%d\n", getpid(), getppid());
}
}
