#include <stdio.h>

int map[1005][1005],cnt[1005],data[1005][10];

int main(void)
{
    int n,i,j,k,l,max=0,res=1;
    scanf("%d",&n);
    l=n;
    for(i=1;i<=n;i++) { for(j=1;j<=5;j++) scanf("%d",&data[i][j]); }
    for(i=1;i<=5;i++)
    {
        n=l;
        while(n>=1)
        {
            k=data[n][i];
            for(j=l;j>=1;j--)
            {
                if(j==n) continue;
                if(data[j][i]==k && map[n][j]==0) { cnt[n]++; cnt[j]++; map[n][j]=map[j][n]=1; }
            }
            n--;
        }
    }
    for(i=1;i<=l;i++) { if(cnt[i]>max) { max=cnt[i]; res=i; } }
    printf("%d",res);
}
