#include <stdio.h>

int map[1005][1005];

int main(void)
{
    int n,m,i,j,k,sum;
    scanf("%d %d",&n,&k);
    for(i=0;i<=n;i++)
    {
        map[i][0]=1;
    }
    map[1][1]=1; map[2][1]=2;
    for(i=3;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            map[i][j]=(map[i-2][j-1]+map[i-1][j])%1000000003;
        }
    }
    printf("%d",(map[n-3][k-1]+map[n-1][k])%1000000003);
}
