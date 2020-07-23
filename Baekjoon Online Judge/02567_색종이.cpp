#include <stdio.h>

int map[105][105];

int main()
{
    freopen("input.txt","r",stdin);
    int n,i,j,k,cnt=0,a,b;
    scanf("%d",&n);
    for(k=1;k<=n;k++)
    {
        scanf("%d %d",&a,&b);
        for(i=b;i<b+10;i++)
        {
            for(j=a;j<a+10;j++)
            {
                map[i][j]=1;
            }
        }
    }
    for(i=1;i<=100;i++)
    {
        for(j=1;j<=100;j++)
        {
            if(map[i][j]==1)
            {
                if(map[i+1][j]==0) cnt++;
                if(map[i-1][j]==0) cnt++;
                if(map[i][j+1]==0) cnt++;
                if(map[i][j-1]==0) cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
