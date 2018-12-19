/*#include <signal.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 


pthread_mutex m1;
int counter=0;
void *f1(void *n)
{
printf("****a=%d\n",(int)n);

}

void *f2(void *n)
{
printf("****b=%d\n",(int)n);

}
int main()
{

  int a=50,b=100;
pthread_t t1,t2;

pthread_create(&t1,NULL,f1,(void*)a);
sleep(1);
pthread_create(&t2,NULL,f2,(void *)b);

pthread_join(t1,NULL);
pthread_join(t2,NULL);


}

*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *functionC();
pthread_mutex_t m1;//= PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2;//= PTHREAD_MUTEX_INITIALIZER;
int  counter = 0;

void *functionC1()
{
  int i=0;
while(i++<5){
  pthread_mutex_lock( &m2 );

  printf("************\n");
  pthread_mutex_unlock( &m1 );
}
}
main()
{
  int rc1, rc2;
  pthread_t thread1, thread2;

  /* Create independent threads each of which will execute functionC */

pthread_create( &thread1, NULL, &functionC, NULL);//
 // {
  //  printf("Thread creation failed: %d\n", rc1);
//  }
sleep(1);
  pthread_create( &thread2, NULL, &functionC1, NULL);
 // {
  //  printf("Thread creation failed: %d\n", rc2);
 // }
// / /* Wait till threads are complete before main continues. Unless we  */
  /* wait we run the risk of executing an exit which will terminate   */
  /* the process and all threads before the threads have completed.   */
  pthread_join( thread1, NULL);
  pthread_join( thread2, NULL);



  exit(EXIT_SUCCESS);
}



void *functionC()

{
  int i=0;
while(i++<5){
  pthread_mutex_lock( &m1 );

  counter++;

  printf("Counter value: %d\n",counter);
  pthread_mutex_unlock( &m2);
}
}
