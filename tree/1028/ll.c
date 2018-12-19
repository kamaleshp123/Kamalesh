#include<stdio.h> 
#include<stdlib.h> 

struct Node 
{ 
  int data; 
  struct Node* next; 
}; 

void reverse(struct Node* head,struct Node*last ); 
void check_eve_odd(struct Node** head)
{
  struct Node* temp=(*head);
  while(temp)
  {
    temp=temp->next;

  }
}

struct Node* find_middle(struct Node *head)
{
  struct Node* temp=(head);
  struct Node* temp1=(head);

  while(temp&&temp1)
  {
    temp1=temp1->next->next;
    temp=temp->next;
  }

  return temp;

}

void even(struct Node** head)
{
  struct Node *mid=find_middle((*head));
  struct Node *last=NULL;

  last= mid;
  reverse((*head),last);
  last=NULL;
  reverse(mid,last);

}
/*
   void reverse(struct Node* head,struct Node*last ) 
   { 

   struct Node* prev   = NULL; 
   struct Node* current = head; 
   struct Node* next = NULL; 
   while (current->next!= last) 
   { 
   next  = current->next;   
   current->next = prev;    
   prev = current; 
   current = next; 
   } 
   head = prev; 
   } 


   void odd(struct Node** head)
   {
   struct Node *mid=find_middle((*head));
   struct Node *last=NULL;

   }
   */
void reverse(struct Node* head,struct Node*last ) 
{ 

  struct Node* prev   = NULL; 
  struct Node* current = head; 
  struct Node* next = NULL; 
  while (current != last) 
  { 
    next  = current->next;   
    current->next = prev;    
    prev = current; 
    current = next; 
  } 
  head = prev; 
} 

void insert(struct Node** head)
{ 
  int data;
  struct Node* new = (struct Node*) malloc(sizeof(struct Node));            
  puts("enter data \n");
  scanf("%d",&data);
  new->data  = data; 
  new->next = (*head);     
  (*head)    = new; 
} 

void disp(struct Node** head) 
{ 
  struct Node *temp = (*head); 
  while(temp ) 
  { 
    printf("%d  ", temp->data);     
    temp = temp->next;   
  } 
}     


int main() 
{ 
  int no;
  struct Node* head = NULL; 
while(1){
  puts("enter choice");
  scanf("%d",&no);
  switch(no)
  {
  case 1:  insert(&head);
           break;
  case 2:disp(&head); 
         break;
 // case 3:reverse(&head);
   //      break;   
         //    even(&head);
         printf("\nReversed Linked list \n"); 
   
         //  disp(head);     
}
}
}

