#include <stdio.h>
#define min(a,b)(a<b?a:b)

int data[5000005];

int main()
{
    freopen("input.txt","r",stdin);
    int max=0,n,i,j,l,data2[10005]={0},temp1,temp2;
    double k=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&data[i]);
        if(data[i]>max) max=data[i];
        data2[data[i]]++;
        k+=data[i];
    }
    k=k/n;
    j=1;
    for(i=1;i<=max;i++)
    {
        for(l=1;l<=data2[i];l++)
        {
            data[j++]=i;
        }
    }
    j=0; l=0;
    if(k>(int)k)
    {
        temp1=(int)k; temp2=(int)k+1;
        for(i=1;i<=n;i++)
        {
            j+=(data[i]-temp1)*(data[i]-temp1);
            l+=(data[i]-temp2)*(data[i]-temp2);
        }
        if(j<=l) j=temp1;
        else j=temp2;
    }
    else j=k;
    printf("%d %d",data[(1+n)/2],j);
    return 0;
}
