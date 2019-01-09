#include <stdio.h>

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,i,j,k,data[105][105]={0},res[105][105]={0},max=-9999999;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&data[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=m;j++)
        {
            for(k=j;k<=m;k++)
            {
                if(res[i][k]==0) res[i][k]=res[i-1][j-1]+data[i][k];
                else if(res[i][k]<res[i-1][j-1]+data[i][k]) res[i][k]=res[i-1][j-1]+data[i][k];
                if(i==n) { if(res[i][k]>max) max=res[i][k]; }
            }
        }
    }
    printf("%d",max);
    return 0;
}
