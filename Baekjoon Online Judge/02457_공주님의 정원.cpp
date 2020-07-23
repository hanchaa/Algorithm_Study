#include <stdio.h>

int main()
{
    freopen("input.txt","r",stdin);
    int n,i,j=0,k,cnt=0,date[13]={0,31,59,90,120,151,181,212,243,273,304,334,365},sm,sd,fm,fd,sday[100005]={0},fday[100005]={0};
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&sm,&sd,&fm,&fd);
        sday[i]=date[sm-1]+sd;
        fday[i]=date[fm-1]+fd;
    }
    k=60;
    while(1)
    {
        if(k>334) break;
        for(i=1;i<=n;i++)
        {
            if(sday[i]<=k && j<fday[i]) j=fday[i];
        }
        if(j<=k) {cnt=0; break;}
        k=j; cnt++;
    }
    printf("%d",cnt);
    return 0;
}
