#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct searchTreeNode
{
    Element element;
    struct searchTreeNode* left;
    struct searchTreeNode* right;
}*SearchTreeNode;
typedef SearchTreeNode SearchTree;

int makeEmpty(SearchTree T)
{
    if(T==NULL)
        return 0;//什么都不干
    else
    {
        makeEmpty(T->left);
        makeEmpty(T->right);
        free(T);
        return 1;
    }
}
SearchTreeNode findElement(SearchTree T,Element ele)
{
    if(T==NULL)
        return NULL;
    else if(ele<T->element)
        return findElement(T->left,ele);
    else if(ele>T->element)
        return findElement(T->right,ele);
    else return T;
}
SearchTreeNode findMax(SearchTree T)
{
    if(T==NULL)
        return NULL;
    while(T->right!=NULL)
        T=T->right;
    return T;
}
SearchTreeNode findMin(SearchTree T)
{
    if(T==NULL)
        return NULL;
    while(T->left!=NULL)
        T=T->left;
    return T;
}
SearchTreeNode insertNode(SearchTree T, Element ele)
{
    SearchTreeNode newN=(SearchTreeNode)malloc(sizeof(struct searchTreeNode));
    newN->element=ele;
    newN->left=newN->right=NULL;

    if(T==NULL)
        return newN;

    SearchTreeNode temp;
    while(T!=NULL)
    {
        temp=T;
        if(ele<T->element)
            T=T->left;
        else if(ele>T->element)
            T=T->right;
        else
            return NULL;
    }

    if(ele<temp->element)
        temp->left=newN;
    else
        temp->right=newN;

    return newN;

}
Element deleteMin(SearchTree T)
{
    SearchTreeNode temp;

    while(T->left!=NULL)
    {
        temp=T;
        T=T->left;
    }
    SearchTreeNode tempD=T;
    if(T==temp->left)
        temp->left=T->right;
    else
        temp->right=T->right;
    Element ele=tempD->element;
    free(tempD);
    return ele;
}
int deleteNode(SearchTree T,Element ele)
{
    SearchTreeNode temp;
    while(T!=NULL)
    {
        if(ele<T->element)
        {
            temp=T;
            T=T->left;
        }
        else if(ele>T->element)
        {
            temp=T;
            T=T->right;
        }
        else break;
    }

    if(T==NULL)
        return 0;

    if(T->left!=NULL && T->right!=NULL)
         T->element=deleteMin(T->right);
     else if(T->left!=NULL)
     {
         SearchTreeNode tempD=T;
         if(T==temp->left)
        temp->left=T->left;
        else
        temp->right=T->left;
        free(tempD);
     }
    else
    {
        SearchTreeNode tempD=T;
        if(T==temp->left)
        temp->left=T->right;
        else
        temp->right=T->right;
        free(tempD);
    }
    return 1;
}
void zhongxuP(SearchTree T)
{
    if(T!=NULL)
    {
        zhongxuP(T->left);
        printf("%d  ",T->element);
        zhongxuP(T->right);
    }
}
void qianxuP(SearchTree T)
{
    if(T!=NULL)
    {
        printf("%d  ",T->element);
        zhongxuP(T->left);
        zhongxuP(T->right);
    }
}
void houxuP(SearchTree T)
{
    if(T!=NULL)
    {
        houxuP(T->left);
        houxuP(T->right);
        printf("%d  ",T->element);
    }
}
int main()
{
    SearchTree Tree=NULL;
    Tree=insertNode(Tree,3);
    insertNode(Tree,1);
    insertNode(Tree,4);insertNode(Tree,6);insertNode(Tree,9);insertNode(Tree,2);insertNode(Tree,5);insertNode(Tree,7);
   houxuP(Tree);
   printf("\n");
   deleteNode(Tree,6);
   houxuP(Tree);
   printf("\n");
   printf("the max is: %d",findMax(Tree)->element);
    return 0;
}
