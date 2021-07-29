#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * s_gets(char * st,int n);
int main(void)
{
    FILE *fp;
    char s1[256],s2[256],s3[256];
    char *str;
    int count=0;
    printf("input a string,and i will find it in the file.\n"
           ,"i can also output the line while includes it.\n");
    s_gets(s1,256);
    printf("input the file name.\n");
    s_gets(s2,256);
    if((fp=fopen(s2,"r"))==NULL)
    {
        fprintf(stderr,"can't open the file");
        exit(EXIT_FAILURE);
    }
    while(fgets(s3,256,fp))
    {
        if(strstr(s3,s1))
        {fprintf(stdout,"the %s is included in the line:",s1);
        fputs(s3,stdout);
        count++;}
    }
    if(count==0)
        printf("not find %s in the file.",s1);
    if(fclose(fp)!=0)
    {
        fprintf(stderr,"can't close the file");
        exit(EXIT_FAILURE);
    }
    return 0;
}
char * s_gets(char * st,int n){
char *re;
re=fgets(st,256,stdin);
if(re)
    {
        while(*st!='\0'&&*st!='\n')
            st++;
        if(*st=='\n')
            *st='\0';
        else
            while(getchar()!='\n')
            continue;
    }
    return re;
}
