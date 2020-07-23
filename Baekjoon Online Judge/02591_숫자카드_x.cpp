#include <stdio.h>
#include <string.h>

int t[45],data[45];

char data2[45];

int main(void)
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,i,j=1,k;
    scanf("%s",data2);
    k=strlen(data2);
    for(i=1;i<=k;i++) data[i]=data2[i-1]-48;
    t[0]=1;
    for(i=1;i<=k;i++)
    {
        t[j]=t[j-1];
        if(data[i-1]*10+data[i]<=34 && (data[i-1]*10+data[i])%10==0) t[--j]=t[j-1];
        else if(data[i]!=0 && data[i-1]!=0 && data[i-1]*10+data[i]<=34) t[j]=t[j-2]+t[j-1];
        j++;
    }
    printf("%d",t[j-1]);
}
