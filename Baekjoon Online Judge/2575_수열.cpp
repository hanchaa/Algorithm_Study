#include <stdio.h>

int main(void)
{
    int n,m,i,j,k=0;
    scanf("%d",&m);
    if(m%3==0) printf("%d ",m/3);
    else printf("%d ",m/3+1);
    if(m==1) { printf("1"); return 0; }
    while(m%4==0)
    {
        k++; m/=4;
    }
    while(m>1)
    {
        for(i=2;i<=m;i++)
        {
            if(m%i==0) { k++; m/=i; break; }
        }
    }
    printf("%d",k);
}
