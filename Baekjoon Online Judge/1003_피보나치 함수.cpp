#include <stdio.h>
#define MAX(a,b)(a>b?a:b)

int n[50]={1,0,1},m[50]={0,1,1};

int main(void)
{
    int t,i,j=2,k,l;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d",&l);
        if(l<j) { printf("%d %d\n",n[l],m[l]); continue; }
        for(i=j;i<=l;i++)
        {
            n[i]=n[i-1]+n[i-2];
            m[i]=m[i-1]+m[i-2];
        }
        printf("%d %d\n",n[l],m[l]);
        j=i;
    }
}
