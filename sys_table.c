#include<stdio.h>
#define max 3
void add(void)
{
  printf("addition\n");
}
void sub(void)
{
  printf("substraction\n");
}
void mul(void)
{
  printf("multiplication\n");
}
void div(void)
{
  printf("division\n");
}

typedef struct
{
  int key;
  void(*fun)(void);
}task_t;


task_t task_table[]=
{
  {0,add},
  {2,sub},
  {3,mul},
  {4,div}
};


void reg(int n)
{
  int index =0;
  task_t *ptr=(task_t *)task_table;
  for(index;index<=max;index++)
  {  
    if(ptr[index].key==n)
      (*ptr[index].fun)();
 
  }
}


int main()
{

  int num;
  printf("enter no from 1-4\n");
  scanf("%d",&num);
  reg(num);
}
