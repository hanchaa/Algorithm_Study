#include <stdio.h>

int main()
{
    FILE *fi=fopen("input.txt","r");
    FILE *fw=fopen("output.txt","w");
    int n,sco[305]={0},i,j,k,cnt=1,sum[305]={0},max;
    fscanf(fi,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(fi,"%d",&sco[i]);
    }
    sum[1]=sco[1];
    sum[2]=sco[2]+sum[1];
    for(i=3;i<=n;i++)
    {
        sum[i]=sco[i]+sum[i-2];
        if(sco[i]+sco[i-1]+sum[i-3]>sum[i]) sum[i]=sco[i]+sco[i-1]+sum[i-3];
    }
    fprintf(fw,"%d",sum[n]);
}
