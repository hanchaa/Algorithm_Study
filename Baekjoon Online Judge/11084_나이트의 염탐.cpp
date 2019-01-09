#include <stdio.h>
#include <queue>
#define N 1000000009
using namespace std;
queue<long long> x,y;
struct koi{ long long x,y; }map[406][406];\
int chk[405][405];

int main(void)
{
    long long r,c,xx,yy;
    scanf("%lld %lld",&r,&c);
    map[1][1].x=1;
    x.push(1); y.push(1);
    chk[1][1]=1;
    while(!x.empty() && !y.empty())
    {
        xx=x.front(); yy=y.front(); x.pop(); y.pop();
        if(xx-2>0 && yy-1 >0)
        {
            if(map[xx-2][yy-1].y==0) { map[xx-2][yy-1].x=map[xx][yy].x%N; map[xx-2][yy-1].y=map[xx][yy].y+1; x.push(xx-2); y.push(yy-1); chk[xx-2][yy-1]=1; }
            else if(map[xx-2][yy-1].y==map[xx][yy].y+1 && chk[xx-2][yy-1]==0) { map[xx-2][yy-1].x=(map[xx-2][yy-1].x+map[xx][yy].x)%N; x.push(xx-2); y.push(yy-1); chk[xx-2][yy-1]=1; }
            else if(map[xx-2][yy-1].y==map[xx][yy].y+1 && chk[xx-2][yy-1]==1) { map[xx-2][yy-1].x=(map[xx-2][yy-1].x+map[xx][yy].x)%N; }
        }
        if(xx-2>0 && yy+1 <=c)
        {
            if(map[xx-2][yy+1].y==0) { map[xx-2][yy+1].x=map[xx][yy].x%N; map[xx-2][yy+1].y=map[xx][yy].y+1; x.push(xx-2); y.push(yy+1); chk[xx-2][yy+1]=1; }
            else if(map[xx-2][yy+1].y==map[xx][yy].y+1 && chk[xx-2][yy+1]==0) { map[xx-2][yy+1].x=(map[xx-2][yy+1].x+map[xx][yy].x)%N; x.push(xx-2); y.push(yy+1); chk[xx-2][yy+1]=1; }
            else if(map[xx-2][yy+1].y==map[xx][yy].y+1 && chk[xx-2][yy+1]==1) { map[xx-2][yy+1].x=(map[xx-2][yy+1].x+map[xx][yy].x)%N; }
        }
        if(xx+2<=r && yy-1 >0)
        {
            if(map[xx+2][yy-1].y==0) { map[xx+2][yy-1].x=map[xx][yy].x%N; map[xx+2][yy-1].y=map[xx][yy].y+1; x.push(xx+2); y.push(yy-1); chk[xx+2][yy-1]=1; }
            else if(map[xx+2][yy-1].y==map[xx][yy].y+1 && chk[xx+2][yy-1]==0) { map[xx+2][yy-1].x=(map[xx+2][yy-1].x+map[xx][yy].x)%N; x.push(xx+2); y.push(yy-1); chk[xx+2][yy-1]=1; }
            else if(map[xx+2][yy-1].y==map[xx][yy].y+1 && chk[xx+2][yy-1]==1) { map[xx+2][yy-1].x=(map[xx+2][yy-1].x+map[xx][yy].x)%N; }
        }
        if(xx+2<=r && yy+1 <=c)
        {
            if(map[xx+2][yy+1].y==0) { map[xx+2][yy+1].x=map[xx][yy].x%N; map[xx+2][yy+1].y=map[xx][yy].y+1; x.push(xx+2); y.push(yy+1); chk[xx+2][yy+1]=1; }
            else if(map[xx+2][yy+1].y==map[xx][yy].y+1 && chk[xx+2][yy+1]==0) { map[xx+2][yy+1].x=(map[xx+2][yy+1].x+map[xx][yy].x)%N; x.push(xx+2); y.push(yy+1); chk[xx+2][yy+1]=1; }
            else if(map[xx+2][yy+1].y==map[xx][yy].y+1 && chk[xx+2][yy+1]==1) { map[xx+2][yy+1].x=(map[xx+2][yy+1].x+map[xx][yy].x)%N; }
        }
        if(xx-1>0 && yy-2 >0)
        {
            if(map[xx-1][yy-2].y==0) { map[xx-1][yy-2].x=map[xx][yy].x%N; map[xx-1][yy-2].y=map[xx][yy].y+1; x.push(xx-1); y.push(yy-2); chk[xx-1][yy-2]=1; }
            else if(map[xx-1][yy-2].y==map[xx][yy].y+1 && chk[xx-1][yy-2]==0) { map[xx-1][yy-2].x=(map[xx-1][yy-2].x+map[xx][yy].x)%N; x.push(xx-1); y.push(yy-2); chk[xx-1][yy-2]=1; }
            else if(map[xx-1][yy-2].y==map[xx][yy].y+1 && chk[xx-1][yy-2]==1) { map[xx-1][yy-2].x=(map[xx-1][yy-2].x+map[xx][yy].x)%N; }
        }
        if(xx-1>0 && yy+2 <=c)
        {
            if(map[xx-1][yy+2].y==0) { map[xx-1][yy+2].x=map[xx][yy].x%N; map[xx-1][yy+2].y=map[xx][yy].y+1; x.push(xx-1); y.push(yy+2); chk[xx-1][yy+2]=1; }
            else if(map[xx-1][yy+2].y==map[xx][yy].y+1 && chk[xx-1][yy+2]==0) { map[xx-1][yy+2].x=(map[xx-1][yy+2].x+map[xx][yy].x)%N; x.push(xx-1); y.push(yy+2); chk[xx-1][yy+2]=1; }
            else if(map[xx-1][yy+2].y==map[xx][yy].y+1 && chk[xx-1][yy+2]==1) { map[xx-1][yy+2].x=(map[xx-1][yy+2].x+map[xx][yy].x)%N; }
        }
        if(xx+1<=r && yy-2 >0)
        {
            if(map[xx+1][yy-2].y==0) { map[xx+1][yy-2].x=map[xx][yy].x%N; map[xx+1][yy-2].y=map[xx][yy].y+1; x.push(xx+1); y.push(yy-2); chk[xx+1][yy-2]=1; }
            else if(map[xx+1][yy-2].y==map[xx][yy].y+1 && chk[xx+1][yy-2]==0) { map[xx+1][yy-2].x=(map[xx+1][yy-2].x+map[xx][yy].x)%N; x.push(xx+1); y.push(yy-2); chk[xx+1][yy-2]=1; }
            else if(map[xx+1][yy-2].y==map[xx][yy].y+1 && chk[xx+1][yy-2]==1) { map[xx+1][yy-2].x=(map[xx+1][yy-2].x+map[xx][yy].x)%N; }
        }
        if(xx+1<=r && yy+2 <=c)
        {
            if(map[xx+1][yy+2].y==0) { map[xx+1][yy+2].x=map[xx][yy].x%N; map[xx+1][yy+2].y=map[xx][yy].y+1; x.push(xx+1); y.push(yy+2); chk[xx+1][yy+2]=1; }
            else if(map[xx+1][yy+2].y==map[xx][yy].y+1 && chk[xx+1][yy+2]==0) { map[xx+1][yy+2].x=(map[xx+1][yy+2].x+map[xx][yy].x)%N; x.push(xx+1); y.push(yy+2); chk[xx+1][yy+2]=1; }
            else if(map[xx+1][yy+2].y==map[xx][yy].y+1 && chk[xx+1][yy+2]==1) { map[xx+1][yy+2].x=(map[xx+1][yy+2].x+map[xx][yy].x)%N; }
        }
    }
    if(map[r][c].x==0) { printf("None"); return 0; }
    printf("%lld %lld",map[r][c].y,map[r][c].x%N);
}
