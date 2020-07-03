#include <stdio.h>
#include <stdlib.h>

struct Node
{
  char data;
  struct Node *next; // next pointer is of datatype `struct Node`
}*top=NULL;

void push(int x)
{
  struct Node *t; // creates variable *t with `Node` datatype
  t=(struct Node*)malloc(sizeof(struct Node));

  if(t==NULL) // if heap memory is full
    printf("stack is full\n");
  else
  {
    t->data=x;
    t->next=top;
    top=t;
  }
}

char pop()
{
  struct Node *t;
  int x = -1;
  if(top==NULL)
    printf("Stack is Empty\n");
  else
  {
    t=top; // assigns last element (element to be popped)
    top=top->next; // update top by saving the pointed(next) element
    x=t->data;
    free(t);
  }
  return x;
}

void Display()
{
  struct Node *p;
  p=top;
  while(p!=NULL)
  {
    printf("%d ",p->data);
    p=p->next;
  }
  printf("\n");
}

int isBalanced(char *exp)
{
  int i;
  for(i=0;exp[i]!='\0';i++)
  {
    if(exp[i] == '(')
      push(exp[i]);
    else if(exp[i] == ')')
    {
      if(top==NULL)
        return 0;
      pop();
    }
  }
  if(top==NULL)
    return 1;
  else
    return 0;
}

int main()
{
  char *exp="((a+b)*(c-d))";
  printf("%d ", isBalanced(exp));

  return 0;
}

