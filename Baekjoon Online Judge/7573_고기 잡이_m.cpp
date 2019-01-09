#include <stdio.h>
#include <algorithm>
#define M 10005
#define MAX(a,b)(a>b?a:b)

int map[M][M],X[105],Y[105];

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,l,m,i,j,k,o,max=0,I,J,cnt;
    scanf("%d %d %d",&n,&l,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&Y[i],&X[i]);
        map[Y[i]][X[i]]=1;
    }
    std::sort(Y+1,Y+m+1);
    std::sort(X+1,X+m+1);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            for(k=l/2-1;k>=1;k--)
            {
                cnt=0;
                for(I=Y[i];I<=Y[i]+k;I++)
                {
                    for(J=X[j];J<=X[j]+(l/2-k);J++)
                    {
                        if(map[I][J]==1) cnt++;
                    }
                }
                max=MAX(max,cnt);
            }
        }
    }
    printf("%d",max);
}
