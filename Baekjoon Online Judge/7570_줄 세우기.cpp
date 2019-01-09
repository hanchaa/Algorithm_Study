#include <stdio.h>
#define M 1000005
#define MAX(a,b)(a>b?a:b)

int a[M],b[M],t[M];

int main(void)
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,i,j,k=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]=i;
    }
    for(i=1;i<=n;i++)
    {
        if(b[a[i]-1]>i) t[i]=1;
        else t[i]=t[b[a[i]-1]]+1;
        k=MAX(k,t[i]);
    }
    printf("%d",n-k);
}
