//cʵ�־�̬�����α꣩
/*
cur���α꣬���һ��Ԫ�ص�cur�ǵ�һ��ռ�õĽڵ���±꣬
�������Ϊ�գ����һ��Ԫ�ص�curΪ0
��һ���ڵ��curΪ��һ���սڵ���±�
�����һ���ù���Ԫ�ص�cur�����һ���յ�Ԫ�ص�cur����Ϊ0����������򷽱�malloclist����
*/
#include <stdio.h>
#define MAXSIZE 1000 //��󴢴�λ���ɸģ�
#include <stdlib.h>
#include <time.h>


typedef struct element element;
typedef struct note note;
//������
struct element {
    int a;
};
//�ڵ�
struct note {
    element ele;
    int cur;}component[MAXSIZE];

//��ʼ�����˴����������
void initiallist(note * component,int n);
//������������
void reservelist(note * component);
//�����ڴ�
int malloclist(note * component);
//�ͷ��ڴ�
void freelist(note * component,int i);
//���뵽nλ
int addlist(note * component,int n,element ale);
//ɾ��Ԫ��
int deletelist(note * component,element ale);
//����Ԫ��
int findlist(note * component,element ale);
//�޸�Ԫ��
int modifylist(note * component,element oldale,element ale);
//ȫ��ӡ
void showlist(note *component);
//����������
int listlength(note * component);
//��ӡ�ṹ
void showstc(element ale);



int main()
{
    initiallist(component,100);
    printf("listlength1��%d\n",listlength(component));
    showlist(component);
    element ats;
    ats.a=3;
    deletelist(component,ats);
    printf("deletelist��3����and listlength2��%d\n",listlength(component));
    addlist(component,15,ats);
    printf("addlist(15),and listlength3��%d\n",listlength(component));
    addlist(component,16,ats);
    printf("addlist(16),and listlength4��%d\n",listlength(component));
    addlist(component,120,ats);
    printf("addlist(120) ,and listlength5��%d\n",listlength(component));
    showlist(component);
    deletelist(component,ats);
    printf("re-deletelist��3����and listlength6��%d\n",listlength(component));
    showlist(component);
    return 0;
}


//��ʼ�����˴����������
void initiallist(note * component,int n)
{
    reservelist(component);
    component[MAXSIZE-1].cur=malloclist(component);//���һ��Ԫ�ص�cur��ʼ��Ϊ��һ��ռ��Ԫ���±�
    int j=component[MAXSIZE-1].cur;//jΪ��һ��ռ�õ�Ԫ��
    srand((unsigned int)time(0));
    component[j].ele.a=rand()%MAXSIZE;//���
    for(int i=1;i<n;i++)
    {
        component[j].cur=malloclist(component);
        j=component[j].cur;
        component[j].ele.a=rand()%MAXSIZE;//���
    }
    component[j].cur=0;//��־ռ��Ԫ�صĽ���
}
//������������
void reservelist(note * component)
{
    for(int i=0;i<MAXSIZE;i++)
    {
        component[i].cur=i+1;
    }
    component[MAXSIZE-1].cur=0;
}
//�����ڴ�
int malloclist(note * component)
{
    int j=component[0].cur;//jΪ��һ���յ�Ԫ���±�
    if(j)
    {
        component[0].cur=component[j].cur;
    }
    return j;
}
//�ͷ��±�Ϊi���ڴ�
void freelist(note * component,int i)
{
    component[i].cur=component[0].cur;
    component[0].cur=i;
}
//���뵽nλ
int addlist(note * component,int n,element ale)
{
    if(n<=0||n>listlength(component)+1)
        return -1;
    int m=component[MAXSIZE-1].cur;//mΪ��һ��Ԫ�ص��±�
    int fi=malloclist(component);
    if(fi)
    {
    //�ҵ�n-1��Ԫ�أ������±�Ϊm����curΪֵΪ��n��Ԫ�ص��±�
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
//ɾ��Ԫ��(��һ��ale��
int deletelist(note * component,element ale)
{
    int i=findlist(component,ale);
    if(i==-1)
        return -1;
    int qi;
    int m=component[MAXSIZE-1].cur;
    //��ǰһ��Ԫ�أ������±�Ϊm����curΪֵΪale���±�
    while (component[m].cur!=i)
        m=component[m].cur;
    qi=component[m].cur;
    component[m].cur=component[qi].cur;
    freelist(component,qi);
}
//����Ԫ��
int findlist(note * component,element ale)
{
    int i=component[MAXSIZE-1].cur;   //iΪ��һ��ռ�õ�Ԫ���±�
    while(i)
    {
        if(component[i].ele.a==ale.a)
            return i;
        i=component[i].cur;
    }
    printf("can't find\n");
    return -1;
}
//�޸�Ԫ��
int modifylist(note * component,element oldale,element ale)
{
    int i=findlist(component,oldale);
    if(i==-1)
        return -1;
    component[i].ele=ale;
    return 1;
}
//�����ӡ
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
//����������
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
//��ӡ�ṹ
void showstc(element ale)
{
    printf("%d ",ale.a);
}
