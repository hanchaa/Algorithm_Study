#include <stdio.h>

int main()
{
    int data[11]={0},cnt[101]={0},i,sum=0,max=0,max2=0;
    for(i=1;i<=10;i++)
    {
        scanf("%d",&data[i]);
        sum+=data[i];
    }

    sum=sum/10;

    for(i=1;i<=10;i++)
    {
        cnt[data[i]/10]++;
    }

    for(i=1;i<=100;i++)
    {
        if(cnt[i]>max) { max=cnt[i]; max2=i*10; }
    }

    printf("%d\n%d",sum,max2);
    return 0;
}
