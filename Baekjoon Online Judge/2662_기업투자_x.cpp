#include <stdio.h>

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int map[22][305]={0},data[22][305]={0},m,n,i,j,k,path[22][305]={0},w[305]={0};
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&k);
            map[j][i]=k;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            k=0;
            while(k<=j)
            {
                if(data[i][j]<data[i-1][k]+map[i][j-k]) { data[i][j]=data[i-1][k]+map[i][j-k]; path[i][j]=k; }
                k++;
            }
        }
    }
    w[n]=m-path[n][m];
    w[n-1]=path[n][m];
    k=path[n][m];
    for(i=n-2;i>=1;i--)
    {
        w[i]=path[i+1][k];
        k=path[i+1][k];
    }
    printf("%d\n",data[n][m]);
    for(i=1;i<=n;i++)
    {
        printf("%d ",w[i]);
    }
    return 0;
}
