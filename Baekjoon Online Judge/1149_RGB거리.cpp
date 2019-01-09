#include <stdio.h>
#define MIN(a,b)(a<b?a:b)

int data[1005][5],t[1005][5];

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++) { scanf("%d %d %d",&data[i][1],&data[i][2],&data[i][3]); t[i][1]=t[i][2]=t[i][3]=1e9; }
    for(i=1;i<=3;i++) t[1][i]=data[1][i];
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=3;j++)
        {
            for(k=1;k<=3;k++)
            {
                if(k==j) continue;
                t[i][j]=MIN(t[i][j],t[i-1][k]+data[i][j]);
            }
        }
    }
    k=1e9;
    for(i=1;i<=3;i++) k=MIN(k,t[n][i]);
    printf("%d",k);
}
