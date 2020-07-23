#include <stdio.h>
#include <algorithm>
#define pow(a)(a*a)

int data[15][15];

struct koi
{
    int x; int y;
};

koi res[105];

bool cmp(const koi &A,const koi &B)
{
    if(A.x==B.x) return A.y<B.y;
    else return A.x<B.x;
}

int main()
{
    freopen("input.txt","r",stdin);
    int n=0,i,j,k=1,tmp,t,gok[5]={0},max=0,a,b;
    for(i=1;i<=10;i++) for(j=1;j<=10;j++) scanf("%1d",&data[i][j]);
    for(i=1;i<=10;i++)
    {
        for(j=1;j<=10;j++)
        {
            tmp=t=0;
            if(data[i][j]==0 && data[i-1][j]==1 && data[i+1][j]==1 && data[i][j-1]==1 && data[i][j+1]==1) { n=1; break; }
            if(data[i][j]==0) continue;
            if(data[i-1][j]==0) tmp++; if(data[i-1][j]==1) t++;
            if(data[i+1][j]==0) tmp++; if(data[i+1][j]==1) t++;
            if(data[i][j-1]==0) tmp++; if(data[i][j-1]==1) t++;
            if(data[i][j+1]==0) tmp++; if(data[i][j+1]==1) t++;
            if(data[i-1][j-1]==1) t++; if(data[i-1][j+1]==1) t++;
            if(data[i+1][j-1]==1) t++; if(data[i+1][j+1]==1) t++;
            if(tmp==3) { res[k].x=i; res[k++].y=j; }
            if(tmp==2 && t==3) {res[k].x=i; res[k++].y=j; }
        }
        if(n==1) break;
    }
    if(k!=4 || n==1) { printf("0"); return 0; }
    gok[1]=pow(abs(res[1].x-res[2].x))+pow(abs(res[1].y-res[2].y));
    gok[2]=pow(abs(res[1].x-res[3].x))+pow(abs(res[1].y-res[3].y));
    gok[3]=pow(abs(res[2].x-res[3].x))+pow(abs(res[2].y-res[3].y));
    for(i=1;i<=3;i++)
    {
        if(gok[i]>max) { max=gok[i]; k=i; }
    }
    j=0;
    for(i=1;i<=3;i++)
    {
        if(i==k) continue;
        if(a==gok[i]) a=1;
        else a=gok[i];
        j+=gok[i];
    }
    if(a!=1 && j!=gok[k]) { printf("0"); return 0; }
    std::sort(res+1,res+4,cmp);
    for(i=1;i<=3;i++)
    {
        printf("%d %d\n",res[i].x,res[i].y);
    }
}
