/**��ͷ������ͨ����
����-1Ϊ�쳣��0Ϊʧ��*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
Head hequ(Head L1,Head L2)
{
    Head L3=createList();
    Item element;
    Head p=L1->next;
    while(p!=NULL)
    {
        element.a=p->item.a;
        if(getFItem(element,L2)!=NULL)
        {
            addHead(element,L3);
        }
        p=p->next;
    }
    return L3;
}
Head xiqu(Head L1,Head L2)
{
    Head L3=createList();
    Item element;
    Head p=L1->next;
    while(p!=NULL)
    {
        element.a=p->item.a;
        if(getFItem(element,L2)==NULL)
        {
            addHead(element,L3);
        }
        p=p->next;
    }
    p=L2->next;
    while(p!=NULL)
    {
        element.a=p->item.a;

            addHead(element,L3);

        p=p->next;
    }
    return L3;
}




//����
int main(void)
{
   Head L1=createList();
   Head L2=createList();
   int b;
    for(int i=10;i>0;i--)
    {
        b=i;
        Item it;
        it.a=b;
        addHead(it,L1);
    }
    printf("the L1 is: ");
   printList(L1);
   printf("the L2 is: ");
   for(int i=6;i>-6;i=i-2)
    {
        b=i;
        Item it;
        it.a=b;
        addHead(it,L2);
    }
    printList(L2);
    printf("the L1 And L2 is :");
    printList(xiqu(L1,L2));
    return 0;
}

