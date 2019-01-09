#include <stdio.h>
#define max(a,b) (a>b?a:b)


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m,n,data[305]={0},i,j,k,group[305][305]={0},result[305][305]={0},sum,path[305]={0};
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&data[i]);
    }
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            result[i][j]=999999;
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=i;j>=1;j--)
        {
            result[1][i]+=data[j];
            group[1][i]=1;
        }
    }
    for(i=2;i<=n;i++)
    {
        for(j=i;j<=m;j++)
        {
            sum=0;
            for(k=j;k>=i;k--)
            {
                sum+=data[k];
                if(result[i][j]>max(sum,result[i-1][k-1])) { result[i][j]=max(sum,result[i-1][k-1]); group[i][j]=k; }
            }
        }
    }
    j=n; k=m;
    for(i=0;i<n;i++)
    {
        path[i]=k-group[j][k]+1;
        k=group[j][k]-1;
        j--;
    }
    printf("%d\n",result[n][m]);
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",path[i]);
    }
    return 0;
}
