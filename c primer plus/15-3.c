#include <stdio.h>
#include <string.h>
#include <limits.h>
int dakaiwei(int a);
char * show_at2(int i);
int main(void)
{
    int a;
    printf("input a integar.\n");
    scanf("%d",&a);
    show_at2(a);
    printf("open number is %d",dakaiwei(a));
    return 0;
}
char * show_at2(int i){
    static char ntst[sizeof(int)*CHAR_BIT+1];
    for(int j=sizeof(int)*CHAR_BIT;j>0;j--)
    {
        ntst[j-1]=(i&01)+'0';
        i>>=1;
    }
    ntst[sizeof(int)*CHAR_BIT]='\0';
    puts(ntst);
    return ntst;
}
int dakaiwei(int a){
int n=sizeof(int)*CHAR_BIT;
int count=0;
for(;n>0;n--)
{
    if(a&01==1)
        count++;
    a>>=1;
}
return count;
}
