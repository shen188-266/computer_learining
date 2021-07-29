
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000//CAN BE CAHNGE
typedef struct element
{
    int ele;
}Element;
typedef struct stack
{
    Element elements[MAXSIZE];
    int SLength;
}*Stack;
int IsEmpty(Stack stacks)
{
    return stacks->SLength==0;
}
int IsFull(Stack stacks)
{
    return stacks->SLength==MAXSIZE;
}
Stack StackCreat()
{
    Stack stacks=(Stack)malloc(sizeof(struct stack));
    if(stacks==NULL)
    {
        printf("can't allocate!");
        exit(1);
    }
    stacks->SLength=0;
    return stacks;
}
int Push(Stack stacks,Element e)
{
    if(!IsFull(stacks))
    {
        stacks->elements[stacks->SLength].ele=e.ele;
        stacks->SLength++;
        return 1;
    }
    else
    {
        printf("IsFull");
        exit(2);
    }
}
Element Pop(Stack stacks)
{
    if(!IsEmpty(stacks))
    {
        stacks->SLength--;
        return stacks->elements[stacks->SLength];
    }
    else
    {
        printf("IsEmpty");
        exit(3);
    }
}
Element Top(Stack stacks)
{
    if(!IsEmpty(stacks))
    {
        return stacks->elements[stacks->SLength-1];
    }
    else
    {
        printf("IsEmpty");
        exit(3);
    }
}
void AllDelete(Stack stacks)
{
    stacks->SLength=0;
}

int main(void)
{
    Stack stack=StackCreat();
    Element e;
    e.ele=5;
    Push(stack,e);
    printf("the top is %d: ",Top(stack).ele);
    Element n;
    n.ele=Pop(stack).ele;
    printf("the last is %d",n.ele);
    return 0;
}
