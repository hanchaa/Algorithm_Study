#include <stdio.h>
 
int map[105][105][105];
 
struct koi
{
    int x,y,z;
};
 
koi que[1000005];
 
int main(void)
{
    int n,i,j,k,m,h,chk=0,f=1,r=1,cnt=0;
    scanf("%d %d %d",&m,&n,&h);
    for(i=1;i<=h;i++){for(j=1;j<=n;j++){for(k=1;k<=m;k++){scanf("%d",&map[i][j][k]);if(map[i][j][k]==0) chk=1; if(map[i][j][k]==1) { que[r].x=k; que[r].y=j; que[r++].z=i; }}}}
    if(chk==0) { printf("0"); return 0;}
    while(f<r)
    {
        j=r;
        for(f=f;f<j;f++)
        {
            if(map[que[f].z][que[f].y][que[f].x+1]==0 && que[f].x+1<=m) { que[r].x=que[f].x+1; que[r].y=que[f].y; que[r++].z=que[f].z; map[que[f].z][que[f].y][que[f].x+1]=1; }
            if(map[que[f].z][que[f].y][que[f].x-1]==0 && que[f].x-1>=1) { que[r].x=que[f].x-1; que[r].y=que[f].y; que[r++].z=que[f].z; map[que[f].z][que[f].y][que[f].x-1]=1; }
            if(map[que[f].z][que[f].y+1][que[f].x]==0 && que[f].y+1<=n) { que[r].x=que[f].x; que[r].y=que[f].y+1; que[r++].z=que[f].z; map[que[f].z][que[f].y+1][que[f].x]=1; }
            if(map[que[f].z][que[f].y-1][que[f].x]==0 && que[f].y-1>=1) { que[r].x=que[f].x; que[r].y=que[f].y-1; que[r++].z=que[f].z; map[que[f].z][que[f].y-1][que[f].x]=1; }
            if(map[que[f].z+1][que[f].y][que[f].x]==0 && que[f].z+1<=h) { que[r].x=que[f].x; que[r].y=que[f].y; que[r++].z=que[f].z+1; map[que[f].z+1][que[f].y][que[f].x]=1; }
            if(map[que[f].z-1][que[f].y][que[f].x]==0 && que[f].z-1>=1) { que[r].x=que[f].x; que[r].y=que[f].y; que[r++].z=que[f].z-1; map[que[f].z-1][que[f].y][que[f].x]=1; }
        }
        cnt++;
    }
    for(i=1;i<=h;i++) for(j=1;j<=n;j++) for(k=1;k<=m;k++) { if(map[i][j][k]==0) { printf("-1"); return 0; } }
    printf("%d",cnt-1);
}