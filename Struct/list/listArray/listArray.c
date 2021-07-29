


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 1000

typedef struct
{
    int a;
}Item;
typedef struct
{
    Item data[MAXSIZE];
    int length;
}arrayList;
//����ʧ�ܵĻ�����NULL
arrayList* creatList()
{
    arrayList* p=(arrayList*)malloc(sizeof(arrayList));
    if(p!=NULL)
    p->length=0;
    return p;
}
//�Ƿ�Ϊ�ձ�
int isEmpty(arrayList* L)
{
    return L->length==0;
}
//�Ƿ�����
int isFull(arrayList* L)
{
    return L->length==MAXSIZE;
}
//ֱ����ĩβ���Ԫ��
int addList(Item items,arrayList* L)
{
    if(!isFull(L)){
    L->data[L->length].a=items.a;
    L->length++;
    return 1;
    }
    return 0;
}
//�ڵ�iλ���һ��Ԫ��
int insertList(Item items,int i,arrayList* L)
{
    if(!isFull(L))
    {
        int j=L->length-1;
        while(j>=i-1)
        {
            L->data[j+1].a=L->data[j].a;
            j--;
        }
        L->data[i-1].a=items.a;
        return 1;
    }
    return 0;
}
//���ص�i��Ԫ�ص�ֵ
int getItem(int i,arrayList* L)
{
    return L->data[i-1].a;
}
//��������λitems��Ԫ���±�
int findItem(Item items,arrayList* L)
{
    int j=0;
    while(j<L->length && L->data[j].a!=items.a)
    {
        j++;
    }
    if(j<<L->length)
        return j;
    else return 0;
}
//ɾ����i��Ԫ��
int deleteItem(int i,arrayList* L)
{
    if(i>0 && i<L->length)
    {
        int j=i-1;
        while(j<L->length-1)
        {
            L->data[j].a=L->data[j+1].a;
            j++;
        }
        L->length--;
        return 1;
    }
    return 0;
}
//��ӡ
void printList(arrayList* L)
{
    for(int i=0;i<L->length;i++)
    {
        printf("%d  ",L->data[i].a);
    }
}


//����
int main(void)
{
    arrayList* L=creatList();
    printf("the list is empty(%d)\n",isEmpty(L));
    for(int i=0;i<10;i++)
    {
        Item it;
        it.a=i;
        addList(it,L);
    }
    printList(L);
    Item it1;
        it1.a=8;
    printf("the 8's xiabiao is: %d\n",findItem(it1,L));
    deleteItem(4,L);
     printList(L);
     printf("the 8's xiabiao is: %d\n",findItem(it1,L));
    return 0;
}
