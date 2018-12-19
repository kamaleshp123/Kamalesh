


#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* next;
  struct node* prev;
};

struct node* last_rec(struct node* p)
{
  if(p==NULL)
  {
    puts("ERROR\n");
    return 0;
  }
  if(p->next==NULL)
    return p;
  else
    last_rec(p->next);
      
}

struct node* rec_alter(struct node* p)
{
  if(p->next==NULL)
    return p;
  else{
  printf("%d->",p->data);
  rec_alter(p->next->next);
  }
}

struct node* insert(struct node* head)
{
  struct node* temp=head;
  struct node* nu;

  nu=(struct node*)malloc(sizeof(struct node));
  scanf("%d",&nu->data);
  if(head==NULL)
  {
    head=nu;
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
  return head;
}



void printl(struct node* p)
{
  while(p)
  {
    printf("%d ",p->data);
    p=p->next;
  }
}

struct node* rev(struct node* h)
{
  struct node* temp=NULL;
  struct node* p=h;
  struct node* q=p->next;

  if(h->next==NULL)
    return h;
  else
  {

    temp= rev(h->next);
    h->next->next=h;
    h->next=NULL;
    return temp;
  }
}


struct node* double_ll(struct node* p)
{
  struct node* temp=p;
  if(p==NULL)
  {
    puts("ERROR first insert\n");
    exit(0);
  }



  while(temp->next)
  {
    temp->next->prev=temp;
    temp=temp->next;
  }
  temp->next=p;
  p->prev=temp;

  return p;
}

void move_fw(struct node* p)
{
  if(p==NULL)
  {
    puts("ERROR first insert\n");
    exit(0);
  }

  struct node* temp=p;
  struct node* flag=p;
  while(temp)
  {
    printf("%d->",temp->data);
    temp=temp->next;
    if(temp==flag)
    {
      break;
    }
  }

}

void move_bw(struct node* p)
{
  if(p==NULL)
  {
    puts("ERROR first insert\n");
    exit(0);
  }

  if(p->prev==NULL)
  {
puts("double it first\n");
return;
  }
  struct node* temp=p;
  struct node* flag=p->prev;
  while(temp)
  {
    temp=temp->prev;
    printf("%d-> ",temp->data);
    if(temp->prev==flag)
    {
      break;
    }
  }
}
int main()
{
  int i=0,opt,cnt=0;
  struct node* head=NULL;

  //while(i++!=6)
  // head=insert(head);
  while(1)
  {
    puts(" 1.insert\n");
    puts(" 2.print\n");
    puts(" 3.double\n");
    puts(" 4.move fwrd\n");
    puts(" 5.move bkwrd\n");
    puts(" 6.last node\n");
    puts(" 7.alternate\n");
    puts(" enter option\n");
    scanf("%d",&opt);
    switch(opt)
    {
      case 1:scanf("%d",&cnt);
             while(i!=cnt)
             {
             head=insert(head);
             i++;
             }
             break;
      case 2:printl(head);
             break;
      case 3:head=double_ll(head);       
             break;
      case 4:move_fw(head);
             break;
      case 5:move_bw(head); 
             break;
      case 6:head=last_rec(head); 
             break;
      case 7:head=rec_alter(head); 
             break;
      default:
             exit(0);
             break;      
    }
  }
  // printl(head);
}


