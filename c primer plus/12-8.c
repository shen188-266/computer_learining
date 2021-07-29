#include <stdio.h>
#include <stdlib.h>
int * make_array(int elem,int val);
void show_array(const int ar[],int n);
int main(void)
{
    int * pa;
    int size;
    int value;

    printf("enter the number of element: ");
    while (scanf("%d",&size)==1&& size>0)
        {
            printf("enter the initialization value: ");
            scanf("%d",&value);
            pa=make_array(size,value);
            if(pa)
            {
                show_array(pa,size);
                free(pa);
            }
            printf("enter the number of elements (<1 to quit):");
        }
        printf("done!\n");
        return 0;
    }
int * make_array(int elem,int val){
int * po;
po=(int *)malloc(elem*sizeof(int));
if(po)
{for(int i=0;i<elem;i++)
    po[i]=val;
return po;}
else
    return NULL;
}
void show_array(const int ar[],int n){
for (int i=0;i<n;i++)
    {
        printf("%-5d",ar[i]);
        if(i%8==7)
            putchar('\n');
    }
}
