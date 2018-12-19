#include<stdio.h> 
#include<stdlib.h> 

struct Node 
{ 
  int data; 
  struct Node* next; 
}; 

int cnt=0;
struct Node* com=NULL;


struct Node* find_com_node(struct Node* h1,struct Node* h2)
{
  struct Node* t1=h1;
  struct Node* t2=h2;
  if(h1==NULL||h2==NULL)
  {
    puts("list is empty\n");
    exit(0);
  }
  while(t1->next)
  {
  t2=h2;
    while(t2->next)
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

void merge(struct Node* h,int n)
{
  int cnt1=0;
  while(h)
  {
    h=h->next;
    cnt1++;
  }
  if(cnt1==n)
h=com;
}



void insert_L1(struct Node** head) 
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
  cnt++;
  if(cnt==1)
    com=temp;
} 



void insert_L2(struct Node** head) 
{ 
  int cnt=0;
  struct Node* temp=(*head);
  struct Node* new;
        while(cnt!=4)
            {
                  new=NULL;
                  temp=(*head);
                  new =(struct Node*) malloc(sizeof(struct Node));          
                   puts("enter data\n"); 
                  scanf("%d",&new->data); 
                   
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
                  cnt++;
              }
      new->next=com;
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
  struct Node* head1 = NULL; 
  struct Node* head2 = NULL; 
  struct Node* temp= NULL; 
  int n;
              while(1)
                  {
                          puts(" enter option\n");
                          puts(" 1. insert l1\n");
                          puts(" 2. insert l2\n");
                          puts(" 3. disp1\n");
                          puts(" 4. disp2\n");
                          puts(" 5. find com node\n");
                  
                          scanf("%d",&n); 
                        switch(n)
                            {
                               case 1:insert_L1(&head1);
                                      break;
                               case 2:insert_L2(&head2);
                                      break;
                               case 3:printList(head1);     
                                      break;
                               case 4:printList(head2);     
                                      break;
                               case 5: temp=find_com_node(head1,head2);                       
                                        printf("intersection node is=%d\n",temp->data);
                                      break;
                             }
                  }    
}
