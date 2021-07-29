#include <stdio.h>
char * dun(char * op,int n);
int main(void)
{char op[10];
dun(op,10);
for(int i=0;i<10;i++)
    putchar(op[i]);
putchar('\n');
return 0;}
char * dun(char * op,int n){
char * oc;
oc=fgets(op,10,stdin);
if(oc)
return op;
else
    return NULL;
}
