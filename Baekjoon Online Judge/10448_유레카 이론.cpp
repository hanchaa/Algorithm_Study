#include <stdio.h>

int num[50];

int main(void)
{
    int i,j,l,k,t,tt;
    for(i=1;i<=45;i++) num[i]=i*(i+1)/2;
    scanf("%d",&t);
    for(tt=1;tt<=t;tt++)
    {
        scanf("%d",&k);
        for(i=1;i<=45;i++) { if(num[i]>=k) break; } i--;
        for(i=i;i>=1;i--)
        {
            for(j=i;j>=1;j--)
            {
                for(l=j;l>=1;l--)
                {
                    if(num[i]+num[j]+num[l]==k) { printf("1\n"); break; }
                }
                if(l>=1) break;
            }
            if(j>=1) break;
        }
        if(i==0) printf("0\n");
    }
}
