#include <stdio.h>
#include <algorithm>

long long par[100005],cnt[100005];

struct koi
{
    long long x; long long y; long long z;
};

koi cost[100005];

bool cmp(const koi &A,const koi &B)
{
    return (A.z>B.z);
}

int f(int a)
{
    if(a==par[a]) return a;
    else return par[a]=f(par[a]);
}

int main(void)
{
    freopen("input.txt","r",stdin);
    long long n,m,i,j,k,cntm=0,sum=0,X,Y;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%lld %lld %lld",&cost[i].x,&cost[i].y,&cost[i].z);
    }
    for(i=1;i<=n;i++)
    {
        par[i]=i;
        cnt[i]=1;
    }
    std::sort(cost+1,cost+m+1,cmp);
    for(i=1;i<=m;i++)
    {
        X=f(cost[i].x); Y=f(cost[i].y);
        if(X!=Y)
        {
            cntm=(cnt[X]*cnt[Y]+cntm);
            par[Y]=par[X];
            cnt[X]+=cnt[Y];
        }
        sum+=cntm*cost[i].z;
    }
    printf("%lld",sum%1000000000);
}
