#include "list.h"
#include <stdio.h>
#include <stdlib.h>

bool getelem(Head *L,int i,Item *e)
{
    Note *p=L->next;
    int j=1;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!p)
        return -1;
    *e=p->items;
    return p;
}
//把e插到第n-1个元素后面
bool listinsert(Head *L,int i,Item e)
{
    int j;
    Note *p,*s;
    p=L->next;
    j=1;//p指向第一个元素
    //找第i-1个元素
    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    //现在p指向第n-1个元素
    s=(Note *)malloc(sizeof(Note));
    if(s)
    {
    s->items=e;
    s->next=p->next;
    p->next=s;
    L->length++;
    }
    return (bool)s;
}
bool listdelete(Head *L,int i,Item *e)
{
    if(i<1||i>L->length)
        return 0;
    int j;
    Note * p,*s;
    p=L->next;
    j=1;//p指向第一个元素
    //找第i-1个元素
    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p)
    return 0;
    if(!p->next)
    return 0;
    s=p->next;//s指向第i个元素
    p->next=s->next;
    free(s);
    L->length--;
    return 1;
}
//初始化n个元素
bool listcreathead(Head *L,int n)
{
    L->next=NULL;//初始化空链表
    Note *p;
    int i=0;
    printf("%d ",i);
    do
    {
        p=(Note *)malloc(sizeof(Note));
        //确保分配内存成功
        if(p==NULL)
            return 0;
        i++;
        printf("%d ",i);
        p->next=L->next;
        p->items.a=i;//初始化
        L->next=p;//p为第一个元素
    }while(i<n);
    L->length=n;
    return 1;
}
//整表删除
bool clearlist(Head *L)
{
    Note *p=L->next,*s;
    s=(Note *)malloc(sizeof(Note));
    while(p)
    {
        s=p;
        p=p->next;
        free(s);
    }
    L->next=NULL;
    L->length=0;
    return 1;
}
//整表打印
void show(Head *L)
{
    Note *p=L->next;//p指向第一个元素
    int i=0;
    printf("there are %d note in total\n",L->length);
    while(p)
    {
        printf("%d ",p->items.a);
        if(i%5==4)
            putchar('\n');
        p=p->next;
    }
    if(i%5!=4)
        putchar('\n');
}
//长度
int listlength(Head *L)
{
    Note *p=L->next;
    int i=0;
    while(p)
    {
        i++;
        p=p->next;
    }
    printf("now lengh = %d\n",i);
    return i;
}
