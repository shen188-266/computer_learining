#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * s_gets(char * st,int n);
int main(void)
{
    FILE *fp,*fp1;
    int sou[20][31];
    char convert[]={' ','.','\'','\"','^','*','%','$','@','#'};
    char s1[256],s2[256],s3[256];
    char *str;
    int i=0,j=0;

    printf("input the file name.\n");
    s_gets(s1,256);
    if((fp=fopen(s1,"r"))==NULL)
    {
        fprintf(stderr,"can't open the file");
        exit(EXIT_FAILURE);
    }

    for(int i=0;i<20;i++)
     {for(int j=0;j<30;j++)
       {
           fscanf(fp,"%d",&sou[i][j]);
       }
       sou[i][30]=0;}


    printf("input the output file name.\n");
    s_gets(s2,256);
    if((fp1=fopen(s2,"w"))==NULL)
    {
        fprintf(stderr,"can't open the file");
        exit(EXIT_FAILURE);
    }


    while(i<20)
    {
       while(j<31)
       {
         fprintf(fp1,"%c",convert[sou[i][j]]);
         j++;
       }
       putc('\n',fp1);
       i++;
       j=0;
    }
    if(fclose(fp)!=0)
    {
        fprintf(stderr,"can't close the file");
        exit(EXIT_FAILURE);
    }
    if(fclose(fp1)!=0)
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
