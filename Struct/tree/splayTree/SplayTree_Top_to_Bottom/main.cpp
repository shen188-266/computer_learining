#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct splayTree
{
    Element element;
    struct splayTree *left;
    struct splayTree *right;
}*SplayTreeNode;
typedef SplayTreeNode SplayTree;
SplayTreeNode findMin_z(SplayTree T)
{
    if(T==NULL)
    {
        fprintf(stderr,"there is no element.\n");
        return NULL;
    }
    while(T->left!=NULL)
    {
        T=T->left;
    }
    return T;
}
SplayTreeNode findMax_z(SplayTree T)
{
    if(T==NULL)
    {
        fprintf(stderr,"there is no element.\n");
        return NULL;
    }
    while(T->right!=NULL)
    {
        T=T->right;
    }
    return T;
}
SplayTreeNode singleRotateWithLeft(SplayTree K1)
{
    if(K1==NULL)
    {
        fprintf(stderr,"K1 is empty.\n");
        return NULL;
    }
    SplayTreeNode K2=K1->left;
    K1->left=K2->right;
    K2->right=K1;
    return K2;
}
SplayTreeNode singleRotateWithRight(SplayTree K1)
{
    if(K1==NULL)
    {
        fprintf(stderr,"K1 is empty.\n");
        return NULL;
    }
    SplayTreeNode K2=K1->right;
    K1->right=K2->left;
    K2->left=K1;
    return K2;
}
SplayTree rotateOnceWithLeft(SplayTreeNode TN,SplayTree RLTree)
{
    if(RLTree->right)
    findMin_z(RLTree->right)->left=TN;
    else
    RLTree->right=TN;
    SplayTreeNode MidTree=TN->left;
    TN->left=NULL;
    return MidTree;
}
SplayTree rotateOnceWithRight(SplayTreeNode TN,SplayTree RLTree)
{
    if(RLTree->left)
    findMax_z(RLTree->left)->right=TN;
    else
    RLTree->left=TN;
    SplayTreeNode MidTree=TN->right;
    TN->right=NULL;
    return MidTree;
}
SplayTree rotateTwiceWithLeft(SplayTreeNode TN,SplayTree RLTree)
{
    SplayTreeNode T=singleRotateWithLeft(TN);
    if(RLTree->right)
    findMin_z(RLTree->right)->left=T;
    else
    RLTree->right=T;
    SplayTreeNode MidTree=T->left;
    T->left=NULL;
    return MidTree;
}
SplayTree rotateTwiceWithRight(SplayTreeNode TN,SplayTree RLTree)
{
    SplayTreeNode T=singleRotateWithRight(TN);
    if(RLTree->left)
    findMax_z(RLTree->left)->right=T;
    else
    RLTree->left=T;
    SplayTreeNode MidTree=T->right;
    T->right=NULL;
    return MidTree;
}
SplayTree rotateDoubleWithLeft(SplayTreeNode TN,SplayTree RLTree)
{
    if(RLTree->right)
    findMin_z(RLTree->right)->left=TN;
    else
    RLTree->right=TN;
    SplayTree Tree=TN->left;
    TN->left=NULL;
    return rotateOnceWithRight(Tree,RLTree);
}
SplayTree rotateDoubleWithRight(SplayTreeNode TN,SplayTree RLTree)
{
    if(RLTree->left)
    findMax_z(RLTree->left)->right=TN;
    else
    RLTree->left=TN;
    SplayTree Tree=TN->right;
    TN->right=NULL;
    return rotateOnceWithLeft(Tree,RLTree);
}
SplayTree conbineTree(SplayTree RLTree,SplayTree MidTree)
{
    if(RLTree->element != MidTree->element)
    {
        SplayTree mLeftTree=MidTree->left;
        SplayTree mRightTree=MidTree->right;
        MidTree->left=RLTree->left;
        MidTree->right=RLTree->right;
        if(RLTree->left!=NULL)
            findMax_z(RLTree->left)->right=mLeftTree;
        else
            MidTree->left=mLeftTree;
        if(RLTree->right!=NULL)
            findMin_z(RLTree->right)->left=mRightTree;
        else
            MidTree->right=mRightTree;
    }
    else//if(RLTree->element == MidTree->element)
    {
        ;//什么都不做
    }
    return MidTree;
}
SplayTree insertElement(SplayTree T,Element ele)
{
    SplayTree nwe=(SplayTree)malloc(sizeof(struct splayTree));
    nwe->element=ele;
    nwe->left=nwe->right=NULL;

    if(T==NULL)
        return nwe;

    SplayTree nweTree=(SplayTree)malloc(sizeof(struct splayTree));
    nweTree->element=T->element;
    nweTree->left=nweTree->right=NULL;
    int j=0;
    while(ele!=T->element)
    {
        if(ele<T->element)
        {
            if(T->left==NULL)
            {
                j=1;//没找到
                if(nweTree->right)
                findMin_z(nweTree->right)->left=T;
                else
                nweTree->right=T;
                break;
            }
            else
            {
                if(ele < T->left->element)
                {
                    T=rotateTwiceWithLeft(T,nweTree);
                }
                else if(ele>T->left->element)
                {
                    T=rotateDoubleWithLeft(T,nweTree);
                }
                else
                    break;
            }
        }
        else if(ele > T->element)
        {
            if(T->right==NULL)
            {
                j=2;
                if(nweTree->left)
                findMax_z(nweTree->left)->right=T;
                else
                nweTree->left=T;
                break;
            }
            else
            {
                if(ele > T->right->element)
                    T=rotateTwiceWithRight(T,nweTree);
                else if(ele < T->right->element)
                    T=rotateDoubleWithRight(T,nweTree);
                else
                    break;
            }
        }
    }
    if(j==0)
    {
        fprintf(stderr,"insert repetively!\n");
        free(nwe);
        return conbineTree(nweTree,T);
    }
    else if(j==1)
        return conbineTree(nweTree,nwe);
    else//if(j==2)
        return conbineTree(nweTree,nwe);
}
SplayTree findElement(SplayTree T,Element ele)
{
    if(T==NULL)
    {
        fprintf(stderr,"There is no element to find.\n");
        return NULL;
    }
    SplayTree nweTree=NULL;
    nweTree=insertElement(nweTree,T->element);
    while(ele!=T->element)
    {
        if(ele<T->element)
        {
            if(T->left==NULL)
            {
                free(nweTree);
                return NULL;//没找到
            }
            else
            {
                if(ele < T->left->element)
                {
                    T=rotateTwiceWithLeft(T,nweTree);
                }
                else if(ele > T->left->element)
                {
                    T=rotateDoubleWithLeft(T,nweTree);
                }
                else
                {
                    T=rotateOnceWithLeft(T,nweTree);
                }
            }
        }
        else //if(ele>T->element)
        {
            if(T->right==NULL)
            {
                free(nweTree);
                return NULL;
            }
            else
            {
                if(ele > T->right->element)
                    T=rotateTwiceWithRight(T,nweTree);
                else if(ele < T->right->element)
                    T=rotateDoubleWithRight(T,nweTree);
                else
                    T=rotateOnceWithRight(T,nweTree);
            }
        }
    }

    return conbineTree(nweTree,T);
}
SplayTree findMax(SplayTree T)
{
    SplayTreeNode TREE=findMax_z(T);
    return findElement(T,TREE->element);
}
SplayTree findMin(SplayTree T)
{
    SplayTreeNode TREE=findMin_z(T);
    return findElement(T,TREE->element);
}
SplayTree deleteElement(SplayTree T,Element ele)
{
    T=findElement(T,ele);
    if(T==NULL)
    {
        fprintf(stderr,"not found the element to delete!");
        return NULL;
    }
    if(T->left && T->right)
    {
        T->right=findMin(T->right);
        T->right->left=T->left;
        SplayTree n=T->right;
        free(T);
        return n;
    }
    else if(T->left)
    {
        SplayTree n=T->left;
        free(T);
        return n;
    }
    else if(T->right)
    {
        SplayTree n=T->right;
        free(T);
        return n;
    }
    else
    {
        free(T);
        return NULL;
    }
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

int main(void)
{
    SplayTree Tree=NULL;
    for(int i=0;i<7;i++)
    Tree=insertElement(Tree,i);
    qianxu(Tree);
    printf("\n");
    Tree=findElement(Tree,0);
    qianxu(Tree);
    Tree=deleteElement(Tree,5);
    printf("\n");
    qianxu(Tree);
    return 0;
}
