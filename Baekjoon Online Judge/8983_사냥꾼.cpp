#include <stdio.h>
#include <algorithm>

struct AAA
{
    int p;//x좌표
    int q;//y좌표
};

AAA data[100005];

bool cmp(const AAA &A,const AAA &B)
{
    return A.p < B.p;
}

int main()
{
    freopen("input.txt","r",stdin);
    int m,n,l,i,j,k,hunt[100005]={0},cnt=0,temp;

    scanf("%d %d %d",&m,&n,&l);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&hunt[i]);
    }
    hunt[i]=2100000000;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&data[i].p,&data[i].q);
    }
    std::sort(hunt+1,hunt+m+1);
    std::sort(data+1,data+n+1,cmp);
    j=1;
    for(i=1;i<=n;i++)
    {
        if(data[i].p>hunt[j+1]) { j++; i--; continue; }
        temp=data[i].p-hunt[j]; if(temp<0) temp*=-1;
        temp+=data[i].q;
        if(temp<=l) { cnt++; continue; }
        temp=data[i].p-hunt[j+1]; if(temp<0) temp*=-1;
        temp+=data[i].q;
        if(temp<=l) { cnt++; continue; }
    }
    printf("%d",cnt);
    return 0;
}
