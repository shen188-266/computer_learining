#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct treeNode
{
    int height;
    Element element;
    struct treeNode* left;
    struct treeNode* right;
}*TreeNode;
typedef TreeNode AVLTree;
void makeEmpty(AVLTree T)
{
    if(T!=NULL)
    {
        makeEmpty(T->left);
        makeEmpty(T->right);
        free(T);
    }
}
TreeNode findMin(AVLTree T)
{
    if(T==NULL)
        return NULL;
    while(T->left!=NULL)
        T=T->left;
    return T;
}
TreeNode findMax(AVLTree T)
{
    if(T==NULL)
        return NULL;
    while(T->right!=NULL)
        T=T->right;
    return T;
}
int Height(TreeNode node)
{
    if(node==NULL)
        return -1;
    return node->height;
}
int max2(int a,int b)
{
    return (a>b)?a:b;
}
TreeNode singleRotateWithLeft(TreeNode K)
{

    TreeNode K1=K->left;
    K->left=K1->right;
    K1->right=K;
    K->height=max2(Height(K->right),Height(K->left))+1;
    K1->height=max2(Height(K->left),K->height)+1;
    return K1;
}
TreeNode singleRotateWithRight(TreeNode K)
{

    TreeNode K1=K->right;
    K->right=K1->left;
    K1->left=K;
    K->height=max2(Height(K->right),Height(K->left))+1;
    K1->height=max2(Height(K->right),K->height)+1;
    return K1;
}
TreeNode doubleRotateWithLeft(TreeNode K1)
{

   TreeNode K2=K1->left;
   TreeNode K3=K2->right;
   K1->left=K3->right;
   K2->right=K3->left;
   K3->left=K2;
   K3->right=K1;
   K1->height=max2(Height(K1->left),Height(K1->right))+1;
   K2->height=max2(Height(K2->left),Height(K2->right))+1;
   K3->height=max2(K1->height,K2->height)+1;
   return K3;
}
TreeNode doubleRotateWithRight(TreeNode K1)
{

   TreeNode K2=K1->right;
   TreeNode K3=K2->left;
   K1->right=K3->left;
   K2->left=K3->right;
   K3->right=K2;
   K3->left=K1;
   K1->height=max2(Height(K1->left),Height(K1->right))+1;
   K2->height=max2(Height(K2->left),Height(K2->right))+1;
   K3->height=max2(K1->height,K2->height)+1;
   return K3;
}
TreeNode insertNode(AVLTree T,Element ele)
{
    if(T==NULL)
    {
        TreeNode nwe=(TreeNode)malloc(sizeof(struct treeNode));
        if(nwe==NULL)
            exit(100);
        nwe->height=0;
        nwe->element=ele;
        nwe->left=nwe->right=NULL;

         return nwe;
    }
    else if(ele<T->element)
    {
        T->left=insertNode(T->left,ele);
        if(Height(T->left)-Height(T->right) == 2)
        {
            if(ele<T->element)
                T=singleRotateWithLeft(T);
            else
                T=doubleRotateWithLeft(T);
        }
    }
    else if(ele>T->element)
    {
        T->right=insertNode(T->right,ele);
        if(Height(T->right)-Height(T->left) == 2)
        {
            if(ele<T->element)
                T=doubleRotateWithRight(T);
            else
                T=singleRotateWithRight(T);
        }
    }
    else
        exit(1);

    T->height=max2(Height(T->left),Height(T->right))+1;
    return T;
}
TreeNode deleteMin(AVLTree T)
{
    if(T==NULL)
        exit(2);
    else if(T->left==NULL)
    {
        TreeNode temp=T;
        T=T->right;
        free(temp);
        return T;
    }
    else
    {
        T->left=deleteMin(T->left);
        if(Height(T->right)-Height(T->left) == 2)
        {
            if(Height(T->right->right)>=Height(T->right->left))
                T=singleRotateWithRight(T);
            else
                T=doubleRotateWithRight(T);
        }
    }
    T->height=max2(Height(T->left),Height(T->right))+1;
    return T;
}
TreeNode deleteNode(AVLTree T,Element ele)
{
    static TreeNode temp;
    if(T==NULL)
    {
        exit(0);
    }
    else if(T->element==ele)
    {
        if(T->left && T->right)
        {
            T->element=findMin(T->left)->element;
            T->left=deleteMin(T->left);
        }
        else
        if(T->left)
            {
                TreeNode tempD=T;
                if(temp->left==T)
                    temp->left=T->left;
                else
                    temp->right=T->left;
                free(tempD);
            }
        else
        {
            free(T);
            return NULL;
        }
    }
    else if(ele<T->element)
    {
        temp=T;
        T->left=deleteNode(T->left,ele);
        if(Height(T->right)-Height(T->left) == 2)
        {
            if(Height(T->right->right)>=Height(T->right->left))
                T=singleRotateWithRight(T);
            else
                T=doubleRotateWithRight(T);
        }
    }
    else if(ele>T->element)
    {
        temp=T;
        T->right=deleteNode(T->right,ele);
        if(Height(T->left)-Height(T->right) == 2)
        {
            if(Height(T->left->left)>=Height(T->left->right))
                T=singleRotateWithLeft(T);
            else
                T=doubleRotateWithLeft(T);
        }
    }

    T->height=max2(Height(T->left),Height(T->right))+1;
    return T;
}
int qianxuP(AVLTree T)
{
    if(T!=NULL)
    {
        printf("%d  ",T->element);
        qianxuP(T->left);
        qianxuP(T->right);
        return 1;
    }
    return 0;
}

int main(void)
{
    AVLTree Tree=NULL;

    Tree=insertNode(Tree,7);
    Tree=insertNode(Tree,8);
    Tree=insertNode(Tree,4);
    Tree=insertNode(Tree,3);
    Tree=insertNode(Tree,6);
    Tree=insertNode(Tree,5);
    Tree=insertNode(Tree,9);

    qianxuP(Tree);
    Tree=deleteNode(Tree,9);

    printf("\n");
    qianxuP(Tree);
    return 0;
}
