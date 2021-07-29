//����ջ��c����ʵ��
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdbool.h>

//Ԫ��
typedef struct element {
    int a;}Item;
//�ڵ�
typedef struct note {
    Item items;
    struct note *next;}Note;
//ͷ�ڵ�
typedef struct {
    Note * top;
    int counts;}stacklink;


//�����ձ�
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
