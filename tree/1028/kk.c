#include <unistd.h>
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>
#include<fcntl.h>
FILE *fp;
pthread_t t1,t2;
sigset_t   set1,set2;                                                                
char *userbufer=NULL;
int st,S=0,T=0;
char buf[10];

char* rev(const char *str);
int compare(char *buff, char *str);
void *com(void *str);
void *readf(void *str);


char* rev(const char *str)
{
  int i=0;
  int j=strlen(str)-1;

  char *temp=(char *)malloc(strlen(str));
  if(temp)
  {
    while(j>=0)
    {
      temp[i++]=str[j--];
    }
    temp[i]='\0';
    return temp;
  }

  else
  {
    puts("--ERROR");
  }
}


int compare(char *buff, char *str) 
{
  int i=0,cnt=0,flg=0; 
  if(strlen(buff)==strlen(str))
  {
    while(buff[i])
    {
      if( (str[i]==buff[i])||(str[i]==buff[i]+32) || (buff[i]==str[i]+32))
      {
        flg=1;
      }
      else
        return 1;
      i++;
    }

    if(flg)
    {

      return 0;
    }
  }
  else
    return 1;


}


void fun(int sig)
{

}

void *com(void *str)
{
sleep(1);
  int sig;
  sigset_t set;
  sigemptyset(&set);
  sigaddset(&set,SIGUSR1);
  char *str1=NULL;
 (void ) signal(SIGUSR1,fun);
   printf("**in t2\n"); 
  while(feof(fp)==0)
  {
    if(compare(buf,userbufer)==0)
    {
      str1=rev(userbufer);
      puts(str1);
      int l=strlen(str1);
      fseek(fp,-l,SEEK_CUR);
      fputs(str1,fp);
      printf("write->%s\n",buf);
    }
      memset(buf,'\0',strlen(buf));
    

      pthread_kill(t1,SIGUSR2);
  sigwait(&set,&sig);

  }
  pthread_exit(NULL);

}

void *readf(void *str)
{
  int sig;
  sigset_t set;
  sigemptyset(&set);
  sigaddset(&set,SIGUSR2);
signal(SIGUSR2,fun);
  printf("**in t1\n");

          while(fscanf(fp,"%s",buf)!=EOF)
     {
        printf("read->%s\n",buf);
        pthread_kill(t2,SIGUSR1);
  sigwait(&set,&sig);
    
  }

  pthread_exit(NULL);
}


int main(int argc,char* argv[])
{

  fp=fopen("text","r+");
  userbufer="fox";

  pthread_create(&t1,0,&readf,0);
  pthread_create(&t2,0,&com,0);

  pthread_join(t2,NULL);
  pthread_join(t1,NULL);
  fclose(fp);
}
