#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct node
{
    Element element;
    struct node *next;
}*Node;
typedef Node Head;
int isEmpty(Head L)
{
    return L->next==L;
}
int findItem(Element e,Head L)
{
    Node p=L->next;
    int i=1;
    while(p!=L && p->element!=e)
    {
        p=p->next;
        i++;
    }
    if(p!=L)
    {
        return i;
    }
    else return 0;
}
Node getItem(int i,Head L)
{
    Node p=L->next;
    if(i<0)
        exit(1);
    if(i==0)
        return L;
    while(--i>0)
    {
        if(p->next!=L)
        p=p->next;
        else
        p=p->next->next;
    }
        return p;
}
Node getFItem(Element e,Head L)
{
    Node p=L->next;
    Node q;
    if(p->element==e)
        return L;
    while(p!=L && p->element!=e)
    {
        q=p;
        p=p->next;
    }
    if(p!=L)
        return q;
    else
        return NULL;
}
int deleteByI(int i,Head L)
{
    if(i<1)
        exit(2);

    Node p=getItem(i-1,L);
    if(!isEmpty(L))
    {
        if(p->next==L)
        p=L;

        Node q=p->next;

        p->next=q->next;
        free(q);
        L->element--;
        return 1;
    }
    return 0;
}
int insertItem(Element e,Head L)
{
    Node p=getFItem(e,L);
    Node newE=(Node)malloc(sizeof(struct node));
    if(newE==NULL)
        exit(3);

    newE->element=e;
    newE->next=p->next;
    p->next=newE;
    L->element++;
    return 1;
}
int insertByI(Element e,int i,Head L)
{
    Node p=getItem(i-1,L);
    Node newE=(Node)malloc(sizeof(struct node));
    if(newE==NULL)
        exit(3);

    newE->element=e;
    newE->next=p->next;
    p->next=newE;
    L->element++;
    return 1;
}
Head createList()
{
    Head lists=(Head)malloc(sizeof(struct node));
    lists->next=lists;
    lists->element=0;
    return lists;
}
void printList(Head L)
{
    Head p=L->next;
    while(p!=L)
    {
        printf("%d  ",p->element);
        p=p->next;
    }
    printf("\n");
}
//≤‚ ‘
int main(void)
{
   Head L1=createList();

   int b;
    for(int i=0;i<10;i++)
    {
        Element it;
        it=i;
        insertByI(it,i+1,L1);
    }
    printf("the L1 is: ");
   printList(L1);
   printf("enter a numer you want to delete: ");
   int a;
   scanf("%d",&a);
   while(L1->element!=1)
   {
       deleteByI(a,L1);
   }

    printList(L1);

    return 0;
}
