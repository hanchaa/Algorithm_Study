#include <stdio.h>
#define N 1005
#define MIN(a,b)(a<b?a:b)
#define MAX(a,b)(a>b?a:b)
int map[N][N];

int main(void)
{
    int n,m=1,i,j,k,t;
    scanf("%d %d",&n,&t);
    for(i=1;i<=t;i++) { scanf("%d %d",&j,&k); map[j][k]=-1; }
    for(i=1;i<=n;i++) { if(map[1][i]==-1) map[1][i]=0; else map[1][i]=1; }
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(map[i][j]==-1) { map[i][j]=0; continue; }
            map[i][j]=MIN(MIN(map[i-1][j-1],map[i-1][j]),map[i][j-1])+1;
            m=MAX(m,map[i][j]);
        }
    }
    printf("%d",m);
}
