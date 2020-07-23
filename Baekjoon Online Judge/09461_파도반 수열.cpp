#include <stdio.h>
long long data[105]={0,1,1,1,2,2},c[105];
int main(void)
{
    int m=0,i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++) { scanf("%d",&c[i]); if(c[i]>m) m=c[i]; }
    for(i=6;i<=m;i++) data[i]=data[i-1]+data[i-5];
    for(i=1;i<=t;i++) printf("%lld\n",data[c[i]]);
}
