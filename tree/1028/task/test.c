#include<stdio.h> 
#include<stdlib.h> 

struct Node 
{ 
  int data; 
  struct Node* next; 
}; 


struct Node* rev(struct Node* start); 
void printList(struct Node *head); 

struct Node*  merge_list(struct Node*p,struct Node* mid,struct Node* half,struct Node* prev)
{
  
  while(p->next)
  {
    p=p->next;
  }
  if(mid){
    p->next=mid;
    mid->next=half;
  }
  else 
  {
    p->next=half;
  }
return p;
}


struct Node* find_middle(struct Node* head)
{
  struct Node* temp=(head);
  struct Node* temp1=(head);
  struct Node* prev=NULL;
  struct Node* half=(head);
  struct Node* lat=(head);
  struct Node* mid=NULL;

  while(temp1->next && temp1->next->next)
  {
    temp1 =temp1->next->next;
    prev =temp;
    temp=temp->next;
  }
  if(temp1->next==NULL)
  {
//    mid=temp;
    half=temp->next;
    temp->next=NULL;
    prev->next=NULL;
  head=rev(head);
  half=rev(half);
  }
  else 
  {
   half=temp->next;
   temp->next=NULL;
  head=rev(head);
  printList(head);
  half=rev(half);
  }
  
//lat=head;
 head= merge_list(head,temp,half,prev);
/*  while(lat->next)
  {
    lat=lat->next;
  }
  if(temp){
    lat->next=temp;
    temp->next=half;
  }
  else
  {
    lat->next=half;
  }
*/
  return head;
}

struct Node*  rev(struct Node* start) 
{ 
  struct Node* prev   = NULL; 
  struct Node* current = (start); 
  struct Node* next = NULL; 
  while (current ) 
  { 
    next  = current->next;   

    current->next = prev;    

    prev = current; 
    current = next; 
  } 
  (start) = prev; 
  return start;
} 

void insert(struct Node** head) 
{ 
  struct Node* new =(struct Node*) malloc(sizeof(struct Node));          
  puts("enter data\n"); 
  scanf("%d",&new->data); 
  struct Node* temp=(*head);
  if((*head)==NULL)
  {
    (*head)=new;
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

int main() 
{ 
  struct Node* head = NULL; 
  int n;
  while(1)
  {
    puts(" enter option\n");
puts("\n 1. insert\n");
puts("\n 2. disp\n");
puts("\n 3. rev\n");
    scanf("%d",&n); 
    switch(n)
    {
      case 1:insert(&head);
             break;
      case 2:printList(head);     
             break;
      case 3: head=find_middle(head);                       
              break;
    }
  }    
}
