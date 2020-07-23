#include <stdio.h>

int data[150];

int main(void)
{
    int a,b,i,t,tt,x1,x2,x3,y1,y2,y3;
    scanf("%d",&t);
    for(i=1;i<=300;i++) data[i]=data[i-1]+i;
    for(tt=1;tt<=t;tt++)
    {
        scanf("%d %d",&a,&b);
        for(i=1;i<=141;i++) if(a<=data[i]) { x1=i-data[i]+a; y1=1+data[i]-a; break; }
        for(i=1;i<=141;i++) if(b<=data[i]) { x2=i-data[i]+b; y2=1+data[i]-b; break; }
        x3=x1+x2; y3=y1+y2;
        printf("%d\n",data[x3+y3-1]-y3+1);
    }
}
