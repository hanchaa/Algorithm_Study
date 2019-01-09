#include <stdio.h>
#include <algorithm>
#include <queue>
#define N 105

using namespace std;

int data[N][N],in[N],cnt[N],res[N];

queue<int> q;

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,i,j,k;
    scanf("%d",&n);
    while(scanf("%d %d",&i,&j)!=EOF)
    {
        data[i][++cnt[i]]=j;
        in[j]++;
    }
    for(i=1;i<=n;i++) if(in[i]==0) q.push(i);
    for(i=1;i<=n;i++)
    {
        if(q.empty()) { printf("impossible"); return 0; }
        res[i]=k=q.front(); q.pop();
        for(j=1;j<=cnt[k];j++)
        {
            in[data[k][j]]--;
            if(in[data[k][j]]==0) q.push(data[k][j]);
        }
    }
    for(i=1;i<=n;i++) printf("%d ",res[i]);
}
