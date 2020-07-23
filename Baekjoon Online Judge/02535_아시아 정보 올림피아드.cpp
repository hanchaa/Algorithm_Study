#include <stdio.h>
#include <algorithm>

struct AAA
{
    int a; int b; int c;
};

AAA data[105];

bool cmp(const AAA &A, const AAA &B)
{
    return A.c>B.c;
}

int main()
{
    freopen("input.txt","r",stdin);
    int n,i,j,k,chk[105]={0},cnt=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&data[i].a,&data[i].b,&data[i].c);
    }
    std::sort(data+1,data+n+1,cmp);
    i=1;
    while(cnt!=3)
    {
        if(chk[data[i].a]==2) {i++; continue;}
        chk[data[i].a]++;
        printf("%d %d\n",data[i].a,data[i].b);
        cnt++; i++;
    }

    return 0;
}
