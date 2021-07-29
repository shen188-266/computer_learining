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
//��e�嵽��n-1��Ԫ�غ���
bool listinsert(Head *L,int i,Item e)
{
    int j;
    Note *p,*s;
    p=L->next;
    j=1;//pָ���һ��Ԫ��
    //�ҵ�i-1��Ԫ��
    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    //����pָ���n-1��Ԫ��
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
    j=1;//pָ���һ��Ԫ��
    //�ҵ�i-1��Ԫ��
    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p)
    return 0;
    if(!p->next)
    return 0;
    s=p->next;//sָ���i��Ԫ��
    p->next=s->next;
    free(s);
    L->length--;
    return 1;
}
//��ʼ��n��Ԫ��
bool listcreathead(Head *L,int n)
{
    L->next=NULL;//��ʼ��������
    Note *p;
    int i=0;
    printf("%d ",i);
    do
    {
        p=(Note *)malloc(sizeof(Note));
        //ȷ�������ڴ�ɹ�
        if(p==NULL)
            return 0;
        i++;
        printf("%d ",i);
        p->next=L->next;
        p->items.a=i;//��ʼ��
        L->next=p;//pΪ��һ��Ԫ��
    }while(i<n);
    L->length=n;
    return 1;
}
//����ɾ��
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
//�����ӡ
void show(Head *L)
{
    Note *p=L->next;//pָ���һ��Ԫ��
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
//����
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
