#include <stdio.h>

int main()
{
    int map[105][105]={0},chk[105]={0},i,j,k,n,m,st[105]={0},top=0,cnt=0;
    scanf("%d %d",&n,&m);
    for(k=0;k<m;k++)
    {
        scanf("%d %d",&i,&j);
        map[i][j]=map[j][i]=1;
    }

    st[++top]=i=chk[1]=1;
    while(top>0)
    {
        for(j=1;j<=n;j++)
        {
            if(map[i][j]==1 && chk[j]==0)
            {
                cnt++;
                chk[j]=1;
                st[++top]=j;
                i=j;
                break;
            }
        }
        if(j>n)
        {
            i=st[--top];
        }
    }
    printf("%d",cnt);
    return 0;
}
