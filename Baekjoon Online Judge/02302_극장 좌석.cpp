#include <stdio.h>

int t[50],chk[50];

int main(void)
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&k); chk[k]=1;
    }
    t[1]=t[0]=1;
    for(i=2;i<=n;i++)
    {
        t[i]=t[i-1];
        if(chk[i]==0 && chk[i-1]==0) t[i]=t[i-2]+t[i-1];
    }
    printf("%d",t[n]);
}
