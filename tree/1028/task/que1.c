#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char* rev(const char* str)
{
  int i=0;
  int j=strlen(str)-1;
  char* ptr; 
  ptr=(char *)malloc(strlen(str));

  while(j>=0)
  {
    ptr[i++]=str[j--];
  }
  ptr[i]='\0';
  return ptr;
}


int fStrStr(char* str, char* strSub)
{
  int i=0, j=0;
  int nTemp = i;
  int nStrLen = strlen(str);
  int nStrSubLen = strlen(strSub);
  for(i=0; i<nStrLen-nStrSubLen; i++)
  {
    nTemp = i;
    for(j=0; j<nStrSubLen; j++)
    {

      if(str[nTemp]==strSub[j])
      {
        if(j==nStrSubLen-1)
          return 1;
        nTemp++;
      }
      else
        break;
    }
  }
  return 0;
}

char* my_strrstr(char* s1, char* s2)
{
  int i,j,temp=0;

  for(i=0;s1[i];i++)
  {
    if(s1[i]==s2[0])
    {
      temp=i;
      for(j=0;s2[j];j++)
      {
        if(s1[i++]==s2[j++])
        {
          if(j==strlen(s2)-1)
          {
            return;
          }
        }
        break;
      }

    }
  } 
  return s1+temp;
}

char* mystrcpy(char* dest,char* scr)
{
  // char* temp=(char *)malloc(strlen(dest));
  char* temp=dest;
  //while(*scr)
  //
  while(*dest++=*scr++);
  // }
  return temp;
  }

int main(int argc,char* argv[])
{
  char* str;
  str=(char *)malloc(strlen(argv[1]));
  str=argv[1];
  char *str1;
  str1=my_strrstr(str,argv[2]);
  mystrcpy(str1,rev(argv[2]));
  printf("%s\n",str);

}


