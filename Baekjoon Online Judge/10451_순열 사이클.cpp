#include <stdio.h>
#include <string.h>
int data[1005],chk[1005];
int main(void)
{
    freopen("input.txt","r",stdin);
    int n,t,i,j,k,tt,cnt;
    scanf("%d",&t);
    for(tt=1;tt<=t;tt++)
    {
        scanf("%d",&n); cnt=0;
        for(i=1;i<=n;i++) scanf("%d",&data[i]);
        for(i=1;i<=n;i++)
        {
            if(chk[i]==1) continue;
            k=i;
            while(1)
            {
                if(chk[k]==1) { cnt++; break; }
                chk[k]=1;
                k=data[k];
            }
        }
        printf("%d\n",cnt);
        memset(chk,0,sizeof(chk));
        memset(data,0,sizeof(data));
    }
}
