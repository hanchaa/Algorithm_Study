#include <stdio.h>
#define MAX(a,b)(a>b?a:b)

int t[505][505],k1[10],k2[10],s[5];

int main(void)
{
    int i,j,k,m1=0,m2=0;
    for(i=1;i<=3;i++) scanf("%d",&s[i]);
    for(i=1;i<=5;i++) { scanf("%d %d",&k1[i],&k2[i]); m1=MAX(m1,k1[i]); m2=MAX(m2,k2[i]); }
    for(i=0;i<=m1;i++) for(j=0;j<=m2;j++) t[i][j]=2;
    for(i=0;i<=m1;i++)
    {
        for(j=0;j<=m2;j++)
        {
            if(i==0 && j==0) continue;
            for(k=1;k<=3;k++)
            {
                if(i-s[k]>=0)
                {
                    if(t[i-s[k]][j]==2) { t[i][j]=1; break; }
                    else if(t[i-s[k]][j]==1) t[i][j]=2;
                }
                if(j-s[k]>=0)
                {
                    if(t[i][j-s[k]]==2) { t[i][j]=1; break; }
                    else if(t[i][j-s[k]]==1) t[i][j]=2;
                }
            }
        }
    }
    for(i=1;i<=5;i++)
    {
        if(t[k1[i]][k2[i]]==1) printf("A\n");
        else if(t[k1[i]][k2[i]]==2) printf("B\n");
    }
}
