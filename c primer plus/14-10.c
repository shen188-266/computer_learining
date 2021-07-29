#include <stdio.h>
#include <string.h>
int menu(void);

float add(float a ,float b);
float subtract(float a ,float b);
float multiply(float a ,float b);
float divide(float a ,float b);
float (*pa)(float a ,float b);
float shuy(float a ,float b);
int main(void)
{
    float a,b;
    printf("input two digit, and i will dispose them.(space to separate)\n");
    scanf("%f %f",&a,&b);
    printf("the answer is %f",shuy(a,b));
    return 0;
}
float shuy(float a ,float b)
{
    char temp;
    while(menu())
    {
        scanf("%c",&temp);
        if(temp=='a'||temp=='s'||temp=='m'||temp=='d')
            break;
    }
    switch(temp)
    {
        case 'a':pa=add;
                  break;
        case 's':pa=subtract;
                  break;
        case 'm':pa=multiply;
                  break;
        case 'd':pa=divide;
                  break;
    }
    return pa(a,b);
}
float add(float a ,float b){
return a+b;}
float subtract(float a ,float b){
return a-b;}
float multiply(float a ,float b){
return a*b;}
float divide(float a ,float b){
return a/b;}
int menu(void){
printf("a.add       s,subtract.\nm.multiply       d.divide.\n"
       "choose which to to.\n");
return 1;}
