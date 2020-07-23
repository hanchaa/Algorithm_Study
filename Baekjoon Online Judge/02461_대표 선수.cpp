#include <stdio.h>
#include <algorithm>
#define MAX(a,b)(a>b?a:b)
#define MIN(a,b)(a<b?a:b)

int data[1005][1005],pt[1005];

struct koi
{
    int a; int b;
};

koi data2[1000005];

bool cmp(const koi &A,const koi &B)
{
    return (A.a<B.a);
}

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,m,i,j,k,max=0,res=999999999;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&data[i][j]);
            data2[(i-1)*m+j].a=data[i][j];
            data2[(i-1)*m+j].b=i;
        }
        std::sort(data[i]+1,data[i]+m+1);
        pt[i]=1;
        max=MAX(max,data[i][1]);
    }
    std::sort(data2+1,data2+n*m+1,cmp);
    i=1;
    while(1)
    {
        res=MIN(res,max-data2[i].a);
        j=data2[i++].b;
        pt[j]++;
        if(pt[j]>m) break;
        max=MAX(max,data[j][pt[j]]);
    }
    printf("%d",res);
}
