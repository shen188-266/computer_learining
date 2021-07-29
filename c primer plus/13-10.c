#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 81
char * s_gets(char * st,int n);
int main(void)
{
    FILE *fp;
    char s1[SIZE];
    char cu[256];
    long sh;
    int t;
    printf("input the file you want to watch.\n");
    s_gets(s1,SIZE);
    fp=fopen(s1,"rb");
    printf("please input a location.");
    t=scanf("%ld",&sh);
    while(sh>=0&&t==1)
    {
       fseek(fp,sh,SEEK_SET);
       fgets(cu,256,fp);
       fputs(cu,stdout);
       printf("\nplease input a location.");
       t=scanf("%ld",&sh);
    }

    if(fclose(fp)!=0)
    {
        fprintf(stderr,"can't close files.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
char * s_gets(char * st,int n){
char * re;
char * find;
re=fgets(st,SIZE,stdin);
if(re)
    {
        find=strchr(st,'\n');
        if(find)
            *find='\0';
        else
            while(getchar()!='\n')
            continue;
    }
    return re;
}
