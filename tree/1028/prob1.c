#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include <ctype.h>
pthread_t tid1,tid2;
 pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
 pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;
              
struct data
{
  char *string;
  char *filename;
  char *word1;
};


FILE *fptr;



char* lowercase(char* a)
{
  char *b;
  int i;

  for ( i = 0; i < strlen(a); i++)
  {
    b[i] = tolower(a[i]);   
  }
  return b;
}

int stringcompare(char* a, char* b)
{
  printf("***************");
  return strcmp(lowercase(a), lowercase(b));
}

char* reverse(char *str)
{
  char *rev;
  int i=0,j=strlen(str)-1;
  while(j>=0)
  {
    rev[i++] = str[j--];
   // j--;
   // i++;
  }
  rev[i] = '\0';
  puts(rev);
//  return rev;
}


char* compare_string(void *db)
{
  char *str;
  struct data *temp=db;

    pthread_mutex_lock(&m2);
  printf(" in t2 %s\n",temp->word1);
  
  if(strcmp(temp->word1,temp->string)==0)
  {
    // printf(" r**%s",reverse(temp->string));
    printf(" string is equal");
  }

    pthread_mutex_unlock(&m1);
  //  fputs(str,fptr);


 // printf("in t2 %s\n",temp->string);

}



void read_from_file(void *db)
{

  struct data *temp=db;
  char word[10],st;
  char *str;

  fptr=fopen(temp->filename,"r+");
  //  fptr=freopen(temp->filename,"r",stdin);
  while(st!=EOF)
  {
    pthread_mutex_lock(&m1);
    st=fscanf(fptr,"%s",word);
    temp->word1=word;
    //gets(st);
    printf("in th1%s\n",word);
    //return word; 
    pthread_create(&tid2,0,&compare_string,temp);

    pthread_mutex_unlock(&m2);
    pthread_join(tid2,0);
    printf(" in 1 %s\n",str);
  }


}




int main(int argc,char* argv[])
{
  char string[100];
  char *str2="kamal";
  struct data db;
  db.string=argv[2];
  db.filename=argv[1];

//  char *str=(char)malloc(sizeof(argv[2]));
  printf("in main n\n");


  pthread_create(&tid1,0,&read_from_file,&db);
  pthread_join(tid1,NULL);



  reverse(str2);
//  printf("in main \n");
}
