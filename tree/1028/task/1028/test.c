#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* next;
  struct node* prev;
};

struct node* dsc(struct node* h1, struct node* h2);
struct node* asc(struct node* h1, struct node* h2);
int check_ll(struct node* h1,struct node* h2);


struct node* merge(struct node* h1, struct node* h2)
{
  if(h1==NULL&&h2==NULL)
  {
    puts("----ERROR--\n");
    exit(0);
  }
  if(check_ll(h1,h2))
    return asc(h1,h2);
  else
    return dsc(h1,h2);
}


struct node* dsc(struct node* h1, struct node* h2)
{
  struct node* temp=NULL;
  struct node* temp2=NULL;
  if(h1==NULL)
  {
    puts("----ERROR---list1 is empty \n");
  exit(0);
  }
  if(h2==NULL)
  {
    puts("----ERROR---list1 is empty \n");
  exit(0);
  }
  if(h1->data>=h2->data)
  {
    temp=h1;
    h1=h1->next;
    if(temp2==NULL)
      temp2=temp;
  }
  else
  {
    temp=h2;
    h2=h2->next;
    if(temp2==NULL)
      temp2=temp;
  }
  while(h1&&h2)
  {
    if(h1->data>=h2->data)
    {
      temp->next=h1;
      temp=h1;
      h1=temp->next;
    }
    else
    {
      temp->next=h2;
      temp=h2;
      h2=temp->next;
    }
  }
  if(h1==NULL)
  {
    temp->next=h2;
  }
  if(h2==NULL)
  {
    temp->next=h1;
  }
  return temp2;
}


struct node* asc(struct node* h1, struct node* h2)
{
  struct node* temp=NULL;
  struct node* temp2=NULL;
  if(h1==NULL)
  {
    puts("----ERROR---list1 is empty \n");
  exit(0);
  }
  if(h2==NULL)
  {
    puts("----ERROR---list2 is empty \n");
  exit(0);
  }
    return h2;
  if(h1->data<=h2->data)
  {
    temp=h1;
    h1=h1->next;
    if(temp2==NULL)
      temp2=temp;
  }
  else
  {
    temp=h2;
    h2=h2->next;
    if(temp2==NULL)
      temp2=temp;
  }
  while(h1&&h2)
  {
    if(h1->data<=h2->data)
    {
      temp->next=h1;
      temp=h1;
      h1=temp->next;
    }
    else
    {
      temp->next=h2;
      temp=h2;
      h2=temp->next;
    }
  }
  if(h1==NULL)
  {
    temp->next=h2;
  }
  if(h2==NULL)
  {
    temp->next=h1;
  }

  return temp2;

}
int check_ll(struct node* h1,struct node* h2)
{
  if(h1->data<h1->next->data)
    return 1;
  else
    return 0;
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
    printf("%d-> ",p->data);
    p=p->next;
  }
}

int main()
{
  int i=0,opt,cnt=0;
  struct node* head1=NULL;
  struct node* head2=NULL;
  struct node* head=NULL;
  while(1)
  {
    puts("enter choice\n");
    puts("1.insert L1 \n");
    puts("2.insert L2\n");
    puts("3.merge\n");
    scanf("%d",&opt);
    switch(opt)
    {

      case 1:
        puts("enter l1\n");
        while(i++!=6)
        {

          head1= insert(head1);
        }
        printl(head1);
        break;
      case 2:
        i=0;
        puts("enter l2\n");
        while(i++!=6)
        {
          head2=insert(head2);
        }
        printl(head2);
        break;
      case 3:
        head=merge(head1,head2);
        puts("after merge\n");
        printl(head);

    }
  }
}
