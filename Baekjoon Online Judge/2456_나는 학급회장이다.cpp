#include <stdio.h>

int main()
{
    freopen("input.txt","r",stdin);
    int n,i,j,A,B,C,cnt[4]={0},high=0,boss,score[4][4]={0};
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&A,&B,&C);
        score[1][A]++; score[2][B]++; score[3][C]++;
        cnt[1]+=A; cnt[2]+=B; cnt[3]+=C;
    }
    C=0;
    j=0;
    if(cnt[1]==cnt[2] && cnt[2]==cnt[3] && score[1][3]==score[2][3] && score[2][3]==score[3][3] && score[1][2]==score[2][2] && score[2][2]==score[3][2]) C=1;
    for(i=1;i<=3;i++)
    {
        if(high==cnt[i]) j=i;
        if(cnt[i]>high) { high=cnt[i]; boss=i; }
    }
    if(score[boss][3]<score[j][3]) boss=j;
    else if(score[boss][3]==score[j][3] && score[boss][2]<score[j][2]) boss=j;
    else if(score[boss][3]==score[j][3] && score[boss][2]==score[j][2]) C=1;
    if(C==1) printf("%d %d",0,high);
    else printf("%d %d",boss,high);
    return 0;
}
