#include <stdio.h>
#include <algorithm>

int ge[1005],p[1005],k;

struct q
{
    int x,y,z;
}data[100005];

bool cmp(const q &a,const q &b)
{
    if(a.z!=b.z) return a.z<b.z;
    a.x<b.x;
}

int f(int c)
{
    if(c==p[c]) return c;
    else return p[c]=f(p[c]);
}

bool gchk(int l)
{
    int i,j,r;
    r=f(l);
    for(i=1;i<=k;i++)
    {
        j=f(ge[i]);
        if(r==j) break;
    }
    if(i>k) return false;
    else return true;
}

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,m,i,j,a,b,sum=0;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=k;i++) scanf("%d",&ge[i]);
    for(i=1;i<=m;i++) scanf("%d %d %d",&data[i].x,&data[i].y,&data[i].z);
    for(i=1;i<=n;i++) p[i]=i;
    std::sort(data+1,data+m+1,cmp);
    for(i=1;i<=m;i++)
    {
        if(gchk(data[i].x) && gchk(data[i].y)) continue;
        a=f(data[i].x); b=f(data[i].y);
        if(a!=b) { p[b]=p[a]; sum+=data[i].z; }
    }
    printf("%d",sum);
}
