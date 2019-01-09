#include <stdio.h>

int tomato[1005][1005];

struct koi
{
    int x;
    int y;
};

koi que[10000005];

int main()
{
    freopen("input.txt","r",stdin);
    int n,m,i,j,k,l=0,front=1,rear=1,cnt=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&tomato[i][j]);
            if(tomato[i][j]==1) { que[rear].x=i; que[rear++].y=j; }
            if(tomato[i][j]==0) l=1;
        }
    }

    while(front<rear && l==1)
    {
        k=rear;
        for(front=front;front<k;front++)
        {
            if(tomato[que[front].x][que[front].y+1]==0 && que[front].y+1<=n)
            {
                que[rear].y=que[front].y+1;
                que[rear++].x=que[front].x;
                tomato[que[rear-1].x][que[rear-1].y]=1;
            }
            if(tomato[que[front].x+1][que[front].y]==0 && que[front].x+1<=m)
            {
                que[rear].x=que[front].x+1;
                que[rear++].y=que[front].y;
                tomato[que[rear-1].x][que[rear-1].y]=1;
            }
            if(tomato[que[front].x][que[front].y-1]==0 && que[front].y-1>0)
            {
                que[rear].y=que[front].y-1;
                que[rear++].x=que[front].x;
                tomato[que[rear-1].x][que[rear-1].y]=1;
            }
            if(tomato[que[front].x-1][que[front].y]==0 && que[front].x-1>0)
            {
                que[rear].x=que[front].x-1;
                que[rear++].y=que[front].y;
                tomato[que[rear-1].x][que[rear-1].y]=1;
            }

        }
        cnt++;
    }
    cnt--;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(tomato[i][j]==0) { cnt=-1; break; }
        }
        if(j<=m) break;
    }
    printf("%d",cnt);
    return 0;
}
