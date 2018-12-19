#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <semaphore.h>
sem_t s1,s2;

void func(void *p)
{
while(1){
  sem_wait(&s2);

  puts("kamalesh\n");
  
  sem_post(&s1);
  sleep(1);
}
}
void func1(void *p)
{
while(1){
sem_wait(&s1);
  puts("patil\n");
  sem_post(&s2);
}
}

int main()
{
  pthread_t t1,t2;
sem_init(&s1,0,0);
sem_init(&s2,0,1);

  pthread_create(&t1,NULL,(void*)func,NULL);
  pthread_create(&t2,NULL,(void*)func1,NULL);

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
}
