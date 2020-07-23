#include <stdio.h>
#define min(a,b)(a<b?a:b)
#define max(a,b)(a>b?a:b)

int map[105][105],safe[105][105],chk[105][105];

int main()
{
    freopen("input.txt","r",stdin);
    int n,i,j,l,k=0;
    int x,y,stackx[100005]={0},stacky[100005]={0},topx,topy,cnt,max,min=99999999,xy[100005]={0},txy;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&map[i][j]);
            k=max(k,map[i][j]);
            min=min(min,map[i][j]);
            safe[i][j]=1;
        }
    }
    max=0;
    for(l=min-1;l<k;l++)
    {
        cnt=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++) { if(map[i][j]<=l) safe[i][j]=0; chk[i][j]=0; }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(safe[i][j]==1 && chk[i][j]==0)
                {
                    x=i; y=j; chk[i][j]=topx=topy=txy=1;
                    while(topx>0 && topy>0)
                    {
                        if(safe[x-1][y]==1 && chk[x-1][y]==0)
                        {
                            stackx[topx++]=x; x--; chk[x][y]=1; xy[txy++]=1;
                        }
                        else if(safe[x][y+1]==1 && chk[x][y+1]==0)
                        {
                            stacky[topy++]=y; y++; chk[x][y]=1; xy[txy++]=0;
                        }
                        else if(safe[x+1][y]==1 && chk[x+1][y]==0)
                        {
                            stackx[topx++]=x; x++; chk[x][y]=1; xy[txy++]=1;
                        }
                        else if(safe[x][y-1]==1 && chk[x][y-1]==0)
                        {
                            stacky[topy++]=y; y--; chk[x][y]=1; xy[txy++]=0;
                        }
                        else if(xy[txy-1]==0)
                        {
                            y=stacky[--topy]; txy--;
                        }
                        else if(xy[txy-1]==1)
                        {
                            x=stackx[--topx]; txy--;
                        }
                    }
                    cnt++;
                }
            }
        }
        max=max(cnt,max);
    }
    printf("%d",max);
    return 0;
}
