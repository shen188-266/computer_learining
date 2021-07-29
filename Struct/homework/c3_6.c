/**��ͷ������ͨ����
����-1Ϊ�쳣��0Ϊʧ��*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 10000
typedef struct {
    int a;
    }Item;
typedef struct jiedian{
    Item item;
    struct jiedian* next;
    }Node;
typedef Node* Head;
typedef Node* element;

Head createList();//��������
int isEmpty(Head L);//�Ƿ�Ϊ�ձ�
int isLast(element e);//�Ƿ�Ϊ���һ��Ԫ��
element getItem(int i,Head L);//�õ���i������λ��
int findItem(Item items,Head L);//��������Ϊitems�Ľ���±꣨�ڼ�����
element getFItem(Item items,Head L);//�ҵ�����Ϊitems�Ľڵ��ǰһ����㣬����
int insertItem(Item items,int i,Head L);//�ڵ�i��λ�ò���һ�����
int deleteItem(Item items,Head L);//ɾ������Ϊitems�Ľڵ㣬�����Ƿ�ɹ�
int deleteByI(int i,Head L);//ɾ����i���ڵ㣬�����Ƿ�ɹ�
int addHead(Item items,Head L);//ͷ������һ��Ԫ��
int printList(Head L);//�����ӡ


Head createList()//��������
{
    Head a=(Head)malloc(sizeof(Node));
    a->next=NULL;
    return a;
}
int isEmpty(Head L)//�Ƿ�Ϊ�ձ�
{
    if(L->next==NULL)
    return 1;
    else return 0;
}
int isLast(element e)//�Ƿ�Ϊ���һ��Ԫ��
{
    if(e->next==NULL)
    return 1;
    else return 0;
}
element getItem(int i,Head L)//�õ���i������λ��
{
    if(i>0)
    {
      int j=0;
      Node* p;
      p=L;
      while(p!=NULL && j<i)
      {
          p=p->next;
          j++;
      }
      if(p!=NULL)
      {
          return p;
      }
    }
    else if(i==0)
        return L;
    else
    return NULL;
}
int findItem(Item items,Head L)//��������Ϊitems�Ľ���±꣨�ڼ�����
{
    int j=1;
    Node* p;
    if(L==NULL)
        return -1;
    p=L->next;
    while(p!=NULL && p->item.a!=items.a)
    {
        p=p->next;
        j++;
    }
    if(p!=NULL)
    {
        return j;
    }
    return 0;
}
element getFItem(Item items,Head L)//�ҵ�����Ϊitems�Ľڵ��ǰһ����㣬����
{
    int j=1;
    Node* p;
    if(L==NULL)
        return NULL;
    p=L;
    while(p->next!=NULL && p->next->item.a!=items.a)
    {
        p=p->next;
        j++;
    }
    if(p->next!=NULL)
    {

        return p;
    }
    else
    return NULL;
}
int insertItem(Item items,int i,Head L)//�ڵ�i��λ�ò���һ�����
{
    Node* f;
    if(f=getItem(i-1,L))
    {
        Node* newNode=(Node*)malloc(sizeof(Node));
        if(newNode)
        {
            newNode->item.a=items.a;
            newNode->next=f->next;
            f->next=newNode;
            return 1;
        }
    }
    return 0;
}
int deleteItem(Item items,Head L)//ɾ������Ϊitems�Ľڵ㣬�����Ƿ�ɹ�
{
    Node *f,*p;
    if(L==NULL)
        return -1;
    if((f=getFItem(items,L))!=NULL)
    {
       p=f->next;
       f->next=p->next;
       free(p);
       return 1;
    }
    return 0;
}
int deleteByI(int i,Head L)//ɾ����i���ڵ㣬�����Ƿ�ɹ�
{
    Node *f,*p;
    if(L==NULL)
        return -1;
    if(f=getItem(i-1,L))
    {
        p=f->next;
       f->next=p->next;
       free(p);
       return 1;
    }
    return 0;
}
int addHead(Item items,Head L)//ͷ������һ��Ԫ��
{
    if(L==NULL)
        return -1;
    Node* a=(Node*)malloc(sizeof(Node));
    if(a!=NULL)
    {
        a->next=L->next;
        a->item.a=items.a;
        L->next=a;
        return 1;
    }
    else
    return 0;
}
int printList(Head L)//�����ӡ
{
    if(L==NULL)
        return -1;
    Node *p =L;
    int j=0;
    while(p->next!=NULL)
    {
        if(j!=0 && j%10==0)
            printf("\n");
        printf("%d  ",p->next->item.a);
        p=p->next;
        j++;
    }
            printf("\n");
    return 1;
}
Head addTwoList(Head L1,Head L2)
{
    Head L3=createList();
    Head p=L1->next;
    Head q=L2->next;
    int i=1;
    Item element;
    while(q!=NULL || p!=NULL)
    {
        if(q!=NULL && p!=NULL)
         {element.a=p->item.a+q->item.a;
         q=q->next;
         p=p->next;}
        else if(q!=NULL)
        {
           element.a=q->item.a;
           q=q->next;
        }
        else if(p!=NULL)
        {
             element.a=p->item.a;
             p=p->next;
        }
        insertItem(element,i,L3);
        i++;
    }
    return L3;
}
Head multiTwoList(Head L1,Head l2)
{

}
int findDiGui(Item items,Head L)
{
    static int i=1;
    Node *p=L->next;
    if(p==NULL)
        return -1;
    else if (p->item.a==items.a)
        return i;
    else
    {
        i++;
        findDiGui(items,p);
    }

}

//����3_6/7
/*
int main(void)
{
   Head L1=createList();
   Head L2=createList();
   int b;
    for(int i=0;i<10;i++)
    {
        b=i;
        Item it;
        it.a=b;
        insertItem(it,i+1,L1);
    }
    printf("the L1 is: ");
   printList(L1);
   printf("the L2 is: ");
   for(int i=15;i>0;i--)
    {
        b=i;
        Item it;
        it.a=b;
        addHead(it,L2);
    }
    printList(L2);
    printf("the L1 And L2 is :");
    printList(addTwoList(L1,L2));
    return 0;
}
*/

int main(void)
{
   Head L1=createList();
   int b;
   Item it;
    for(int i=0;i<MAXSIZE;i++)
    {
        b=i;
        it.a=b;
        insertItem(it,i+1,L1);
    }
    printf("the L1 is: ");
   printList(L1);
   it.a=MAXSIZE-1;
    //printf("the i is %d\n",findDiGui(it,L1));
    printf("the i is %d\n",findItem(it,L1));
    return 0;
}
