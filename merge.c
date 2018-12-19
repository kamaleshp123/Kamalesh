#include<stdio.h>
#include<stdlib.h>

struct Node
{
char ch;
  struct Node *next;
}*top = NULL;

void push(char );
char pop();
int check(char,char);
void display();

void main()
{
  int choice;
 char sym;

int i,num;


}
void push(char value)
{
  struct Node *newNode;
  newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->ch= value;
  if(top == NULL)
    newNode->next = NULL;
  else
    newNode->next = top;
  top = newNode;
}


int check(char ch,char ch1)
{

  if(ch=='{'&&ch1=='}')
    return 1;
  if(ch=='('&&ch1==')')
    return 1;
  if(ch=='['&&ch1==']')
    return 1;
}
char pop()
{
  char data;

if(top == NULL)
 printf("\nStack is Empty\n");
else{
    struct Node *temp = top;
data=temp->ch;
  printf("\nDeleted element: %c", temp->ch);
    top = temp->next;
    free(temp);
  return data;
}
}
void display()
{
char data;
  if(top == NULL)
  printf("\nStack is Empty\n");
  else{
    struct Node *temp = top;
    while(temp->next != NULL){
      printf("%c--->",temp->ch);
      data=temp->ch;

     temp = temp -> next;
    }
    printf("%c--->NULL",temp->ch);
  }

}    



