#include <stdio.h>
#define M 1005

int seat[M][M];

int main()
{
    freopen("input.txt","r",stdin);
    int c,r,i,j,k,l,m,o,p;
    scanf("%d %d %d",&c,&r,&k);
    for(i=0;i<=c+1;i++)
    {
        seat[0][i]=seat[r+1][i]=-1;
    }
    for(i=1;i<=r;i++)
    {
        seat[i][0]=seat[i][c+1]=-1;
    }
    i=j=p=l=m=o=1;
    while(1)
    {
        seat[i][j]=p++;
        if(seat[i][j]==k) break;
        if(seat[i-1][j]!=0 && seat[i][j-1]!=0 && seat[i+1][j]!=0 && seat[i][j+1]!=0) { i=j=0; break; }

        if(o==1 && seat[i+l][j]!=0)
        {
            o*=-1; l*=-1;
        }

        else if(o==-1 && seat[i][j+m]!=0)
        {
            o*=-1; m*=-1;
        }

        if(o==1) i+=l;
        else if(o==-1) j+=m;
    }
    if(i==0 && j==0) printf("0");
    else printf("%d %d",j,i);
    return 0;
}
