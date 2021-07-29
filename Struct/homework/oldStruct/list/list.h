//有头结点

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>


//数据
typedef struct element {
    int a;}Item;
//节点
typedef struct note{
    Item items;
    struct note *next;}Note;
//头结点
typedef struct {
    int length;
    Note * next;}Head;



//把一个数据导出到e
bool getelem(Head *L,int i,Item *e);
//插入
bool listinsert(Head *L,int i,Item e);
//删除并把数据导出到e
bool listdelete(Head *L,int i,Item *e);
//初始化n个元素
bool listcreathead(Head *L,int n);
//整表删除
bool clearlist(Head *L);
//整表打印
void show(Head *L);
//长度
int listlength(Head *L);

#endif // LIST_H_INCLUDED
