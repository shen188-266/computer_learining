#include <stdio.h>
#include <string.h>
struct name {
char firstname[20];
char mid[20];
char lastname[20];};
struct sdk {
   char sd[10];
   struct name sdf;};
void printstr(struct sdk *mmn);
char * s_gets(char * st ,int n);
int main(void)
{
    struct sdk mmn;
    printf("input your last name.\n");
    s_gets(mmn.sdf.lastname,20);
    printf("input your mid name.\n");
    s_gets(mmn.sdf.mid,20);
    printf("input your first name.\n");
    s_gets(mmn.sdf.firstname,20);
    printf("input your card numbers.\n");
    s_gets(mmn.sd,10);
    printstr(&mmn);
    return 0;
}
void printstr(struct sdk *mmn){
printf("%s, %s %c. --%s",mmn->sdf.lastname,mmn->sdf.firstname,mmn->sdf.mid[0],mmn->sd);}
char * s_gets(char *st ,int n){
char * re;
re=fgets(st,20,stdin);
if(re)
    {
        while(*st!='\0'&&*st!='\n')
            st++;
        if(*st='\n')
            *st='\0';
        else
            while(getchar()!='\n')
            continue;
    }
    return re;
}
