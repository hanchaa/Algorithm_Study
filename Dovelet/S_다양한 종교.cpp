#include <stdio.h>
#define N 50005
int p[N],chk[N];

int f(int a)
{
    if(p[a]==a) return a;
    else return p[a]=f(p[a]);
}

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,m,i,k=0,a,b;
    scanf("%d %d",&n,&m); for(i=1;i<=n;i++) p[i]=i;
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        if(f(a)!=f(b)) p[f(b)]=p[f(a)];
    }
    for(i=1;i<=n;i++) if(chk[f(p[i])]==0) { k++; chk[f(p[i])]=1; }
    printf("%d",k);
}
