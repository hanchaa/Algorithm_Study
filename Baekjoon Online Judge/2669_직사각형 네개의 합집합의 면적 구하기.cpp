#include <stdio.h>

int map[105][105];

int main()
{
    freopen("input.txt","r",stdin);
    int n,i,j,k,a,b,c,d,cnt=0;
    for(i=1;i<=4;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        for(j=b;j<d;j++) for(k=a;k<c;k++) map[j][k]=1;
    }
    for(i=1;i<=100;i++) for(j=1;j<=100;j++) if(map[i][j]==1) cnt++;
    printf("%d",cnt);
}
