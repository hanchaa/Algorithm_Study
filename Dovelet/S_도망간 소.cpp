#include <stdio.h>

//18

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i,j,que[200010]={0},n,k,chk[200010]={0},cnt[200010]={0},rear=0,front=0;
    scanf("%d %d",&n,&k);
    que[rear]=n;
    chk[n]=1;
    while(cnt[k]==0)
    {
        if(n>k) {printf("%d",n-k); break;}
        if(n==k) {printf("0"); break;}
        if(chk[que[front]+1]==0)
        {
            que[++rear]=que[front]+1;
            chk[que[rear]]=1;
            cnt[que[rear]]=cnt[que[front]]+1;
        }
        if(que[front]>0)
        {
            if(chk[que[front]-1]==0)
            {
                que[++rear]=que[front]-1;
                chk[que[rear]]=1;
                cnt[que[rear]]=cnt[que[front]]+1;
            }
        }
        if(que[front]<k)
        {
            if(chk[que[front]*2]==0)
            {
                que[++rear]=que[front]*2;
                chk[que[rear]]=1;
                cnt[que[rear]]=cnt[que[front]]+1;
            }
        }
        front++;
    }
    if(n<k) printf("%d",cnt[k]);
    return 0;
}
