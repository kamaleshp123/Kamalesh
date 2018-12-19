
/*Ques:
 * In a given file,  find number count of occurrence of a given string in a file.
 * Change all capitals letter into small of small letter into capital for given string in the file.
 *
 * Example Input:
 * File Content: The quick brown fox jumps over the lazy dog
 * String Search: the
 *
 * Output File Content:  EHt quick brown fox jumps over EHT lazy dog 
 * Explanation: There are 2 string  The and the in given file are reverse with change case.
 *
 *


*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
FILE *fp;


int compare(char *buff, char *str) 
{
  int i=0,cnt=0,flg=0; 
  if(strlen(buff)==strlen(str))
  {
    while(buff[i])
    {
      if( (str[i]==buff[i])||(str[i]==buff[i]+32)||(buff[i]==str[i]+32))
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




int count_occ(char *str)
{
  char buff[10];
  int cnt =0;
  int i;
  char *temp=(char*)malloc(strlen(str));
  memcpy(temp,str,strlen(str));

  while(fscanf(fp,"%s",buff)!=EOF)
  {
    if(compare(buff,str)==0)
    {
      cnt++;
      i=0;
      while(buff[i])
      {
        if((buff[i]>='A'|| buff[i]<='Z')&&(!(buff[i]>='0'||buff[i]<='9')))
        {
          buff[i]=buff[i]-32;
        }
        else if((buff[i]>='a'||buff[i]<='z' )&&(!(buff[i]>='0'||buff[i]<='9')))
        {
          buff[i]=buff[i]+32;
        }
        i++;

      }
      fseek(fp,-(strlen(buff)),1);
      fputs(buff,fp);

    }


  } 

  return cnt;
}



int main(int argc,char* argv[])
{
  fp=fopen(argv[1],"r+");
  char str[30],*buff;
  //scanf("%s",str);
  //buff= rm_dup(str);
  printf("count %d\n",count_occ(argv[2]));
  fclose(fp);
}
