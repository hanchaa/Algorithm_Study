#include <stdio.h>
#define MAX(a,b)(a>b?a:b)

int data[35000],chk[3005],que[35000];

int main()
{
    freopen("input.txt","r",stdin);
    int n,i,j,k,l,c,d,cnt,max,f,r;
    scanf("%d %d %d %d",&n,&d,&k,&c);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&data[i]);
    }
    for(i=n+1;i<=n+k;i++)
    {
        data[i]=data[i-n];
    }

    cnt=1; chk[c]=1;
    f=r=0;
    for(i=1;i<=k;i++)
    {
        if(chk[data[i]]==0) { cnt++; chk[data[i]]++; que[r++]=data[i]; }
        else if(chk[data[i]]>0) { chk[data[i]]++; que[r++]=data[i]; }
    }
    max=cnt;
    for(i=k+1;i<=n+k;i++)
    {
        if(chk[data[i-k]]<2) cnt--;
        chk[que[f++]]--;
        if(chk[data[i]]==0) { cnt++; chk[data[i]]++; que[r++]=data[i]; }
        else if(chk[data[i]]>0) { chk[data[i]]++; que[r++]=data[i]; }
        max=MAX(max,cnt);
    }

    printf("%d",max);

    return 0;
}
