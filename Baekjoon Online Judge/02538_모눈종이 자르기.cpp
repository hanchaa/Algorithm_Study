#include <stdio.h>
#include <algorithm>
#define MAX(a,b)(a>b?a:b)

int cnt[1000000],data[500005][5],a[3],b[3],n,m,chk[5];

void f(int x,int y,int j,int k)
{
    if(a[1]==x && (x==0||x==n)) cnt[j]+=abs(a[2]-y);
    else if(a[2]==y && (y==0||y==m)) cnt[j]+=abs(a[1]-x);
    else if(k==1) { cnt[j]+=a[1]+m-y; if(chk[4]==0) cnt[j]+=m-a[2]; }
    else if(k==2) { cnt[j]+=a[2]+x; if(chk[1]==0) cnt[j]+=a[1]; }
    else if(k==3) { cnt[j]+=n-a[1]+y; if(chk[2]==0) cnt[j]+=a[2]; }
    else if(k==4) { cnt[j]+=m-a[2]+n-x; if(chk[3]==0) cnt[j]+=n-a[1]; }
}

int main(void)
{
    freopen("input.txt","r",stdin);
    int i,j=1,k,c,max=0,t=0,l=0;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=k;i++) scanf("%d %d",&data[i][1],&data[i][2]);
    data[k+1][1]=data[1][1]; data[k+1][2]=data[1][2];
    for(i=1;i<=k+1;i++)
    {
        c=0;
        if(data[i][1]==0)
        {
            c=t=1;
            chk[1]=1;
            if(l==0) { b[1]=a[1]=data[i][1]; b[2]=a[2]=data[i][2]; l=1; }
            if(data[i-1][1]==0)
            {
                if(data[i-1][2]!=m && i>2) j++;
                a[1]=data[i][1];
                a[2]=data[i][2];
            }
            else if(data[i][2]==data[i-1][2] && data[i][2]!=m) f(data[i][1],data[i][2],j,1);
            if(data[i-1][1]!=0 && data[i][2]!=m && i>1) cnt[j]+=abs(data[i][1]-data[i-1][1])+abs(data[i][2]-data[i-1][2]);
        }
        if(data[i][1]==n)
        {
            c=t=1;
            chk[3]=1;
            if(l==0) { b[1]=a[1]=data[i][1]; b[2]=a[2]=data[i][2]; l=3; }
            if(data[i-1][1]==n)
            {
                if(data[i-1][2]!=0 && i>2) j++;
                a[1]=data[i][1];
                a[2]=data[i][2];
            }
            else if(data[i][2]==data[i-1][2] && data[i][2]!=0) f(data[i][1],data[i][2],j,3);
            if(data[i-1][1]!=n && data[i][2]!=0 && i>1) cnt[j]+=abs(data[i][1]-data[i-1][1])+abs(data[i][2]-data[i-1][2]);
        }
        if(data[i][2]==0)
        {
            c=t=1;
            chk[2]=1;
            if(l==0) { b[1]=a[1]=data[i][1]; b[2]=a[2]=data[i][2]; l=2; }
            if(data[i-1][2]==0)
            {
                if(data[i-1][1]!=0 && i>2) j++;
                a[1]=data[i][1];
                a[2]=data[i][2];
            }
            else if(data[i][1]==data[i-1][1] && data[i][1]!=0) f(data[i][1],data[i][2],j,2);
            if(data[i-1][2]!=0 && data[i][1]!=0 && i>1) cnt[j]+=abs(data[i][1]-data[i-1][1])+abs(data[i][2]-data[i-1][2]);
        }
        if(data[i][2]==m)
        {
            c=t=1;
            chk[4]=1;
            if(l==0) { b[1]=a[1]=data[i][1]; b[2]=a[2]=data[i][2]; l=4; }
            if(data[i-1][2]==m)
            {
                if(data[i-1][1]!=n && i>2) j++;
                a[1]=data[i][1];
                a[2]=data[i][2];
            }
            else if(data[i][1]==data[i-1][1] && data[i][1]!=n) f(data[i][1],data[i][2],j,4);
            if(data[i-1][2]!=m && data[i][1]!=n && i>1) cnt[j]+=abs(data[i][1]-data[i-1][1])+abs(data[i][2]-data[i-1][2]);
        }
        if(c==0 && i>1) cnt[j]+=abs(data[i][1]-data[i-1][1])+abs(data[i][2]-data[i-1][2]);
        max=MAX(max,cnt[j]);
        if(i==k+1)
        {
            if(c==0) f(b[1],b[2],j,l);
            if(t==1) { cnt[1]+=cnt[j]; j--; }
            else cnt[1]+=2*(m+n);
        }
    }
    printf("%d %d",j,MAX(max,cnt[1]));
}
