//头指针element没储存东西
#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int ele;
}Element;
typedef struct node
{
    Element item;
    struct node *next;
}Node;
typedef Node *Stack;
int IsEmpty(Stack stacks)
{
    return stacks->next==NULL;
}
Stack StackCreat()
{
    Node *stacks;
    stacks=(Node*)malloc(sizeof(Node));
    if(stacks!=NULL)
    {
        stacks->next=NULL;
        return stacks;
    }
    else return NULL;
}
int Push(Stack stacks,Element element)
{
    Node *newNode;
    newNode=(Node*)malloc(sizeof(Node));
    if(newNode)
    {
        newNode->item.ele=element.ele;
        newNode->next=stacks->next;
        stacks->next=newNode;
        return 1;
    }
    else return 0;
}
Element Top(Stack stack)
{
    return stack->next->item;
}
Element Pop(Stack stacks)
{
    if(!IsEmpty(stacks)){
    Element newE;
    newE.ele=stacks->next->item.ele;
    Node *p;
    p=stacks->next;
    stacks->next=p->next;
    free(p);
    return newE;
    }
    printf("isEmpty!");
    exit(0);
}
void AllDelete(Stack stacks)
{
    Node *p;
    p=stacks->next;
    while(p!=NULL)
    {
        stacks->next=p->next;
        free(p);
        p=stacks->next;
    }
}
void AllPrint(Stack stacks)
{
    Node *p=stacks->next;
    while(p!=NULL)
    {
        printf("%d  ",p->item.ele);
        p=p->next;
    }
}


int main(void)
{
    Stack stacks=StackCreat();
    Element e;
    e.ele=5;
    Push(stacks,e);
    printf("the top is %d: ",Top(stacks).ele);
    Element n;
    n.ele=Pop(stacks).ele;
    printf("the last is %d",n.ele);
    Push(stacks,e);Push(stacks,e);Push(stacks,e);Push(stacks,e);Push(stacks,e);Push(stacks,e);Push(stacks,e);Push(stacks,e);
    AllPrint(stacks);
    return 0;
}
