#include <stdio.h>

int jinsu[50][100],d;

int f(long long a,int c)
{
    if(a==1 || a==0) { jinsu[1][c]=a; d=c; return 0; }
    f(a/2,c+1);
    jinsu[1][c]=a%2;
}

int main()
{
    int i,j,l,A=1,cnt=0;
    long long n,m,k;
    scanf("%lld",&n);
    f(n,1);
    k=0;
    for(i=1;i<=d;i++)
    {
        jinsu[2][i]=jinsu[3][i]=jinsu[1][i];
        if(jinsu[1][i]==0) A=0;
        if(jinsu[1][i]==1) cnt++;
    }
    if(A==0)
    {
        for(i=1;1<=d;i++)
        {
            if(jinsu[3][i]==0 && k==0 ) { j=i; k=1; }
            if(jinsu[3][i]==1 && k==1 )
            {
                l=jinsu[3][i];
                jinsu[3][i]=jinsu[3][j];
                jinsu[3][j]=l;
                j=i-1;
                break;
            }
        }
        k=1;
        while(1)
        {
            m=0;
            for(i=k;i<=j;i++)
            {
                if(jinsu[3][i]==1 && m==0 ) { n=i; m=1; }
                if(jinsu[3][i]==0 && m==1 )
                {
                    l=jinsu[3][i];
                    jinsu[3][i]=jinsu[3][n];
                    jinsu[3][n]=l;
                    break;
                }
            }
            k++;
            if(i>j) break;
        }
    }
    l=0;
    if(A==1)
    {
        m=0; jinsu[3][1]=0; l=1;
    }
    k=1;
    m=0;
    if(jinsu[3][1]==1) m=1;
    if(l==0)
    {
        for(i=2;i<=d+A;i++)
        {
            k*=2;
            if(jinsu[3][i]==1) m+=k;
        }
    }
    k=0;
    printf("%lld ",m);
    if(A==0 && cnt>1)
    {
        for(i=1;1<=d+1;i++)
        {
            if(jinsu[2][i]==1 && k==0 ) { j=i; k=1; }
            if(jinsu[2][i]==0 && k==1 )
            {
                l=jinsu[2][i];
                jinsu[2][i]=jinsu[2][j];
                jinsu[2][j]=l;
                j=i-1;
                break;
            }
        }
        k=1;
        while(1)
        {
            m=0;
            for(i=k;i<=j;i++)
            {
                if(jinsu[2][i]==0 && m==0 ) { n=i; m=1; }
                if(jinsu[2][i]==1 && m==1 )
                {
                    l=jinsu[2][i];
                    jinsu[2][i]=jinsu[2][n];
                    jinsu[2][n]=l;
                    break;
                }
            }
            k++;
            if(i>j) break;
        }
    }
    if(A==1 && cnt>1)
    {
        jinsu[2][d+1]=1; jinsu[2][d]=0;
    }
    if(A==0 && cnt==1)
    {
        jinsu[2][d+1]=1; jinsu[2][d]=0; A=1;
    }
    k=1;
    m=0;
    if(jinsu[2][1]==1) m=1;
    for(i=2;i<=d+5;i++)
    {
        k*=2;
        if(jinsu[2][i]==1) m+=k;
    }
    printf("%lld",m);

    return 0;
}
