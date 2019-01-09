#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
#define N 1000010

using namespace std;

struct P
{
    int x,y;
    bool operator>(P right) const
    {
        return x>right.x;
    }
    bool operator<(P right) const
    {
        return x<right.x;
    }
}data[N],b;

int chk[N];
priority_queue<P> M;
priority_queue<P, vector<P>, greater<P> > m;

int main(void)
{
    freopen("input.txt","r",stdin);
    int n,i,k,t,tt,tp; char a;
    scanf("%d",&t);
    for(tt=1;tt<=t;tt++)
    {
        memset(chk,0,sizeof(chk));
        scanf("%d",&k);
        tp=0;
        for(i=1;i<=k;i++)
        {
            scanf("\n %c",&a);
            if(a=='I')
            {   scanf("%d",&data[++tp].x); data[tp].y=tp; M.push(data[tp]); m.push(data[tp]); }
            if(a=='D')
            {
                scanf("%d",&n);
                if(n==1)
                {
                    while(!M.empty())
                    {
                        b=M.top();
                        if(chk[b.y]==0) { chk[b.y]=1; M.pop(); break; }
                        M.pop();
                    }
                }
                if(n==-1)
                {
                    while(!m.empty())
                    {
                        b=m.top();
                        if(chk[b.y]==0) { chk[b.y]=1; m.pop(); break; }
                        m.pop();
                    }
                }
            }
        }
        n=0;
        while(!M.empty())
        {
            b=M.top();
            if(chk[b.y]==0 && n==0) { printf("%d",b.x); n=1; }
            M.pop();
        } n=0;
        while(!m.empty())
        {
            b=m.top();
            if(chk[b.y]==0 && n==0) { printf(" %d\n",b.x); n=1; }
            m.pop();
        }
        if(n==0 && M.empty() && m.empty()) printf("EMPTY\n");
    }
}
