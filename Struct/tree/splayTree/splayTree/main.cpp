#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct splayTree
{
    Element element;
    struct splayTree* left;
    struct splayTree* right;
    struct splayTree* parent;
}*SplayTree;
typedef SplayTree SplayTreeNode;

SplayTreeNode singleRotateWithLeft(SplayTreeNode K1)
{
    SplayTreeNode p=K1->parent;
    SplayTreeNode K2=K1->left;
    SplayTreeNode q=K2->right;
    K1->left=q;
    K2->right=K1;
    K1->parent=K2;
    K2->parent=p;

    if(p)
    {
        if(p->left==K1)
        {
            p->left=K2;
        }
        else
        {
            p->right=K2;
        }
    }
    return K2;
}
SplayTreeNode singleRotateWithRight(SplayTreeNode K1)
{
    SplayTreeNode p=K1->parent;
    SplayTreeNode K2=K1->right;
    SplayTreeNode q=K2->left;
    K1->right=q;
    K2->left=K1;
    K1->parent=K2;
    K2->parent=p;

    if(p)
    {
        if(p->left==K1)
        {
            p->left=K2;
        }
        else
        {
            p->right=K2;
        }
    }
    return K2;
}
SplayTreeNode doubleRotateWithLeft(SplayTreeNode K1)
{
    K1->left=singleRotateWithRight(K1->left);
    return singleRotateWithLeft(K1);
}
SplayTreeNode doubleRotateWithRight(SplayTreeNode K1)
{
    K1->right=singleRotateWithLeft(K1->right);
    return singleRotateWithRight(K1);
}
SplayTree splay(SplayTreeNode T)
{
    SplayTreeNode p,gp;
    do
    {
        p=T->parent;
        if(p==NULL)
            break;
        gp=p->parent;
        if(p->left==T)
        {
            if(gp==NULL)
                T=singleRotateWithLeft(p);
            else
            {
                if(gp->left==p)
                {
                    singleRotateWithLeft(gp);
                    T=singleRotateWithLeft(p);
                }
                else //if(gp->right==p)
                {
                    T=doubleRotateWithRight(gp);
                }
            }
        }
        else //if(p->right==T)
        {
            if(gp==NULL)
                T=singleRotateWithRight(p);
            else
            {
                if(gp->right==p)
                {
                    singleRotateWithRight(gp);
                    T=singleRotateWithRight(p);
                }
                else //if(gp->right==p)
                {
                    T=doubleRotateWithLeft(gp);
                }
            }
        }
    }while(T->parent!=NULL);
    return T;
}
SplayTree findElement(SplayTree T,Element ele)
{
    if(T==NULL)
    {
        return NULL;
    }
    else if(ele<T->element)
    {
        return findElement(T->left,ele);
    }
    else if(ele>T->element)
    {
        return findElement(T->right,ele);
    }
    else //if(ele==T->element)
    {
        return splay(T);
    }
}
SplayTree insertElement_z(SplayTree T,Element ele)
{
    if(T==NULL)
    {
        SplayTreeNode nwe=(SplayTreeNode)malloc(sizeof(struct splayTree));
        if(nwe==NULL)
            exit(1);
        nwe->parent=NULL;
        nwe->left=nwe->right=NULL;
        nwe->element=ele;
        return nwe;
    }
    else if(ele<T->element)
    {
        T->left=insertElement_z(T->left,ele);
        T->left->parent=T;
    }
    else if(ele>T->element)
    {
        T->right=insertElement_z(T->right,ele);
        T->right->parent=T;
    }
    else //if(ele==T->element)
    {
        fprintf(stderr,"repetition");
        exit(2);
    }
    return T;
}
SplayTree insertElement(SplayTree T,Element ele)
{
    T=insertElement_z(T,ele);
    T=findElement(T,ele);
    return T;
}
SplayTreeNode findMin(SplayTree T)
{
    if(T==NULL)
        return NULL;
    while(T->left!=NULL)
    {
        T=T->left;
    }
    return splay(T);
}
SplayTreeNode findMax(SplayTree T)
{
    if(T==NULL)
        return NULL;
    while(T->right!=NULL)
    {
        T=T->right;
    }
    return splay(T);
}
SplayTree deleteElement(SplayTree T,Element ele)
{
    T=findElement(T,ele);
    if(T==NULL)
    {
        fprintf(stderr,"there is no element");
        return NULL;
    }
    if(T->left && T->right)
    {
        T->right=findMin(T->right);
        T->right->left=T->left;
        T->right->left->parent=T->right;
        T->right->parent=NULL;
        free(T);
        return T->right;
    }
    else
    if(T->left!=NULL)
    {
        T->left->parent=NULL;
        free(T);
        return T->left;
    }
    else if(T->right!=NULL)
    {
        T->right->parent=NULL;
        free(T);
        return T->right;
    }
    else
        return NULL;
}
void qianxu(SplayTree T)
{
    if(T!=NULL)
    {
        printf("%d  ",T->element);
        qianxu(T->left);
        qianxu(T->right);
    }
}
void houjiancha(SplayTree T)
{
    if(T!=NULL)
    {
        houjiancha(T->left);
        houjiancha(T->right);
        if(T->parent!=NULL)
        printf("%d  ",T->parent->element);
    }
}
int main(void)
{
    SplayTree Tree=NULL;
    for(int i=0;i<7;i++)
    {
        Tree=insertElement(Tree,i);
    }
    qianxu(Tree);
    printf("\n");
    Tree=findElement(Tree,0);
    qianxu(Tree);
    printf("\n");
    Tree=deleteElement(Tree,5);
    qianxu(Tree);
    return 0;
}
