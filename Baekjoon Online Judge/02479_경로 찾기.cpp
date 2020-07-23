#include <stdio.h>
#include <algorithm>

int map[1005][1005],que[1005],chk[1005],path[1005],path2[1005];

char data[1005][40];

int main(void)
{
    int n,i,j,k,A,B,l,cnt,C=0,r=0,f=0;
    scanf("%d %d ",&n,&k);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            scanf("%c",&data[i][j]);
        }
        scanf("\n");
    }
    scanf("%d %d",&A,&B);
    for(l=1;l<=n;l++)
    {
        for(i=1;i<=n;i++)
        {
            cnt=0;
            if(l==i) continue;
            for(j=1;j<=k;j++)
            {
                if(data[l][j]!=data[i][j]) cnt++;
            }
            if(cnt==1) map[l][i]=1;
        }
    }
    que[++r]=A;
    chk[A]=1;
    k=0;
    while(1)
    {
        f++;
        for(i=1;i<=n;i++)
        {
            if(map[que[f]][i]==1 && chk[i]==0) { que[++r]=i; path[i]=que[f]; chk[i]=1; }
        }
        if(chk[B]==1) break;
        if(f==r) { printf("-1"); k=1; break; }

    }
    i=1;
    path2[i]=B;
    if(k==0)
    {
        while(1)
        {
            path2[++i]=path[B];
            B=path[B];
            if(B==A) break;
        }
        for(j=i;j>=1;j--)
        {
            printf("%d ",path2[j]);
        }
    }
}
