#include <stdio.h>
#define MAX(a,b)(a>b?a:b)

int map[105][10005];

struct koi
{
    int bit; int t;
};

koi data[105];

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,m,i,j,k=0,max=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&data[i].bit);
    for(i=1;i<=n;i++) { scanf("%d",&data[i].t); k+=data[i].t; }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=max;j++)
        {
            if(map[i-1][j]!=0) map[i][j+data[i].t]=MAX(map[i-1][j+data[i].t],map[i-1][j]+data[i].bit);
            if(map[i-1][j]!=0 && map[i][j]==0) map[i][j]=map[i-1][j];
        }
        max+=data[i].t;
        map[i][data[i].t]=MAX(map[i-1][data[i].t],data[i].bit);
    }
    for(i=0;i<=k;i++)
    {
        if(map[n][i]>=m) { printf("%d",i); break; }
    }
}
