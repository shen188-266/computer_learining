#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    stacklink *S=malloc(sizeof(stacklink));
    initialstack(S,10);
    showstack(S);

    Item temp;
    temp=gettop(S);
    printf("%d\n",temp.a);
    pop(S,&temp);
    printf("%d\n",temp.a);
    showstack(S);
    pop(S,&temp);
    printf("%d\n",temp.a);
    showstack(S);
    push(S,&temp);
    showstack(S);
    clearstack(S);
    printf("%s\n",stack_is_empty(S)?"the stack is empty":"the stack isn't empty");

    return 0;
}
