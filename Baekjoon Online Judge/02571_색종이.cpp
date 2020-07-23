#include <stdio.h>
#define MAX(a,b)(a>b?a:b)

int Map[105][105];

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,i,j,k,a,b,tmp,max=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        for(j=b;j<b+10;j++)
        {
            for(k=a;k<a+10;k++)
            {
                Map[j][k]=1;
            }
        }
    }
    for(i=1;i<=100;i++)
    {
        for(j=1;j<=100;j++)
        {
            if(Map[i][j]!=0) Map[i][j]+=Map[i-1][j];
        }
    }
    for(i=1;i<=100;i++)
    {
        for(j=100;j>=1;j--)
        {
            k=j; a=0;
            tmp=Map[i][j];
            while(1)
            {
                if(Map[i][k]==0) break;
                if(tmp>=Map[i][k]) tmp=Map[i][k];
                a++; k--;
                Map[i][j]=MAX(Map[i][j],tmp*a);
            }
            max=MAX(Map[i][j],max);
        }
    }
    printf("%d",max);
}
