#include <stdio.h>

int data[100],s,n,cnt;

int f(int a)
{
    int b=0,i,j,k;
    if(a==n+1) { for(i=1;i<=n;i++) printf("%d",data[i]); return 0; }
    for(i=1;i<=3;i++)
    {
        data[a]=i;
        for(j=1;j<=a/2;j++)
        {
            cnt=0;
            for(k=0;k<j;k++)
            {
                if(data[a-j-k]==data[a-k]) cnt++;
            }
            if(cnt==j) break;
        }
        if(j<=a/2) continue;
        b=f(a+1);
        if(b==1) continue;
        break;
    }
    if(i>3) return 1;
}

int main(void)
{
    scanf("%d",&n);
    f(s+1);
}
