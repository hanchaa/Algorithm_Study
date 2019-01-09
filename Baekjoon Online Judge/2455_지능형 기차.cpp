#include <stdio.h>
#define MAX(a,b)(a>b?a:b)

int main()
{
    freopen("input.txt","r",stdin);
    int n,i,j,k=0,mx=0,in,out;
    for(i=1;i<=4;i++)
    {
        scanf("%d %d",&out,&in);
        k=k-out+in;
        mx=MAX(k,mx);
    }
    printf("%d",mx);
    return 0;
}
