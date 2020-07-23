#include <stdio.h>
#include <algorithm>

using namespace std;

struct koi
{
    int l,h;
}data[1005];

bool cmp(const koi &A,const koi &B)
{
    return A.l<B.l;
}

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,i,k,m=0,cnt=0,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++) { scanf("%d %d",&data[i].l,&data[i].h); if(data[i].h>m) { m=data[i].h; k=data[i].l; } }
    sort(data+1,data+n+1,cmp);
    cnt+=m;
    i=m=t=0;
    while(data[i].l!=k)
    {
        if(data[i].h>m) { cnt+=m*(data[i].l-t); t=data[i].l; m=data[i].h; }
        i++;
    }
    cnt+=m*(data[i].l-t);
    m=0; i=t=n;
    while(data[i].l!=k)
    {
        if(data[i].h>m) { cnt+=m*(t-data[i].l); t=data[i].l; m=data[i].h; }
        i--;
    }
    cnt+=m*(t-data[i].l);
    printf("%d",cnt);
}
