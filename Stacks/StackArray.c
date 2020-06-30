#include <stdio.h>
#include <stdlib.h>

struct Stack
{
  int size;
  int top;
  int *S;
};

void Create(struct Stack *st)
{
  printf("Enter size: ");
  scanf("%d", &st->size);
  st->top = -1;
  st->S=(int *)malloc(st->size*sizeof(int));
}

void Display(struct Stack st)
{
  int i;
  for(i=0;i<=st.top;i++)
    printf("%d ", st.S[i]);
  printf("\n");
}

void push (struct Stack *st, int x)
{
  if(st->top == st->size - 1)
    printf("Stack overflow\n");
  else
  {
    st->top++;
    st->S[st->top] = x;
  }
}

int pop (struct Stack *st)
{
  int x = -1;

  if(st->top == -1)
    printf("Stack underflow\n");
  else
  {
    x = st->S[st->top--];
  }
  return x;
}

int peep (struct Stack st, int index)
{
  int x = -1;
  if(st.top-index+1 < 0)
    printf("Invalid Index \n");
  x = st.S[st.top-index+1];

  return x;
}

int isEmpty(struct Stack st)
{
  if(st.top == -1)
    return 1;
  return 0;
}

int isFull(struct Stack st)
{
  return st.top == st.size-1;
}

int stackTop(struct Stack st)
{
  if(!isEmpty(st))
    return st.S[st.top];
  return -1;
}

int main()
{
  struct Stack st;
  Create(&st);

  push(&st, 10);
  push(&st, 20);
  push(&st, 30);
  push(&st, 40);

  printf("%d \n", peep(st, 4));

  Display(st);
  printf("%d\n", st.top);
  return 0;
}