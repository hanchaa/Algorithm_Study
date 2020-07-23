#include <stdio.h>
#include <algorithm>
#define M 100005
using namespace std;

long long a[M],b[M],cnt;

struct koi
{
    int p,q;
}d1[M],d2[M];

bool cmp(const koi &A,const koi &B)
{
    return A.p<B.p;
}

void fsort(int l,int r)
{
    int i,j,k,x,y;
    if(l+2>=r)
    {
        for(i=l;i<r;i++)
        {
            for(j=l;j<r;j++)
            {
                if(a[j]>a[j+1]) { k=a[j]; a[j]=a[j+1]; a[j+1]=k; cnt++; }
            }
        }
    }
    else
    {
        fsort(l,(l+r)/2);
        fsort((l+r)/2+1,r);
        x=l;y=(l+r)/2+1;
        for(i=l;i<=r;i++)
        {
            if(y>r) b[i]=a[x++];
            else if(x>=(l+r)/2+1) b[i]=a[y++];
            else if(a[x]<=a[y]) b[i]=a[x++];
            else if(a[y]<a[x]) { b[i]=a[y++]; cnt+=(l+r)/2-x+1; }
        }
        for(i=l;i<=r;i++) a[i]=b[i];
    }
}

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,i,k,t,tt;
    scanf("%d",&t);
    for(tt=1;tt<=t;tt++)
    {
        cnt=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++) { scanf("%d",&k); d1[i].p=k; d1[i].q=i; }
        for(i=1;i<=n;i++) { scanf("%d",&k); d2[i].p=k; d2[i].q=i;}
        sort(d1+1,d1+n+1,cmp); sort(d2+1,d2+n+1,cmp);
        for(i=1;i<=n;i++) a[d1[i].q]=d2[i].q;
        fsort(1,n);
        printf("%lld\n",cnt);
    }
}
