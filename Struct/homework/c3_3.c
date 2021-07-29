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
void printAsSecond(Head L1,Head L2)
{
    int i;
    Head p=L2->next;
    for(i=L2->next->item.a;p->next!=NULL;i=p->item.a)
    {
        printf("%d  ",getItem(i,L1)->item.a);
        p=p->next;
    }
    printf("\n");
}
int changeElement(Head L,int i,int j)
{
    if(i>j)
    {
        int temp=i;
        i=j;
        j=temp;
    }
    else if(i==j)
        return 1;

    if(i<=0)
        exit(2);
    if(i==j-1)
    {
        Head FristEPre=getItem(i-1,L);
        Head FristEle=FristEPre->next;
        FristEPre->next=FristEle->next;
        FristEle->next=FristEle->next->next;
        FristEPre->next->next=FristEle;
    }
    else   // if (i<j-1)
    {
    Head FirstEPre=getItem(i-1,L);
    Head SecondEPre=getItem(j-1,L);
    if(SecondEPre==NULL)
        exit(3);
    if(SecondEPre->next==NULL)
        exit(4);

    Head p=FirstEPre->next;
    Head f=FirstEPre->next->next;
    Head q=SecondEPre->next->next;

    FirstEPre->next->next=q;
    FirstEPre->next=SecondEPre->next;
    SecondEPre->next->next=f;
    SecondEPre->next=p;
    return 1;}


}




//����

    int main(void)
{
   Head L1=createList();

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
     changeElement(L1,3,6);
     printList(L1);
    return 0;
}


