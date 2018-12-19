#include <unistd.h>
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/syscall.h>
FILE *fp1,*fp2;
pthread_t t1,t2,main_id;
char *userbufer=NULL;
char buf1[100];
char buf2[100];

int i=0,T1=0,T2=0;
sigset_t set;
sigset_t set1;



void *T2_process_word(void *str)
{

  int sig,st2,k;
  sigset_t *set=str;
  sigwait(set,&sig);
  while((fscanf(fp1,"%s",buf2)!=EOF)&&(t2))
  {
    puts("----in T2---\n");
    puts(buf2);
    pthread_kill(main_id,SIGUSR1);
    sigwait(set,&sig);
  }
if(main_id)
    pthread_kill(main_id,SIGUSR1);

  pthread_exit(NULL);
}



void *T1_read_from_file(void *str)
{
  int sig,k;
  sigset_t *se=str;

  int st1=0;
  sigwait(se,&sig);
  while(fscanf(fp1,"%s",buf1)!=EOF)
  {  
    printf("----in T1---\n");
    puts(buf1);
    T1=1;
    pthread_kill(t2,SIGUSR1);
    sigwait(se,&sig);
  }
  if(t2)
    pthread_kill(t2,SIGUSR1);
    
  pthread_exit(NULL);
}

void init_main(void)
{
  sigemptyset(&set);
  sigaddset(&set, SIGUSR1);
  fp1=fopen("text1","r");
  fp2=fopen("text2","w+");

  pthread_sigmask(SIG_BLOCK, &set, NULL);

}

void create_thread(void)
{

  if(pthread_create(&t1,0,&T1_read_from_file,&set)!=0)
  {
    printf("thread1 is not created\n");
  }
  if( pthread_create(&t2,0,&T2_process_word,&set)!=0)
  {
    printf("thread1 is not created\n");
  }
  if(t1)
    pthread_kill(t1,SIGUSR1);

}



int main(int argc,char* argv[])
{

  init_main();
  create_thread();
  int sig;
  main_id=pthread_self();
  sigwait(&set,&sig);
  while(feof(fp1)==0)
  {

    puts("---in main-- \n");
    T1=0;
    T2=0;

    fputs(buf1,fp2);
    fputs(" ",fp2);
    fputs(buf2,fp2);
    fputs(" ",fp2);
    printf("----in main---\n");
    memset(buf1,'\0',100);
    memset(buf2,'\0',100);
    pthread_kill(t1,SIGUSR1);
    sigwait(&set,&sig);

  }
  if(buf1)
    fputs(buf1,fp2);
  if(buf2)
    fputs(buf2,fp2);
  puts("----done\n");
  // pthread_sigmask(SIG_UNBLOCK, &set, NULL);
fclose(fp1);
fclose(fp2);  //  printf("\n**********file updated********\n");
  exit(0);
}
