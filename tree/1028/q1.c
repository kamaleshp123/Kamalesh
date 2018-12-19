#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char* rm_dup(const char *temp)
{
  int l;
  puts("*********");

  char *str=(char*)malloc(sizeof(char)*strlen(temp));
if(str){
  memcpy(str,temp,sizeof(strlen(str)));
  int i=0,j,k=0,cnt=0;
  for(l=0;str[l];l++);
  printf("%d\n ",l);
  for(i=0;i<l;i++)
  {
    for(j=i+1;j<l;j++)
    { 
      if(str[i]==str[j])
    {
    for(k=j;k<l;k++)
    {          str[k]=str[k+1];
    }

      j--;
      l--;
    }
  }
  str[i]='\0';
  puts(temp);
  return str;
}
}
else
{
  puts("--ERROR--");
}

}


char* rev(const char *str)
{
  int i=0;
  int j=strlen(str)-1;

  char *temp=(char *)malloc(strlen(str));
 if(temp){
  while(j>=0)
  {
    temp[i++]=str[j--];
  }
  temp[i]='\0';
//  puts(temp);
  return temp;
 }
 else
 {
   puts("--ERROR");
 }
}


void count_occ(char *str)
{

}



int main(int argc,char *argv[])
{
  char str[30],*buff;
  scanf("%s",str);
 buff= rm_dup(str);

  printf("rev %s\n",rev(buff));
}
