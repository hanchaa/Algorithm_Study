#include <stdio.h>
#include <algorithm>
#include <string.h>
#define N 500000
using namespace std;
int itree[2*N-1],data[N];
struct koi
{
    int p,q;
}d1[N],d2[N];
bool cmp (const koi &A,const koi &B)
{
    return A.p<B.p;
}
int query(int n, int nx, int ny, int qx, int qy)
{
    int tmp=0;
    if(qx<=nx && qy>=ny) return itree[n];
    else
    {
        int mid=(nx+ny)/2;
        if(qx<=mid) tmp+=query(2*n,nx,mid,qx,qy);
        if(mid<qy) tmp+=query(2*n+1,mid+1,ny,qx,qy);
        return tmp;
    }
}
void update(int n, int nx, int ny, int q)
{
    if(nx==ny) itree[n]=1;
    else
    {
        int mid=(nx+ny)/2;
        if(q<=mid) update(n*2,nx,mid,q);
        else update(n*2+1,mid+1,ny,q);
        itree[n]=itree[n*2]+itree[n*2+1];
    }
}
int main(void)
{
    freopen("input.txt","r",stdin);
    int n,i,t,tt,a;
    long long cnt;
    scanf("%d",&t);
    for(tt=1;tt<=t;tt++)
    {
        cnt=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++) { scanf("%d",&a); d1[i].p=a; d1[i].q=i; }
        for(i=1;i<=n;i++) { scanf("%d",&a); d2[i].p=a; d2[i].q=i; }
        sort(d1+1,d1+n+1,cmp); sort(d2+1,d2+n+1,cmp);
        for(i=1;i<=n;i++) data[d1[i].q]=d2[i].q;
        for(i=1;i<=n;i++)
        {
            if(data[i]==n) { update(1,1,n,data[i]); continue; }
            cnt+=query(1,1,n,data[i]+1,n);
            update(1,1,n,data[i]);
        }
        printf("%lld\n",cnt);
        memset(itree,0,sizeof(itree));
    }
}
