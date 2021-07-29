#include <stdio.h>
#include <string.h>
#include <limits.h>
int jianchawei(int value,int n);
char * show_at2(int i);
int main(void)
{
    int a,n;
    printf("input a integar and after space input another int\n"
           "i will check if this is 1\n");
    scanf("%d %d",&a,&n);
    show_at2(a);
    if(jianchawei(a,n)==1)
    printf("it is open\n");
    else if(jianchawei(a,n)==0)
    printf("it is close\n");
    else if(jianchawei(a,n)==-1)
    printf("error\n");
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
int jianchawei(int value,int n){
int o=sizeof(int)*CHAR_BIT;
int i=0;
if(n>o||n<0)
    return -1;
for(;i<n;i++)
{
    value>>=1;
}
if(value&01)
return 1;
else
    return 0;
}
