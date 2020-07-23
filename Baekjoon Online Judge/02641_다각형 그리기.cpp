#include <stdio.h>

int stand[105],data[105][55],res[105][55];

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,i,j,k,l,cnt=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&stand[i]);
    for(i=i;i<=n*2;i++) stand[i]=stand[i%n];
    scanf("%d",&k);
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=n;j++) scanf("%d",&data[i][j]);
        for(j=1;j<=n;j++)
        {
            for(l=1;l<=n;l++)
            {
                if(stand[j+l-1]!=data[i][l]) break;
            }
            if(l>n)
            {
                for(l=1;l<=n;l++) res[cnt][l]=data[i][l];
                cnt++; break;
            }
        }
        if(j<=n) continue;
        for(j=1;j<=n;j++)
        {
            for(l=n;l>=1;l--)
            {
                if(data[i][l]==2 && stand[j+n-l]==4) continue;
                if(data[i][l]==2 && stand[j+n-l]!=4) break;
                if((data[i][l]+2)%4!=stand[j+n-l]) break;
            }
            if(l<1)
            {
                for(l=1;l<=n;l++) res[cnt][l]=data[i][l];
                cnt++; break;
            }
        }
    }
    printf("%d\n",cnt-1);
    for(i=1;i<cnt;i++) { for(j=1;j<=n;j++) printf("%d ",res[i][j]); printf("\n"); }
}
