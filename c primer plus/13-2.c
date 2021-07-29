#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 81
char * s_gets(char * st,int n);
int main(void)
{
    FILE *fp1,*fp2;
    char s1[SIZE],s2[SIZE];
    char ch;
    printf("input the file you want to copy:");
    s_gets(s1,SIZE);
    printf("input the name of destination file:");
    s_gets(s2,SIZE);
    if(strcmp(s1,s2)==0)
    {
        fprintf(stderr,"the file can't be copy to itself.\n");
        exit(EXIT_FAILURE);
    }
    if((fp1=fopen(s1,"r"))==NULL)
    {
        fprintf(stderr,"can't open %s\n",s1);
        exit(EXIT_FAILURE);
    }
    if((fp2=fopen(s2,"w+"))==NULL)
    {
        fprintf(stderr,"can't open %s\n",s2);
        exit(EXIT_FAILURE);
    }
    if(setvbuf(fp1,NULL,_IOFBF,4096)!=0)
    {
        fprintf(stderr,"can't built input buffer.\n");
        exit(EXIT_FAILURE);
    }
    if(setvbuf(fp2,NULL,_IOFBF,4096)!=0)
    {
        fprintf(stderr,"can't built output buffer.\n");
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fp1))!=EOF)
    {
        ch=toupper(ch);
        putc(ch,fp2);
    }
    if(fclose(fp1)!=0||fclose(fp2)!=0)
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
