#include <stdio.h>
#define MAX(a,b)(a>b?a:b)

int dice(int a,int b,int c)
{
    if(a==b && b==c && a==c) return 10000+a*1000;
    else if(a==b || b==c) return 1000+b*100;
    else if(a==c) return 1000+a*100;
    else return MAX(MAX(a,b),c)*100;
}

int data[1005][4];

int main()
{
    int n,i,j,k,max=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&data[i][1],&data[i][2],&data[i][3]);
        max=MAX(max,dice(data[i][1],data[i][2],data[i][3]));
    }
    printf("%d",max);
    return 0;
}
