#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct node
{
int data;
struct node *next;
}NODE;

void insert(struct NODE **p)
{
struct NODE *temp=(*p),*nu;

nu=calloc(1,sizeof(struct NODE**));
puts("enter data");
scanf("%d",&(nu->data));

if((*p)==NULL){
(*p)->next=nu;
nu->next=NULL;
}
else
{
  while(temp->next)
  {
    temp=temp->next;
      }
temp->next=nu;
nu->next=NULL;

  
}
}


int main()
{
  int num;
  struct NODE* head=NULL; 
  puts("enter 1 -ip,2display,3 delete\n");
  scanf("%d",&num);

switch(num)
{

  case 1:insert(head);
         break;
//case 2:display(&head);
         break;

         
}

}
