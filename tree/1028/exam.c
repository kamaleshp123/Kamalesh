#include <unistd.h>
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>
#include<fcntl.h>
FILE *fp;
pthread_t t1,t2;
//sigset_t   set1,set2;                                                                
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

void fun(int sig)
{
  usleep(100);
 // if(feof(fp)!=0)
   // pthread_kill(t1,SIGINT);
//  printf("in handler\n");
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


void *com(void *str)
{

 // sleep(1);
  printf("**in t2\n"); char *str1=NULL;
  //   T=2;
(void) signal(SIGUSR1,fun);




  //       sigwait(set,SIGUSR1);
  while(feof(fp)==0)
  {
    if(compare(buf,userbufer)==0)
    {
      str1=rev(userbufer);
      printf("write->%s\n",buf);
      puts(str1);
      int l=strlen(str1);
      fseek(fp,-l,SEEK_CUR);
      fputs(str1,fp);

    }
      memset(buf,'\0',strlen(buf));
    //  if(S==1)
    //  {

    pthread_kill(t2,SIGUSR2);
    pause();
    //  }



  }
  pthread_exit(NULL);

}

void *readf(void *str)
{

  (void) signal(SIGUSR2,fun); 
  printf("**in t1\n");

  while(feof(fp)==0)
  { 


    if(fscanf(fp,"%s",buf))
    {
      printf("read->%s\n",buf);
      //            if(T==2){ 
      pthread_kill(t2,SIGUSR1);
      //          }
      //        S=1;
      pause();

    }
  }


  pthread_exit(NULL);
}


int main(int argc,char* argv[])
{
  
  sigset_t set1;
  sigemptyset(&set1);
  sigaddset(&set1, SIGUSR2);
  sigaddset(&set1, SIGUSR1);
  /*  if(argc<3||argv[2]==NULL)
      {
      printf("use:<a.out><filename><string>");
      }
      */
  // fp=fopen(argv[1],"r+");
  // userbufer=argv[2];
  fp=fopen("text","r+");
  userbufer="patil";
  pthread_create(&t1,0,&readf,0);
  pthread_create(&t2,0,&com,0);
  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  fclose(fp);
  return 0;
}
