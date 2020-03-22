#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
int main(void){
int fd;
char msg[]="Hello msg";
char * myfifo="/tmp/myfifo";
mkfifo(myfifo,666);
fd=open(myfifo, O_WRONLY);
write(fd,msg,strlen(msg));
close(fd);
unlink(myfifo);
return(0);
}
