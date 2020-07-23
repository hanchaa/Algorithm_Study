#include <stdio.h>
#include <algorithm>
#include <queue>
#define N 105
using namespace std;

queue<int> q;
int data[N][N],in[N],cnt[N],res[N][N],chk[N];

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,m,i,j,k,a,b,c,o,p;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        data[b][++cnt[b]]=a;
        res[b][a]=c;
        in[a]++;
    }
    a=0;
    for(i=1;i<=n;i++) { if(in[i]==0) { q.push(i); chk[i]=1; a++; res[i][i]=1; } }
    for(i=1;i<=n;i++)
    {
        k=q.front();
        q.pop();
        if(chk[k]==0)
        {
            for(o=1;o<=n;o++)
            {
                for(p=1;p<=n;p++)
                {
                    if(chk[p]==1) res[k][p]+=res[o][k]*res[o][p];
                }
            }
        }
        for(j=1;j<=cnt[k];j++)
        {
            in[data[k][j]]--;
            if(in[data[k][j]]==0) q.push(data[k][j]);
        }
    }
    printf("%d\n",a);
    for(i=1;i<=n;i++) if(chk[i]==1) printf("%d %d\n",i,res[n][i]);
}
