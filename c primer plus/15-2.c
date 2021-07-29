#include <stdio.h>
#include <limits.h>
#include <string.h>
int btoi(char *st);
char * show_at2(int i);
int main(void)
{
    char s1[30],s2[30];
    int i1,i2;
    printf("input a string.\n");
    scanf("%s",s1);
    printf("input another string.\n");
    scanf("%s",s2);
    i1=btoi(s1);
    i2=btoi(s2);
    printf("%10d%10d\n",i1,i2);
    show_at2(i1);

    show_at2(i2);
    putchar('\n');
    printf("%10d%10d\n",~i1,~i2);
    show_at2(~i1);
    show_at2(~i2);
    putchar('\n');
    printf("%10d\n",i1&i2);
    show_at2(i1&i2);
    putchar('\n');
    printf("%10d\n",i1|i2);
    show_at2(i1|i2);
    putchar('\n');
    printf("%10d\n",i1^i2);
    show_at2(i1^i2);
    putchar('\n');

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
