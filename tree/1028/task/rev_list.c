
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;

void add_last(NODE**p)
{
    NODE *nu;
    NODE *temp=(*p);
    nu=calloc(1,sizeof(NODE));
    puts("enter data");
    scanf("%d",&nu->data);
    if((*p)==0)
    {
        (*p)=nu;
        return;
    }
    else{
        while(temp&&temp->next)
        {
            temp=temp->next;
        }
        temp->next=nu;
        
        
    }
}

static void reverse(struct Node** head_ref) 
{ 
    struct Node* prev   = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next = NULL; 
    while (current != NULL) 
    { 

        next  = current->next;   
  

        current->next = prev;    
  

        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 
void rev_list(NODE**p)
{
NODE *temp=0;
NODE *prev=0;
NODE *cur=(*p);
while(cur)
  {
    puts("****\n");
    temp=(cur)->next;
    (cur)->next=prev;
    prev=(cur);
    (cur)=temp;
    
  }
(*p)=prev;

}

void disp(NODE**p)
{
    while(*p)
{
    printf("%d->",(*p)->data);
    (*p)=(*p)->next;
}
    
}


int main()
{
    NODE *p=NULL;
        int no;
        puts("enter no of element");
        scanf("%d",&no);

while(no--)
{
  add_last(&p);
}
puts("before rev \n");
disp(&p);

rev_list(&p);
puts("after rev \n");
disp(&p);
        

    return 0;
}



