#include<stdio.h> 
#include<stdlib.h> 

struct Node 
{ 
  int data; 
  struct Node* next; 
  struct Node* top; 
}; 


struct Node* rev(struct Node* start); 


struct Node* find_middle(struct Node* head)
{
  struct Node* temp=(head);
  struct Node* temp1=(head);
  struct Node* prev=(head);
  struct Node* half=(head);
  struct Node* lat=(head);

  while(temp1->next && temp1->next->next)
  {
    temp1 =temp1->next->next;
    prev =temp;
    temp=temp->next;
  }
  if(temp1->next==NULL)
  {
    half=temp->next;
    temp->next=NULL;
    prev->next=NULL;
  }
  else 
  {
    half=temp->next;
    temp->next=NULL;
  }
  head=rev(head);
  half=rev(half);
  lat=head;
  while(lat->next)
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

  return head;
}


void pop(struct Node**p)
{

  struct Node* temp=(*p);
  if((*p)==NULL){
    puts("stack is empty\n");
  exit(0) ;
  } 
  (*p)=(*p)->next;
  temp=NULL;

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
    new->next=(*head);
    (*head)=new;


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
    scanf("%d",&n); 
    switch(n)
    {
      case 1:insert(&head);
             break;
      case 2:printList(head);     
             break;
      case 3: head=find_middle(head);                       
              break;
      case 4:pop(&head);
             break;
    }
  }    
}
