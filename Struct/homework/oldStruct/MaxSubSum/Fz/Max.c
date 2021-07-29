#include <stdio.h>

int max3(int a,int b,int c);
int MaxSubSum(const int A[],int left,int right);

int main(void){
    int A[5]={1,-2,4,6,-8};
    int a=MaxSubSum(A,0,4);
    printf("%d",a);
    return 0;

}
int MaxSubSum(const int A[],int left,int right){
    //over
    if(right==left){

        return A[right];}
    //defination
    int Maxs,Maxleft,Maxright,Maxlb,Maxrb;
    int mid=(right-left)/2;

    Maxleft=MaxSubSum(A,left,mid);
    Maxright=MaxSubSum(A,mid+1,right);

    Maxlb=0,Maxrb=0;
    int maxt=0;
    for(int i=mid;i>=left;i--)
    {
        maxt+=A[i];
        if(maxt>Maxlb)
            Maxlb=maxt;

    }
    maxt=0;
    for(int i=mid+1;i<=right;i++)
    {
        maxt+=A[i];
        if(maxt>Maxrb)
            Maxrb=maxt;
            printf("111\n");
    }

    return max3(Maxleft,Maxright,Maxlb+Maxrb);
}
int max3(int a,int b,int c){
    if(a>=b){
        if(a>=c)
            return a;
        else
        return c;
    }
    if(b>=c)
        return b;
    else
    return c;
}
