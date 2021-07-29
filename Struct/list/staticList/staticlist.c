//c实现静态链表（游标）
/*
cur是游标，最后一个元素的cur是第一个占用的节点的下标，
如果链表为空，最后一个元素的cur为0
第一个节点的cur为第一个空节点的下标
将最后一个用过的元素的cur和最后一个空的元素的cur都设为0，代表结束或方便malloclist函数
*/
#include <stdio.h>
#define MAXSIZE 1000 //最大储存位（可改）
#include <stdlib.h>
#include <time.h>


typedef struct element element;
typedef struct note note;
//数据域
struct element {
    int a;
};
//节点
struct note {
    element ele;
    int cur;}component[MAXSIZE];

//初始化（此处用随机数）
void initiallist(note * component,int n);
//创建备用链表
void reservelist(note * component);
//分配内存
int malloclist(note * component);
//释放内存
void freelist(note * component,int i);
//插入到n位
int addlist(note * component,int n,element ale);
//删除元素
int deletelist(note * component,element ale);
//查找元素
int findlist(note * component,element ale);
//修改元素
int modifylist(note * component,element oldale,element ale);
//全打印
void showlist(note *component);
//返回链表长度
int listlength(note * component);
//打印结构
void showstc(element ale);



int main()
{
    initiallist(component,100);
    printf("listlength1：%d\n",listlength(component));
    showlist(component);
    element ats;
    ats.a=3;
    deletelist(component,ats);
    printf("deletelist（3），and listlength2：%d\n",listlength(component));
    addlist(component,15,ats);
    printf("addlist(15),and listlength3：%d\n",listlength(component));
    addlist(component,16,ats);
    printf("addlist(16),and listlength4：%d\n",listlength(component));
    addlist(component,120,ats);
    printf("addlist(120) ,and listlength5：%d\n",listlength(component));
    showlist(component);
    deletelist(component,ats);
    printf("re-deletelist（3），and listlength6：%d\n",listlength(component));
    showlist(component);
    return 0;
}


//初始化（此处用随机数）
void initiallist(note * component,int n)
{
    reservelist(component);
    component[MAXSIZE-1].cur=malloclist(component);//最后一个元素的cur初始化为第一个占用元素下标
    int j=component[MAXSIZE-1].cur;//j为第一个占用的元素
    srand((unsigned int)time(0));
    component[j].ele.a=rand()%MAXSIZE;//随机
    for(int i=1;i<n;i++)
    {
        component[j].cur=malloclist(component);
        j=component[j].cur;
        component[j].ele.a=rand()%MAXSIZE;//随机
    }
    component[j].cur=0;//标志占有元素的结束
}
//创建备用链表
void reservelist(note * component)
{
    for(int i=0;i<MAXSIZE;i++)
    {
        component[i].cur=i+1;
    }
    component[MAXSIZE-1].cur=0;
}
//分配内存
int malloclist(note * component)
{
    int j=component[0].cur;//j为第一个空的元素下标
    if(j)
    {
        component[0].cur=component[j].cur;
    }
    return j;
}
//释放下标为i的内存
void freelist(note * component,int i)
{
    component[i].cur=component[0].cur;
    component[0].cur=i;
}
//插入到n位
int addlist(note * component,int n,element ale)
{
    if(n<=0||n>listlength(component)+1)
        return -1;
    int m=component[MAXSIZE-1].cur;//m为第一个元素的下标
    int fi=malloclist(component);
    if(fi)
    {
    //找第n-1个元素，它（下标为m）的cur为值为第n个元素的下标
    for(int i=1;i<n-1;i++)
    {
        m=component[m].cur;
    }

    component[fi].ele=ale;
    component[fi].cur=component[m].cur;
    component[m].cur=fi;
    }
    return fi;
}
//删除元素(第一个ale）
int deletelist(note * component,element ale)
{
    int i=findlist(component,ale);
    if(i==-1)
        return -1;
    int qi;
    int m=component[MAXSIZE-1].cur;
    //找前一个元素，它（下标为m）的cur为值为ale的下标
    while (component[m].cur!=i)
        m=component[m].cur;
    qi=component[m].cur;
    component[m].cur=component[qi].cur;
    freelist(component,qi);
}
//查找元素
int findlist(note * component,element ale)
{
    int i=component[MAXSIZE-1].cur;   //i为第一个占用的元素下标
    while(i)
    {
        if(component[i].ele.a==ale.a)
            return i;
        i=component[i].cur;
    }
    printf("can't find\n");
    return -1;
}
//修改元素
int modifylist(note * component,element oldale,element ale)
{
    int i=findlist(component,oldale);
    if(i==-1)
        return -1;
    component[i].ele=ale;
    return 1;
}
//整表打印
void showlist(note *component)
{
    int m=component[MAXSIZE-1].cur;
    int i=0;
    while(m)
    {
        showstc(component[m].ele);
        m=component[m].cur;
        if(i%5==4)
            putchar('\n');
        i++;
    }
    if(i%5!=4)
    putchar('\n');
}
//返回链表长度
int listlength(note * component)
{
    int m=component[MAXSIZE-1].cur;

    int i=0;
    while(m)
    {
        m=component[m].cur;
        i++;
    }

    return i;
}
//打印结构
void showstc(element ale)
{
    printf("%d ",ale.a);
}
