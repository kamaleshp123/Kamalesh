#include<stdio.h> 
#include<stdlib.h> 

struct Node 
{ 
  int data; 
  struct Node* next; 
}; 

int cnt=0,pass=0,fail=0;
struct Node* com=NULL;


struct Node* find_com_node(struct Node* h1,struct Node* h2)
{
  struct Node* t1=h1;
  struct Node* t2=h2;
  if(h1==NULL||h2==NULL)
  {
    puts("list is empty\n");
    return 0;
  }
  while(t1)
  {
    t2=h2;
    while(t2)
    {
      if(t1==t2)
      {
        printf(" **%d\n",t2->data);
        return t2;
      }
      t2=t2->next;
    }
    t1=t1->next;

  }
}


struct Node* find_rec(struct Node* h1,struct Node* h2)
{
  if(h1==h2)
    retuen h2;
  if(h2!=NULL)
  {
    find_rec(h1,h2->next);
  }
  else
  {
    h2=com;
    find(h1->next,h2);
  }
}
 

int merge(struct Node* h)
{
  if(h)
  {
    while(h->next)
    {
      h=h->next;
    }
    h->next=com;
    return 0;
  }
  else
  {
    puts("list is empty\n");
    return 1;
  }
}


int set_com(struct Node* h,int n)
{
  int cnt1=0;
  if(h)
  {
    while(h)
    {
      cnt1++;
      if(cnt1==n){
        com=h;
        break;
      }
      h=h->next;
    }
    return 0;
  }
  else
  {
    puts("list is empty\n");
    return 1;
  }

}

struct Node* last(struct Node* p)
{
  while(p)
  {  p=p->next;
  }
  return p;
}
struct Node*  insert(struct Node* head,int data)
{

  struct Node* new =(struct Node*) malloc(sizeof(struct Node));          
  //puts("enter data\n"); 
  //scanf("%d",&new->data); 
  new->data=data;
  struct Node* temp=(head);
  if((head)==NULL)
  {
    (head)=new;
    new->next=NULL;
  }
  else
  {
    while(temp->next)
    {
      temp=temp->next;
    }
    temp->next=new;
    new->next=NULL;
  }

  return head;

}

struct Node* insert_L1(struct Node* head) 
{
  head=insert(head,1); 
  head=insert(head,2); 
  head=insert(head,3); 
  head=insert(head,4); 
  head=insert(head,5); 
  head=insert(head,6); 
  head=insert(head,7); 

  return head; 
} 



struct Node* insert_L2(struct Node* head) 
{ 
  head=insert(head,12); 
  head=insert(head,13); 
  head=insert(head,14); 
  head=insert(head,15); 
  head=insert(head,16); 
  return head;
} 

void printList(struct Node *head) 
{ 
  struct Node *temp = head; 
  while(temp != NULL) 
  { 
    printf("%d  ", temp->data);     
    temp = temp->next;   
  } 
}     

void test1(struct Node*h1 ,struct Node* h2)
{
  /********testcase1******* Random**/
  struct Node* temp;
  int acc=5;
  set_com(h1,5);
  merge(h2);
  temp=find_com_node(h1,h2);
  printf("node =%d\n",temp->data);
  if( temp->data==acc)
    pass++;
  else{ 
    fail++;
    puts("test case 1 fail\n");
  }
}

void test2(struct Node*h1 ,struct Node* h2)
{
  int acc;
  struct Node* temp;
  /********testcase2******* at last**/
  acc=7;
  set_com(h1,7);
  merge(h2);
  temp=find_com_node(h1,h2);
  printf("node =%d\n",temp->data);
  if( temp->data==acc)
    pass++;
  else{ 
    fail++;
    puts("test case 1 fail\n");
  }
}


void test3(struct Node*h1 ,struct Node* h2)
{
  /********testcase3*********/
  struct Node* temp;
  int acc=1;
  set_com(h1,1);
  merge(h2);
  temp=find_com_node(h1,h2);
  printf("node =%d\n",temp->data);
  if(temp->data==acc)
    pass++;
  else 
    fail++;
}

void test4(struct Node*h1 ,struct Node* h2)
{
  int st,st1;
  /********testcase3*********/
  h2=NULL;
  struct Node* temp;
  int acc=1;
  set_com(h1,1);
  merge(h2);
  temp=find_com_node(h1,h2);
  //printf("node =%d\n",temp->data);
  if(st||st1)
    pass++;
  else
    fail++;


}

void test5(struct Node*h1 ,struct Node* h2)
{
  int st,st1;
  /********testcase3*********/
  h1=NULL;
  struct Node* temp;
  int acc=1;
  temp=find_com_node(h1,h2);
  //printf("node =%d\n",temp->data);
  if(st||st1)
    pass++;
  else
    fail++;


}

void test6(struct Node*h1 ,struct Node* h2)
{
  int st,st1;
  /********testcase3*********/
  h2=NULL;
  h1=NULL;
  struct Node* temp;
  int acc=1;
  temp=find_com_node(h1,h2);
  //printf("node =%d\n",temp->data);
  if(st||st1)
    pass++;
  else
    fail++;

}

void test7(struct Node*h1 ,struct Node* h2)
{
  int st,st1,acc=3;
  /********testcase3**** *****/
  h2=h1->next->next;
  struct Node* temp;
  temp=find_com_node(h1,h2);
  //printf("node =%d\n",temp->data);
  if(temp->data==acc)
    pass++;
  else
    fail++;

}

void test8(struct Node*h1 ,struct Node* h2)
{
  /********testcase3*********/

  struct Node* temp;
  struct Node* l=h1;
  int acc=7;
  //  l=last(h1);
  /* while(l->next)
     {
     l=l->next;
     }
     */
  h2=l;
  temp=find_com_node(h1,h2);
  //printf("node =%d\n",temp->data);
  if(temp->data==acc)
    pass++;
  else
    fail++;

}

int main() 
{

  struct Node* head1 = NULL; 
  struct Node* head2 = NULL;
  struct Node* temp = NULL;
  head1=insert_L1(head1);
  printList(head1);
  head2=insert_L2(head2);
  int acc,n;
  while(1){
  puts("enter test case no, 1-7");
  scanf("%d",&n);
  switch(n)
  {
  case 1:
  test2(head1,head2);
  break;
  case 2:
  test3(head1,head2);
  break;
  case 3:
  test4(head1,head2);
  break;
  case 4:
  test5(head1,head2);
  break;
  case 5:
  test6(head1,head2);
  break;
  case 6:
  test7(head1,head2);
  break;
  case 7:
  test8(head1,head2);
break;
  }
  printf("pass=%d  fail=%d \n ",pass,fail);
  }
}
