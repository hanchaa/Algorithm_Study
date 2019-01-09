#include <stdio.h>
#define N 1005

int a1[N],a2[N],s1[N],s2[N],f1[N*N],f2[N*N];

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,m,i,j,k=0,t;
    scanf("%d %d",&t,&n);
    for(i=1;i<=n;i++) { scanf("%d",&a1[i]); s1[i]=s1[i-1]+a1[i]; }
    scanf("%d",&m);
    for(i=1;i<=m;i++) { scanf("%d",&a2[i]); s2[i]=s2[i-1]+a2[i]; }
    for(i=1;i<=n;i++) for(j=0;j<i;j++) f1[s1[i]-s1[j]]++;
    for(i=1;i<=m;i++) for(j=0;j<i;j++) f2[s2[i]-s2[j]]++;
    for(i=1;i<=t;i++) k+=f1[i]*f2[t-i];
    printf("%d",k);
}
