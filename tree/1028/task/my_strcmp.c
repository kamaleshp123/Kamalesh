#include<stdio.h>
#include<stdlib.h>

int my_strcmp(const char* str,const char* str1)
{
  int flag=0;
  while(*str!=NULL&&*str1!=NULL)
  {
    if(*str==*str1)
      flag =1;
  }

  if(flag==1)
    return 0;
  return 1;
}

int main()
{

  printf("**%d\n",my_strcmp("kamal","kamal"));
    printf("str equal\n");
    printf("str not equal\n");
}
