#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MAX(a,b)(a>b?a:b)

struct koi
{
    int xa,xb,ya,yb;
};

koi data[55],tmp[105],tmp2[105],stack[105];

bool cmps(const koi &A,const koi &B)
{
    return A.ya<B.ya;
}

bool cmpb(const koi &A,const koi &B)
{
    return A.ya>B.ya;
}

int main(void)
{
    int n,i,j,k,top=1,a,b,x,y,res=0,max=0,cnt,c,d=-1,e,chk[55]={0};
    scanf("%d",&n);
    for(i=1;i<=n/2;i++) scanf("%d %d %d %d",&data[i].xa,&data[i].ya,&data[i].xb,&data[i].yb);
    for(i=1;i<=4;i++)
    {
        if(i==1) a=1; if(i==2) a=4; if(i==3) a=2; if(i==4) a=3;
        b=0;
        for(j=1;j<=n/2;j++)
        {
            if(data[j].xa==a) { tmp[++b].xa=data[j].xa; tmp[b].ya=data[j].ya; }
            if(data[j].xb==a) { tmp[++b].xa=data[j].xb; tmp[b].ya=data[j].yb; }
        }
        if(a==1 || a==4) std::sort(tmp+1,tmp+b+1,cmps);
        if(a==2 || a==3) std::sort(tmp+1,tmp+b+1,cmpb);
        a=b;
        for(b=1;b<=a;b++)
        {
            for(j=1;j<=n/2;j++)
            {
                if(data[j].xa==tmp[b].xa && data[j].ya==tmp[b].ya) { x=data[j].xb; y=data[j].yb; break; }
                if(data[j].xb==tmp[b].xa && data[j].yb==tmp[b].ya) { x=data[j].xa; y=data[j].ya; break; }
            }
            cnt=c=e=0;
            stack[top].xa=tmp[b].xa; stack[top++].ya=tmp[b].ya;
            for(k=top-2;k>=1;k--)
            {
                if(stack[k].xa==x && stack[k].ya==y)
                {
                    stack[top-1].xa=stack[top-1].ya=stack[k].xa=stack[k].ya=d--;
                    res+=cnt-c; cnt-=e; max=MAX(max,cnt); x=5; break;
                }
                else { cnt++; if(stack[k].xa<0 && chk[abs(stack[k].xa)]==1) e+=2; else if(stack[k].xa<0) chk[abs(stack[k].xa)]=1; if(stack[k].xa<0) c++; }
            }
            memset(chk,0,sizeof(chk));
        }
    }
    printf("%d\n%d",res,max);
}
