#include <stdio.h>
#include <algorithm>
#define M 500005

int a[M],b[M];
long long cnt[M];

struct AAA
{
    int p;
    int q;
};
AAA data[500005],data2[500005];

bool cmp(const AAA &A, const AAA &B)
{
    return A.p < B.p;
}

int sort(int l,int r)
{
    int i,j,k,x,y;
    if(l+2>=r)
    {
        for(i=l;i<=r;i++)
        {
            for(j=l;j<r;j++)
            {
                if(a[j]>a[j+1])
                {
                    k=a[j];
                    a[j]=a[j+1];
                    a[j+1]=k;
                    cnt[j+1]++;
                }
            }
        }
    }
    else
    {
        sort(l,(l+r)/2);
        sort((l+r)/2+1,r);
        x=l; y=(l+r)/2+1;
        for(i=l;i<=r;i++)
        {
            if(y>r) b[i]=a[x++];
            else if(x>=(l+r)/2+1) b[i]=a[y++];
            else if(a[x]<=a[y]) b[i]=a[x++];
            else if(a[y]<a[x])
            {
                cnt[a[y]]+=(l+r)/2-x+1;
                b[i]=a[y++];
            }
        }
        for(j=l;j<=r;j++) a[j]=b[j];
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    int n,i,j;
    long long k=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        data[i].p=a[i];
        data[i].q=i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        data2[i].p=b[i];
        data2[i].q=i;
    }

    std::sort(data+1,data+n+1,cmp);
    std::sort(data2+1,data2+n+1,cmp);

    for(i=1;i<=n;i++)
    {
        a[data[i].q]=data2[i].q;
    }

    sort(1,n);
    for(i=1;i<=n;i++)
    {
        k+=cnt[i];
    }
    printf("%lld",k);
    return 0;
}
