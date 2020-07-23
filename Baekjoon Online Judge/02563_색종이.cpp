#include <stdio.h>

int map[106][106];

int main()
{
    freopen("input.txt","r",stdin);
    int n,i,j,k,a,b,l,m,cnt=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        for(l=b;l<b+10;l++)
        {
            for(m=a;m<a+10;m++)
            {
                if(map[l][m]==0) cnt++;
                map[l][m]=1;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
