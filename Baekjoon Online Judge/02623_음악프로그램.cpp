#include <stdio.h>
#include <queue>
#define N 1005
using namespace std;

queue<int> q;

int data[N][N],in[N],cnt[N],res[N];

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,i,j,k,m,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&k,&a);
        for(j=2;j<=k;j++)
        {
            scanf("%d",&b);
            data[a][++cnt[a]]=b;
            in[b]++;
            a=b;
        }
    }
    for(i=1;i<=n;i++) if(in[i]==0) q.push(i);
    for(i=1;i<=n;i++)
    {
        if(q.empty()) { printf("0"); return 0; }
        res[i]=k=q.front(); q.pop();
        for(j=1;j<=cnt[k];j++)
        {
            in[data[k][j]]--;
            if(in[data[k][j]]==0) q.push(data[k][j]);
        }
    }
    for(i=1;i<=n;i++) printf("%d\n",res[i]);
}
