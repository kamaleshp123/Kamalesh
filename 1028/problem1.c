#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<signal.h>

#define no_msg 20

int cnt=0;
  FILE *fp,*fd;
//pthread_mutex m1;
int size=0;
pthread_mutex_t m1= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;

struct node
{
  int data;
  struct node *next;
}*head = NULL;


struct que 
{ 
  struct node *front, *rare; 
}; 


struct que *create(int n)
{ 
  struct que *q1=(struct que*)malloc(sizeof(struct que)*n);
  q1->front=q1->rare=NULL;
  return q1;
}

struct node* newnode(int value)
{ 
  struct node *nu=(struct node*)malloc(sizeof(struct node));
  nu->data=value;
  nu->next=NULL;
  return nu;

}

void handler(int signum)
{
  signal(SIGUSR1,handler);
  printf("no more enqueue\n");

}

void enqueue(struct que *q, int value) 
{ 
  struct node *nu ; 
  nu=newnode(value);
  if (q->front == NULL) 
    q->front = nu; 
  else
    q->rare->next = nu; 

  q->rare = nu; 
  q->rare->next = q->front; 
} 

int dequeue(struct que *q) 
{ 
  int value;
  if (q->front == NULL) 
  { 
    printf ("Queue is empty"); 
    return 0; 
  } 

  if (q->front == q->rare) 
  { 
    value = q->front->data; 
    free(q->front); 
    q->front = NULL; 
    q->rare = NULL; 
  } 
  else  // There are more than one nodes 
  { 
    struct node *temp = q->front; 
    value = temp->data; 
    q->front = q->front->next; 
    q->rare->next= q->front; 
    free(temp); 
  } 

  return value ; 
} 


void display(struct que *q) 
{ 
  struct node *temp = q->front; 
  printf("\nElements in Circular Queue are: "); 
  while (temp->next != q->front) 
  { 
    printf("%d ", temp->data); 
    temp = temp->next; 
  } 
  printf("%d", temp->data); 
} 

void *fun1(void* que)
{
  int no,i,m;
  char *ret;
  pthread_mutex_lock( &m1 );
signal(SIGUSR1,handler);
  scanf("%d",&no);

  for(i=0;i<no;i++)
  {
    scanf("%d",&m);
        enqueue(que,m);
        size++;
  }
  printf("enqeued %d msgs\n",no);
  if(size>=20)
    kill(getpid(),SIGUSR1);
  pthread_mutex_unlock( &m1 );
}


void *fun2(void* que)
{
  int no,i,m;

  pthread_mutex_lock( &m1 );

//printf("%d",no);
  scanf("%d",&no);
  for(i=0;i<no;i++)
  {
  //printf("%d ", dequeue(que));

       fprintf(fd,"%d ",dequeue(que));
  }
  printf("denqeued %d msgs\n",no);
  pthread_mutex_unlock( &m1 );
}

int main()
{
  void *ret;
  pthread_t t1,t2;
  int request,no,t,i;
  fd=fopen("/home/patilkam/ipc/practice/1028/out.txt","a");
fp=freopen("/home/patilkam/ipc/practice/1028/test.txt","r",stdin);
//while(1){
//  puts("enter request");
  struct que *q=create(no_msg);
  scanf("%d",&t);
for(i=0;i<t;i++)
{
  scanf("%d",&request);


  if(request==1)
    pthread_create(&t1,NULL,fun1,(void*)q);
  
 if(request==2)
    pthread_create(&t2,NULL,fun2,(void*)q);


  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
}
  /*
     enqueue(q,10);
     enqueue(q,20);
     enqueue(q,30);
     display(q);
     */
        
//
fclose(fd);
}
