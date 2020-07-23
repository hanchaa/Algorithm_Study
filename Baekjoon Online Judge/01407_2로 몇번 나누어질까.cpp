#include <stdio.h>

int main()
{
    long long n,i,j,k=0,a,b,sum=0,x,y,mul[60]={0};
    scanf("%lld %lld",&a,&b);
    i=1;
    for(n=1;n<b;)
    {
        n*=2;
        mul[i++]=n;
    }
    i--;
    for(n=i;n>=1;n--)
    {
        i=b/mul[n];
        j=a/mul[n];
        if(a%mul[n]==0) x=i-j+1;
        else x=i-j;

        sum+=(x-k)*mul[n];
        k=x;
    }
    if(b%2==0 && a%2==0) sum+=(b-a)/2;
    else sum+=(b-a)/2+1;
    printf("%lld",sum);
    return 0;
}
