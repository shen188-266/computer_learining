//��ͷ���

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>


//����
typedef struct element {
    int a;}Item;
//�ڵ�
typedef struct note{
    Item items;
    struct note *next;}Note;
//ͷ���
typedef struct {
    int length;
    Note * next;}Head;



//��һ�����ݵ�����e
bool getelem(Head *L,int i,Item *e);
//����
bool listinsert(Head *L,int i,Item e);
//ɾ���������ݵ�����e
bool listdelete(Head *L,int i,Item *e);
//��ʼ��n��Ԫ��
bool listcreathead(Head *L,int n);
//����ɾ��
bool clearlist(Head *L);
//�����ӡ
void show(Head *L);
//����
int listlength(Head *L);

#endif // LIST_H_INCLUDED
