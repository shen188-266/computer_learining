//链表栈的c语言实现
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdbool.h>

//元素
typedef struct element {
    int a;}Item;
//节点
typedef struct note {
    Item items;
    struct note *next;}Note;
//头节点
typedef struct {
    Note * top;
    int counts;}stacklink;


//创建空表
void createstack(stacklink * S);
bool initialstack(stacklink * S,int n);
bool clearstack(stacklink * S);
Item gettop(stacklink * S);
void pop(stacklink * S,Item *e);
bool push(stacklink * S,Item *e);
bool stack_is_empty(stacklink * S);
int stacklength(stacklink * S);
void showstack(stacklink * S);

#endif // STACK_H_INCLUDED
