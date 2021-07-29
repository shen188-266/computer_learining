#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    Head *ap=(Head *)malloc(sizeof(Note));
    Item temp,temp1;
    temp1.a=20;
    if(!listcreathead(ap,10))
    {
        fprintf(stderr,"can't creat");
        exit(1);
    }
    listlength(ap);
    show(ap);
    getelem(ap,5,&temp);
    printf("temp.a:%d\n",temp.a);
    printf("temp1.a:%d\n",temp1.a);
    listinsert(ap,5,temp1);
    show(ap);
    listlength(ap);
    listdelete(ap,2,&temp1);
    printf("after listdelete(2)\n");
    listlength(ap);
    show(ap);
    printf("now temp1.a:%d\n",temp1.a);


    return 0;
}
