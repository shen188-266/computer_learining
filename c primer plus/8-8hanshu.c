char caidan(void)
{ printf("Enter the operation of your choice:\n");
  printf("a.add            s.subtract\n");
  printf("m.multiply       d.divide\n");
  printf("q.quit\n");
  char ch;
  ch=isp(ch);
  return ch;
}
char isp(char a)
{ a=getchar();
   while(a!='a'&&a!='s'&&a!='m'&&a!='q'&&a!='d')
   {while(getchar()!='\n')
    continue;
    printf("I just can recognize a、s、m、q、d.\ninput again.\n");
    a=getchar();}
    getchar();//肇指概
    return a;
}
float isn(void)
{float a;
char c,b[20];
while(scanf("%f",&a)!=1)
{scanf("%s",b);
printf("%s is not a number.\n",b);
printf("Please enter a number.such as 2.5, -1.78E8,or 3:");
while((c=getchar())!='\n')
continue;}
return a;}
float towisn(void)
{float a;
char c,b[20];
printf("Enter second number:");
while(scanf("%f",&a)!=1)
{scanf("%s",b);
printf("%s is not a number.\n",b);
printf("Please enter a number.such as 2.5, -1.78E8,or 3:");
while((c=getchar())!='\n')
continue;}
getchar();
return a;}
float towisno0(void)
{float a;
char c,b[20];
printf("Enter scecond number:");
while(scanf("%f",&a)!=1||a<=0.001)
{   if(a<=0.001)
      printf("Enter a number other than 0:");
    else
     {scanf("%s",b);
     printf("%s is not a number.\n",b);
     printf("Please enter a number.such as 2.5, -1.78E8,or 3:");}
while((c=getchar())!='\n')
continue;}
getchar();
return a;}
