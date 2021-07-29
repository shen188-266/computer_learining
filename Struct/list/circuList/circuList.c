/**ѭ������
��ͷ������ͨ����
����-1Ϊ�쳣��0Ϊʧ��
LΪ��*/

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
int isLast(element e,Head L);//�Ƿ�Ϊ���һ��Ԫ��
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
    a->next=a;
    return a;
}
int isEmpty(Head L)//�Ƿ�Ϊ�ձ�
{
    if(L->next==L)
    return 1;
    else return 0;
}
int isLast(element e,Head L)//�Ƿ�Ϊ���һ��Ԫ��
{
    if(e->next==L)
    return 1;
    else return 0;
}
element getItem(int i,Head L)//�õ���i������λ��
{
    if(i>0)
    {
      int j=0;
      Node* p;
      p=L->next;
      while(p!=L && j<i-1)
      {
          p=p->next;
          j++;
      }
      if(p!=L)
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
    while(p!=L && p->item.a!=items.a)
    {
        p=p->next;
        j++;
    }
    if(p!=L)
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
    while(p->next!=L && p->next->item.a!=items.a)
    {
        p=p->next;
        j++;
    }
    if(p->next!=L)
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
    while(p->next!=L)
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






//����
int main(void)
{
   Head L=createList();
   if(isEmpty(L)==1)
    printf("it is empty\n");
    for(int i=0;i<10;i++)
    {
        int b=i;

        Item it;
        it.a=b;
        addHead(it,L);
    }
   printList(L);
   int d;
   Item it2;

   it2.a=5;
   if((d=findItem(it2,L))!=0 && d!=-1)
   {
       deleteByI(5,L);
       printList(L);
   }
   element pit;
   pit=getItem(9,L);
   printf("the 9 is: %d,and the last is %d",pit->item.a,isLast(pit,L));

    return 0;
}
