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
char *buf;

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
/*

   void *com(void *str)
   {

   int sig;
   sigset_t *set=str;
   char *str1=NULL;


   while(feof(fp)==0)
   {
   printf("**in t2\n"); 
   if(compare(buf,userbufer)==0)
   {
   str1=rev(userbufer);
   puts(str1);
   int l=strlen(str1);
   fseek(fp,-l,SEEK_CUR);
   fputs(str1,fp);
   printf("write->%s\n",str1);
   memset(buf,'\0',strlen(buf));
   }


   pthread_kill(t1,SIGUSR2);

   }
   pthread_exit(NULL);

   }

   void *readf(void *str)
   {


   while(feof(fp)==0)
   { 
   printf("**in t1\n");
   {
   fscanf(fp,"%s",buf);
   printf("read->%s\n",buf);

   }
   }

   }
   */

int main(int argc,char* argv[])
{
  char *str1=0;

  char *buf2;

  if((argc<3) || (argv[2]==NULL))
  {
    printf("ERROR---<a.out> <filename> <comp string> >");
    exit(0);

  }
  buf2=argv[3];
  fp=fopen(argv[1],"r+");
  if(fp==0)
  {
    puts("ERROR");
  }
  userbufer=argv[2];
  while(fscanf(fp,"%s",buf)!=EOF)
  {

    if(compare(buf,userbufer)==0)
    {
      str1=rev(userbufer);
      //    puts(str1);
      int l=strlen(str1);
      fseek(fp,-l,SEEK_CUR);
      fputs(str1,fp);
      printf("write->%s\n",str1);
      memset(buf,'\0',strlen(buf));
    }

  }

  fclose(fp);

  /*    int i;
        i=compare("prabhjottushar12345678910","PraBHjotTUSHAR12345678910");
        printf("%d \n",i);
        printf("%s\n",rev(argv[3]));
        */

}
