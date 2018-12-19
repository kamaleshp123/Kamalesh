#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<signal.h>

struct node
{
  int data;
  struct node *next;
}*front=NULL,*rear=NULL;


void insert(int value)
{
  struct node *nu;
  nu=(struct node*)malloc(sizeof(struct node));
  nu->data=value;
  if(front==NULL)
    front=rear=nu;
  else
  {
    rear->next=nu;
    rear=nu;
  }

  printf("success\n");
}


void delete(void)
{

  if(front==NULL)
    printf("queue is empty\n");
  else
  {
    struct node *temp;
    temp=front;
    front=front->next;
    printf("\n deleted element %d \n",temp->data);
    free(temp);
  }

}


void display(void)
{
  sleep();
  struct node *temp=front;
  while(temp)
  {
    printf("%d",temp->data);
    temp=temp->next;
  }
}


int main()
{
  int i,n;
  pthread_t t1;
  freopen("/home/patilkam/ipc/practice/database","r",stdout);
  for(i=2;i<5;i++)
  {
    scanf("%d",&n);
    insert(n);

  }
  //pthread_create(&t1,NULL,&display,NULL);
  //usleep(1);

  //  signal(SIGINT,display);
  display();
  for(i=2;i<5;i++)
    delete();


}
