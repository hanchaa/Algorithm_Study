#include <stdio.h>

int data[100005],g[100005];

int gcd(int a,int b)
{
    if(a==b) return a;
    if(b==0) return a;
    gcd(b,a%b);
}

int main()
{
    freopen("input.txt","r",stdin);
    int n,i,j,k,r;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&data[i]);
        if(i>=2) g[i-1]=data[i]-data[i-1];
    }
    r=g[1];
    for(i=2;i<n;i++)
    {
        r=gcd(r,g[i]);
    }
    printf("%d",(data[n]-data[1])/r-n+1);
    return 0;
}
