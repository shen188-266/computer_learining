#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


void createstack(stacklink * S)
{
    S->top=NULL;
    S->counts=0;

}
bool initialstack(stacklink * S,int n)
{
    createstack(S);
    while(n-->0)
    {
        Item temp;
        temp.a=n;
        push(S,&temp);
    }
    return 1;
}
bool clearstack(stacklink * S)
{
    Note * s=S->top,*p;
    if(s)
    {
        p=s->next;
        free(s);
        s=p;
    }
    S->top=NULL;
    S->counts=0;
    return 1;
}
Item gettop(stacklink * S)
{
    return S->top->items;
}
void pop(stacklink * S,Item *e)
{
    Note * s=S->top,*p;
    *e=s->items;
    p=s->next;
    S->top=p;
    free(s);
    S->counts--;
}
bool push(stacklink * S,Item *e)
{
    Note *p;
    p=(Note *)malloc(sizeof(Note));
    if(p)
    {
        p->items=*e;
        p->next=S->top;
        S->top=p;
        S->counts++;
        return 1;
    }
    return 0;
}
bool stack_is_empty(stacklink * S)
{
    return (S->top==NULL)?1:0;
}
int stacklength(stacklink * S)
{
    Note *p=S->top;
    int i=0;
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;
}
void showstack(stacklink * S)
{
    printf("the stack length is %d\n",S->counts);
    Note *p=S->top;
    while(p)
    {
        printf("%d ",p->items.a);
        p=p->next;
    }
    putchar('\n');
}
