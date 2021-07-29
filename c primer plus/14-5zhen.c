#include <stdio.h>
#include <string.h>
#define CSIZE 2
#define SIZE 20
struct name {
   char lastname[SIZE];
   char fristname[SIZE];
   };
struct student {
 struct name sdf;
 float grade[3];
 float average;
 };
char * s_gets(char *st,int n);
float classaver(struct student st);

void printcls(struct student *st,int n);
void printcav(struct student *st,int n);
int main(void)
{
    struct student wode[CSIZE];
    int i=0;
    while(i<CSIZE)
    {
        printf("input student's lastname.\n");
        s_gets(wode[i].sdf.lastname,SIZE);
        printf("input student's fristname,\n");
        s_gets(wode[i].sdf.fristname,SIZE);
        printf("input 3 grades of the student(space to separate).\n");
        scanf("%f %f %f",&wode[i].grade[0],&wode[i].grade[1],&wode[i].grade[2]);

        while(getchar()!='\n')
            continue;
        i++;
    }
    i=0;
    while(i<CSIZE)
    {
        wode[i].average=classaver(wode[i]);

        i++;
    }

    printcls(wode,CSIZE);
    printcav(wode,CSIZE);
    return 0;
}

char * s_gets(char *st,int n){
char * re;
re=fgets(st,SIZE,stdin);
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

float classaver(struct student st){
return (st.grade[0]+st.grade[1]+st.grade[2])/3.0;}

void printcls(struct student *st,int n){
int i=0;
while(i<n)
    {
        printf("the student %s %s's grade1 is %f,grade2 is %f,grade3 is %f,average is %f\n",st->sdf.lastname,st->sdf.fristname,st->grade[0],st->grade[1],st->grade[2],st->average);
        i++;
        st++;
    }
}
void printcav(struct student *st,int n){
int i=0;
float total=0;
while(i<n)
    {
        total+=st->average;
        i++;
        st++;
    }
    printf("the class average grade is %f\n",total/n);
}
