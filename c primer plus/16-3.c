#include <stdio.h>
#include <math.h>
#define NDEBUG
#include <assert.h>

typedef struct jizuobiao {
   double mo;
   double jiao;}jizuo;
typedef struct zhijiaozuobiao {
   double x;
   double y;}zhijiao;
zhijiao jizuo_to_zhijiao(jizuo jj);
int main(void)
{
    jizuo jj;
    zhijiao zhi;
    printf("input r and angle and i will return x and y:");
    scanf("%lf %lf",&jj.mo,&jj.jiao);
    assert(jj.mo>0&&jj.jiao>0);
    zhi=jizuo_to_zhijiao(jj);
    assert(zhi.x>0&&zhi.y>0);
    printf("the x=%lf, y=%lf\n",zhi.x,zhi.y);

    return 0;
}
zhijiao jizuo_to_zhijiao(jizuo jj){
        assert(jj.jiao>0&&jj.mo>0);
zhijiao temp;
temp.x=jj.mo*cos(jj.jiao);
temp.y=jj.mo*sin(jj.jiao);
    assert(temp.x>0&&temp.y>0);
return temp;}

