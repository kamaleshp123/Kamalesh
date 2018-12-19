#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

struct q
{
  struct node *front,*rare;
};


struct node* newnode(int value)
{
  struct node *nu=(struct node*)malloc(sizeof(struct node));
  nu->data=value;
  nu->next=NULL;
  return nu;

}

struct q *create()
{
  struct q *q1=(struct q*)malloc(sizeof(struct q));
  q1->front=q1->rare=NULL;
  return q1;
}


void enqueue(struct q *q1,int value)
{
  struct node *nu;
  nu=newnode(value);
  if(q1->rare==NULL)
  {
    q1->front=q1->rare=nu;
  }

  q1->rare->next=nu;
  q1->rare=nu;
}


struct node *dequeue(struct q *q1)
{
  if(q1->front ==NULL)
    return NULL;

  struct node *temp=q1->front;
  q1->front=q1->front->next;
  if(q1->front==NULL)
    q1->rare=NULL;

  return temp;
}

int main()
{

  struct q *q1 = create(); 
  enqueue(q1, 10); 
  enqueue(q1, 20); 
  dequeue(q1); 
  dequeue(q1); 
  enqueue(q1, 30); 
  enqueue(q1, 40); 
  enqueue(q1, 50); 
  struct node *n = dequeue(q1); 
  if (n != NULL) 
    printf("Dequeued item is %d", n->data); 
  return 0; 

}

