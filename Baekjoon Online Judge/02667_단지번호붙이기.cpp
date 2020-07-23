#include <stdio.h>
#include <algorithm>

int data[30][30],que[1000][5],cnt[751],f,r,cntt;

void bfs()
{
    for(f=f;f<r;f++)
    {
        if(data[que[f][1]+1][que[f][2]]==1) { data[que[f][1]+1][que[f][2]]=0; que[r][1]=que[f][1]+1; que[r++][2]=que[f][2]; cnt[cntt]++; }
        if(data[que[f][1]][que[f][2]+1]==1) { data[que[f][1]][que[f][2]+1]=0; que[r][1]=que[f][1]; que[r++][2]=que[f][2]+1; cnt[cntt]++; }
        if(data[que[f][1]-1][que[f][2]]==1) { data[que[f][1]-1][que[f][2]]=0; que[r][1]=que[f][1]-1; que[r++][2]=que[f][2]; cnt[cntt]++; }
        if(data[que[f][1]][que[f][2]-1]==1) { data[que[f][1]][que[f][2]-1]=0; que[r][1]=que[f][1]; que[r++][2]=que[f][2]-1; cnt[cntt]++; }
    }
}

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++) scanf("%1d",&data[i][j]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(data[i][j]==1)
            {
                cntt++;
                r=f=0;
                que[r][1]=i;que[r++][2]=j;
                cnt[cntt]++;
                data[que[f][1]][que[f][2]]=0;
                bfs();
            }
        }
    }
    std::sort(cnt+1,cnt+cntt+1);
    printf("%d",cntt);
    for(i=1;i<=cntt;i++)
    {
        printf("\n%d",cnt[i]);
    }
}
