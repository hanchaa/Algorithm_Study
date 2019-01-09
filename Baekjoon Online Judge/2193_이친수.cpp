#include <stdio.h>

long long t[100];

int main(void)
{
    long long n,i;
    scanf("%lld",&n); t[1]=1;
    for(i=2;i<=n;i++)
    {
        t[i]=t[i-1]+t[i-2];
    }
    printf("%lld",t[n]);
}
