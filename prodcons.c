#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>
#define BUFFERSIZE 20
#define MAXPRODUCTION 50000

int buffer[BUFFERSIZE],position;
sem_t empty,full,mutex,S;
int numproduced=0;
int numconsumed=0;

void *producer(void *param){
while(1){
 sem_wait(&empty);
 sem_wait(&mutex);
   buffer[posiiton]=rand()%50;
   position++;
   if(numproduced++ == MAXPRODUCTION) break;
   printf("&d\n", buffer[position]);
 sem_post(&mutex);
  sem_wait(&full);
  }                                                                                                                     
  printf("ok\n");
 pthread_exit(0);
}
void *consumer(void *param){
while(1){
if(numconsumed==MAXPRODUCED) break;
sem_wait(&full);
sem_wait(&mutex);
buffer[position]=-1;
position--;
numconsumed--;
  printf("%d\n",numconsumed);
  sem_post(&mutex);
sem_post(&empty);
}
 pthread_exit(0);
}

int main(){
  int N;
  pthread_t pt,ct;
  position=0;
  sem_init(&empty,0,BUFFERSIZE);
  sem_init(&full,0,0);
  sem_init(&mutex,0,1);
     N=40;                                                                                                                  
     pthread_create(&pt,NULL,producer,&N);
  N=60;
  pthread_create(&ct,NULL,consumer,&N);
  pthread_join(pt,NULL);
  pthread_join(ct,NULL);
    return(0);
}
