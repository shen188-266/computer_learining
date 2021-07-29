#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int num;
    int i;
    char (*pa)[20];
    printf("enter how many words.\n");
    scanf("%d",&num);
    pa = (char (*)[20])malloc(num*20*sizeof(char));
    printf("enter your words.\n");
    while (i<num)
    {
        scanf("%s",pa[i++]);
    }
    for(i=0;i<num;i++)
    {
        puts(pa[i]);
    }
    free(pa);
    return 0;
 }
