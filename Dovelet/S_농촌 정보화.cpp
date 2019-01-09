#include <stdio.h>
#include <algorithm>

int ho[105][105],t[105];

struct AAA
{
    int x,y,z;
};

AAA heap[10000];

bool cmp(const AAA &a, const AAA &b)
{
    if(a.z!=b.z) return a.z < b.z;
    else return a.x < b.x;

}

int f(int a)
{
    if(a==t[a]) return a;
    else return t[a]=f(t[a]);
}

int main()
{
    freopen("input.txt","r",stdin);
    int n,m,i,j,k,sum=0,aa,bb;
    scanf("%d",&n);
    m=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&ho[i][j]);
            if(i<j){ heap[m].z=ho[i][j]; heap[m].x=j; heap[m++].y=i;}
        }
        t[i]=i;
    }
    std::sort(heap+1,heap+m,cmp);
    for(i=1;i<m;i++)
    {
        aa=f(heap[i].y);
        bb=f(heap[i].x);
        if(aa!=bb) { t[bb]=t[aa]; sum+=heap[i].z; }
    }
    printf("%d",sum);
    return 0;
}
