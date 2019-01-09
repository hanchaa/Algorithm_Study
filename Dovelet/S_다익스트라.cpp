#include <stdio.h>
#define min(a,b)(a<b?a:b)

int map[1005][1005]={0};

int main()
{
    freopen("input.txt","r",stdin);
    int i,j,k,n,m,s,a,b,c,chk[1005]={0},fr[1005]={0},sum[1005]={0},min,way[1005]={0};
    scanf("%d %d %d",&n,&m,&s);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        map[a][b]=c;
    }
    fr[s]=sum[s]=0; chk[s]=1;
    k=s;
    while(c!=n)
    {
        for(i=1;i<=n;i++)
        {
            if(map[k][i]!=0 && chk[i]==0)
            {
                c=1;
                j=sum[k]+map[k][i];
                if(sum[i]==0) { sum[i]=j; fr[i]=k; }
                else
                {
                     if(sum[i]>j) { sum[i]=j; fr[i]=k; c=0; }
                }
            }
        }
        min=9999999;
        for(i=1;i<=n;i++)
        {
            if(sum[i]!=0 && sum[i]<min && chk[i]==0)
            {
                min=sum[i];
                j=i;
            }
        }
        chk[j]=1;
        if(map[k][j]!=0 && c==0) fr[j]=k;
        k=j;
        c=0;
        for(i=1;i<=n;i++)
        {
            if(chk[i]==1) c++;
        }
    }
    for(i=1;i<=n;i++)
    {
        k=i;
        way[0]=i;
        for(j=1;j<=100001;j++)
        {
            way[j]=fr[k];
            k=fr[k];
            if(fr[k]==0) break;
        }
        if(way[j]==0) j--;
        for(j=j;j>=0;j--)
        {
            printf("%d ",way[j]);
        }
        printf("\n");
    }
    return 0;
}
