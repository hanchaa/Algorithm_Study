#include <stdio.h>
#include <algorithm>

using namespace std;

int v[105],h[105];

int main(void)
{
    int n,i,j,k,m,a,b,ca=1,cb=1;
    scanf("%d %d %d",&a,&b,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&m);
        if(m==0) scanf("%d",&h[ca++]);
        if(m==1) scanf("%d",&v[cb++]);
    }
    sort(h+1,h+ca); h[ca]=b;
    sort(v+1,v+cb); v[cb]=a;
    a=b=0;
    for(i=1;i<=ca;i++) b=max(b,h[i]-h[i-1]);
    for(i=1;i<=cb;i++) a=max(a,v[i]-v[i-1]);
    printf("%d",b*a);
}
