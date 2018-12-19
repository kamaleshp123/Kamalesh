#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
  int data;
  struct Node *next;
}*top =NULL,*scr=NULL,*aux=NULL,*dest=NULL;


void push(struct node *top,int value)
{
  struct node *nu;
   nu=(struct node*)malloc(sizeof(struct node));
  nu->data=value;
  if(top==NULL)
    nu->next=nu;
  else
  {
    nu->next=top;
    top=nu;
  }
}

int pop()
{
  int data;
  if(top==NULL)
    printf("emptyyy\n");
  else
  {
    struct node *temp=top;
    data=temp->data;
    top=top->next;
    free(temp);
    return data;
  }
}


void move(struct node *scr,struct node *dest,char s,char d)
{
  int t1=pop(scr);
  int t2=pop(dest);

  if(t1==NULL)
  {
    push(scr,t2);
    printf("%c to---->%c =%d\n",d,s,t2);

  }
  else if(t2==NULL)
  {
    push(dest,t1);
    printf("%c to---->%c =%d\n",s,d,t1);
  }
  else if(t1>t2)
  {
    push(scr,t1);
    push(scr,t2);
    printf("%c to---->%c =%d\n",d,s,t2);
  }
  else 
  {
    push(dest,t2);
    push(dest,t1);
    printf("%c to---->%c =%d\n",s,d,t1);
  }

}


void thoi(int no,struct node *scr,struct node *aux,struct node *dest)
{

  int i,mov;
  char s='S',d='D',a='A';

  if(no%2==0)
  {
    char temp=d;
    d=a;
    a=temp;

  }

  mov=(pow(2,no))-1;
printf("%d",mov);

  for(i=no;i<=mov;i++)
    push(scr,i);

  for(i=1;i<=no;i++)
  {
    if(i%3==1)
      move(scr,dest,s,d);
    else if(i%3==2)
      move(scr,aux,s,a);
    else if(i%3==0)
      move(aux,dest,a,d);
  }

}




int main()
{

  unsigned no=3;
  struct node *scr,*dest,*aux;
  thoi( no,scr,aux,dest);

  return 0;
}


