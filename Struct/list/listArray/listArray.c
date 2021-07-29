


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
//建表，失败的话返回NULL
arrayList* creatList()
{
    arrayList* p=(arrayList*)malloc(sizeof(arrayList));
    if(p!=NULL)
    p->length=0;
    return p;
}
//是否为空表
int isEmpty(arrayList* L)
{
    return L->length==0;
}
//是否满了
int isFull(arrayList* L)
{
    return L->length==MAXSIZE;
}
//直接在末尾添加元素
int addList(Item items,arrayList* L)
{
    if(!isFull(L)){
    L->data[L->length].a=items.a;
    L->length++;
    return 1;
    }
    return 0;
}
//在第i位添加一个元素
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
//返回第i个元素的值
int getItem(int i,arrayList* L)
{
    return L->data[i-1].a;
}
//返回数据位items的元素下标
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
//删除第i个元素
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
//打印
void printList(arrayList* L)
{
    for(int i=0;i<L->length;i++)
    {
        printf("%d  ",L->data[i].a);
    }
}


//测试
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
