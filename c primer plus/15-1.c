#include <stdio.h>
#include "alls.h"
int btoi(char *st);

int main(void)
{
    char *pbin="01001001";
    printf("%d",btoi(pbin));

return 0;
}
int btoi(char *st){
    int m=0;
while(*st)
    {
        m*=2;
        m+=*st++ - '0';
    }
    return m;
}
