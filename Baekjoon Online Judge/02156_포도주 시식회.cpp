#include <stdio.h>
#define M 10010
#define Max(a,b)(a>b?a:b)

int table[M],data[M];

int main()
{
    freopen("input.txt","r",stdin);
    int n,i,j,k=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&data[i]);
    }
    table[1]=data[1];
    table[2]=data[1]+data[2];
    for(i=3;i<=n;i++)
    {
        table[i]=Max(Max(data[i]+table[i-2],data[i]+data[i-1]+table[i-3]),table[i-1]);
    }
    printf("%d",table[n]);
    return 0;
}
