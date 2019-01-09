#include <stdio.h>
#include <algorithm>

int main()
{
    freopen("input.txt","r",stdin);
    int n,budget[10005]={0},m,i,j,k=0,k1=0,s,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&budget[i]);
        k+=budget[i];
    }
    scanf("%d",&m);
    std::sort(budget+1,budget+n+1);
    if(k<=m) printf("%d",budget[n]);
    else
    {
        k=budget[2];
        while(k!=k1)
        {
            k1=k;
            s=0;
            for(t=1;t<=n;t++)
            {
                if(budget[t]<k) s+=budget[t];
                if(budget[t]>=k) {t--; break;}
            }
            k=(m-s)/(n-t);
        }
        printf("%d",k);
    }
    return 0;
}
