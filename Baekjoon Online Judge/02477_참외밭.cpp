#include <stdio.h>

int data[10][5],c;

int f(int a,int b)
{
    if(a==1)
    {
        if(data[b-1][1]==4) { c=1; return data[b][2]*data[b-1][2]; }
    }
    else if(a==2)
    {
        if(data[b-1][1]==3) { c=1; return data[b][2]*data[b-1][2]; }
    }
    else if(a==3)
    {
        if(data[b-1][1]==1) { c=1; return data[b][2]*data[b-1][2]; }
    }
    else if(a==4)
    {
        if(data[b-1][1]==2) { c=1; return data[b][2]*data[b-1][2]; }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    int n,i,j,k,cnt[10]={0},S;
    scanf("%d",&n);
    for(i=1;i<=6;i++)
    {
        scanf("%d %d",&data[i][1],&data[i][2]);
        cnt[data[i][1]]+=data[i][2];
        if(c==0) k=f(data[i][1],i);
    }
    if(c==0) k=data[1][2]*data[6][2];
    S=cnt[1]*cnt[4]-k;
    printf("%d",S*n);
    return 0;
}
