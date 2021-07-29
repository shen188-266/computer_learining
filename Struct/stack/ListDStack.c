
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
    int SLength1;
    int SLength2;
}*Stack;
int IsEmpty(Stack stacks,int i)  //i=1,i=2
{

    return i==1?stacks->SLength1==0:stacks->SLength2==0;
}
int IsFull(Stack stacks)
{
    return stacks->SLength2 + stacks->SLength1>=MAXSIZE;
}
Stack StackCreat()
{
    Stack stacks=(Stack)malloc(sizeof(struct stack));
    if(stacks==NULL)
    {
        printf("can't allocate!");
        exit(1);
    }
    stacks->SLength1=0;
     stacks->SLength2=0;
    return stacks;
}
int Push(Stack stacks,Element e,int i)
{
    if(i==1){
    if(!IsFull(stacks))
    {
        stacks->elements[stacks->SLength1].ele=e.ele;
        stacks->SLength1++;
        return 1;
    }
    else
    {
        printf("1 IsFull");
        exit(2);
    }
    }
    else if(i==2){
        if(!IsFull(stacks))
    {
        stacks->SLength2++;
        stacks->elements[MAXSIZE-stacks->SLength2].ele=e.ele;
        return 1;
    }
    else
    {
        printf("2 IsFull");
        exit(2);
    }
    }
}
Element Pop(Stack stacks,int i)
{
    if(i==1){
    if(!IsEmpty(stacks,1))
    {
        stacks->SLength1--;
        return stacks->elements[stacks->SLength1];
    }
    else
    {
        printf("1 IsEmpty");
        exit(3);
    }}
    else if(i==2){
        if(!IsEmpty(stacks,2))
    {
        stacks->SLength2--;
        return stacks->elements[MAXSIZE - stacks->SLength2 - 1];
    }
    else
    {
        printf("2 IsEmpty");
        exit(3);
    }}

}
Element Top(Stack stacks,int i)
{
    if(i==1){
    if(!IsEmpty(stacks,1))
    {
        return stacks->elements[stacks->SLength1];
    }
    else
    {
        printf("1 IsEmpty");
        exit(3);
    }}
    else if(i==2){
        if(!IsEmpty(stacks,2))
    {
        return stacks->elements[MAXSIZE - stacks->SLength2 ];
    }
    else
    {
        printf("2 IsEmpty");
        exit(3);
    }}

}
void AllDelete(Stack stacks,int i)
{
    if(i==1)
    stacks->SLength1=0;
    else if(i==2)
        stacks->SLength2=MAXSIZE;
}

int main(void)
{
    Stack stack=StackCreat();
    Element e;
    e.ele=5;
    Push(stack,e,2);
    printf("the top is %d: ",Top(stack,2).ele);
    Element n;
    n.ele=Pop(stack,2).ele;
    printf("the last is %d",n.ele);
    return 0;
}
