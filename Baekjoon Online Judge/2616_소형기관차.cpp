#include <stdio.h>
#define N 50005
#define MAX(a,b)(a>b?a:b)
int data[N],data2[N],t[5][N];

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,m,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&data[i]);
    scanf("%d",&m);
    for(i=1;i<=m;i++) data2[i]=data2[i-1]+data[i];
    for(i=m+1;i<=n;i++) data2[i]=data2[i-1]+data[i]-data[i-m];
    for(i=1;i<=n;i++) t[1][i]=MAX(t[1][i-1],data2[i]);
    for(i=2;i<=3;i++)
    {
        for(j=1;j<=m;j++)
        {
            t[i][j]=MAX(t[i][j-1],data2[j]);
        }
        for(j=m+1;j<=n;j++)
        {
            t[i][j]=MAX(t[i][j-1],data2[j]+t[i-1][j-m]);
        }
    }
    printf("%d",t[3][n]);
}
