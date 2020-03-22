#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#define BUFSIZE 100
int main(void){
int fd;
char *myfifo="/tmp/myfifo";
char buffer[BUFSIZE];
fd=open(myfifo,O_RDONLY);
read(fd,buffer,BUFSIZE);
printf("Received: %s\n",buffer);
close(fd);
return(0);
}
