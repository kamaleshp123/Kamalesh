#include<stdio.h>
#include<string.h>
FILE *fp;
  char* rev(char *str)
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
      return rev;
    }
    

  
int main(int argc,char *argv[])
{
  char *buff,str[20];

fp=fopen("./file.c","r+");
printf("**********\n");
while(fscanf(fp,"%s",str)!=EOF)
{
  if(strcmp(str,argv[2])){
      fseek(fp,-(sizeof(str)),1);
      fputs(rev(argv[2]),fp);
      fseek(fp,-(sizeof(str)),1);
}
}
fclose(fp);

}

