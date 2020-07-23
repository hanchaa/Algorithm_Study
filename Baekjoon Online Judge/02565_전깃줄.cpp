#include <stdio.h>
#include <algorithm>
#define M 105
#define MAX(a,b)(a>b?a:b)

struct AAA
{
    int p;
    int q;
};

AAA data[M];

bool cmp(const AAA &a,const AAA &b)
{
    return a.p<b.p;
}

int main()
{
    freopen("input.txt","r",stdin);
    int n,i,j=0,k,t[M];
    scanf("%d",&n);
    for(i=1;i<=n;i++) { scanf("%d %d",&data[i].p,&data[i].q); t[i]=1; }
    std::sort(data+1,data+n+1,cmp);
    for(i=2;i<=n;i++)
    {
        for(k=1;k<=i-1;k++)
        {
            if(data[k].q < data[i].q) t[i]=MAX(t[i],t[k]+1);
        }
        if(t[i]>j) j=t[i];
    }
    printf("%d",n-j);
    return 0;
}
