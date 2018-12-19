
#include<stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct node
{
  int value1;
  struct node *nxt;
} node ;

typedef struct stack
{
  node *top;
}str;


void push(str *,int);
int pop(str *);
void display(str *,char);

str initStack() {
  str st ;
  st.top = NULL ;
  return st ;
}

void main()
{
  int i,j,k,a,b;
  pthread_t t1;

  int value=0;
  str top1 = initStack() ;
  str top2 = initStack() ;
  str top3 = initStack() ;
  
  printf("Enter number of disks:");
  scanf("%d",&i);
int ch ='K';
  pthread_create(&t1,NULL,dsplay,&ch);

  for(j=i;j>=1;j--)
  {
    push(&top1,j);
  }

  display(&top1,'S');
  display(&top2,'A');
  display(&top3,'D');

  for(k=1;k < 1<<i ;k++)
  {
    a=(k&k-1)%3;
    b=((k|k-1)+1)%3;

    switch(a)
    {
      case 0: value=pop(&top1);
              break;
      case 1: value=pop(&top2);
              break;
      case 2: value=pop(&top3);
              break;
    }

    switch(b)
    {
      case 0: push(&top1,value);
              break;
      case 1: push(&top2,value);
              break;
      case 2: push(&top3,value);
              break;
    }
    display(&top1,'S');
    display(&top2,'A');
    display(&top3,'D');
    printf("\n") ;
  printf("********************\n");
  }
}

void push(str *s,int t)
{
  node *n1 = (node*)malloc(sizeof(node)) ;
  n1->value1 = t;
  n1->nxt = s->top ;
  s->top = n1 ;   
}

int pop(str *s)
{
  node *n2 = s->top ;   
  s->top = n2->nxt ;
  char ch = n2->value1 ;
  free(n2) ;
  return ch;
}    

void display(str *st,char ch) {
  node *s = st->top ;
  while(s!=NULL)
  {
    printf("%c-----%d ",ch,s->value1);
    s = s->nxt ;
  }
  printf("\n") ;
}
