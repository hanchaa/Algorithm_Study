#include <stdio.h>

int main()
{
    //freopen("input.txt","r",stdin);
    int n,data[1005]={0},i,j,k,l,temp;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&data[i]);
        j=i; l=i;
        while(j>1)
        {
            j=j/2;
            if(data[l]>data[j])
            {
                k=data[l];
                data[l]=data[j];
                data[j]=k;
            }
            l=j;
        }
    }
    for(i=1;i<=n;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    k=n;
    for(i=1;i<=3;i++)
    {
        data[1]=data[k];
        data[k]=0; k--;
        j=1; l=1;
        while(1)
        {
            j*=2;
            if(j>k) break;
            if(data[j+1]==0)
            {
                if(data[j]>data[l])
                {
                    temp=data[j];
                    data[j]=data[l];
                    data[l]=temp;
                }
                else break;
            }
            if(data[j]>=data[j+1])
            {
                if(data[j]>data[l])
                {
                    temp=data[j];
                    data[j]=data[l];
                    data[l]=temp;
                }
                else break;
            }
            else
            {
                if(data[j+1]>data[l] && data[j+1]!=0)
                {
                    temp=data[j+1];
                    data[j+1]=data[l];
                    data[l]=temp;
                    j++;
                }
                else break;
            }
            l=j;
        }
    }
    for(i=1;i<=k;i++)
    {
        printf("%d ",data[i]);
    }
    return 0;
}
