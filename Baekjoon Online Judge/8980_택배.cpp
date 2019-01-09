#include <stdio.h>

int town[2005][2005];

int main()
{
    freopen("input.txt","r",stdin);
    int n,c,m,i,j,k,l,o,ai,bi,ci,deli[2005]={0},deltem[2005]={0},cnt=0,truck=0,temp;
    scanf("%d %d %d",&n,&c,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&ai,&bi,&ci);
        town[ai][bi]=ci;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(town[j][i]>0)
            {
                temp=town[j][i];
                for(l=j+1;l<=i;l++)
                {
                    if(deltem[l]+temp<=c) deltem[l]+=temp;
                    else
                    {
                        temp=c-deltem[l];
                        for(o=j+1;o<=l;o++) deltem[o]=deli[o];
                        l=j;
                    }
                }
                for(l=j+1;l<=i;l++) deli[l]=deltem[l];
                cnt+=temp;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
