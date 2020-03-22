#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main() {

pid_t pid = fork();
    if(pid > 0)
     sleep(50);
    else
     printf("Child working..\n");
     exit(0);
    return 0;
}
