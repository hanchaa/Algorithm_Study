#include <stdio.h>

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,map[105][105]={0},i,j,k,data[105][105]={0},max=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            data[i][j]=data[i-1][j]+map[i][j];
            if(data[i][j-1]+map[i][j]>data[i][j]) data[i][j]=data[i][j-1]+map[i][j];
        }
    }
    for(i=1;i<=n;i++)
    {
        if(data[n][i]>max) max=data[n][i];
    }
    printf("%d",max);
    return 0;
}
