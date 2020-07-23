#include <stdio.h>
#define MAX(a,b)(a>b?a:b)

int dice(int a,int b,int c,int d)
{
    if(a==b && a==c && a==d ) return 50000+a*5000;
    else if((a==b && b==c) || (a==b && b==d) || (a==c && c==d)) return 10000+a*1000;
    else if(b==c && c==d) return 10000+b*1000;
    else if((a==b && c==d) || (a==c && b==d)) return 2000+a*500+d*500;
    else if(a==d && b==c) return 2000+a*500+b*500;
    else if(a==b || a==c || a==d) return 1000+a*100;
    else if(b==c || b==d) return 1000+b*100;
    else if(c==d) return 1000+c*100;
    else return MAX(MAX(MAX(a,b),c),d)*100;
}

int main()
{
    int n,i,j,k,max=0,d1,d2,d3,d4;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&d1,&d2,&d3,&d4);
        max=MAX(max,dice(d1,d2,d3,d4));
    }
    printf("%d",max);
    return 0;
}
