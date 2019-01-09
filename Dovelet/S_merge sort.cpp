#include <stdio.h>

int data[105],temp[105],m;

int merge(int l,int r)
{
    int x,y,i=1,j;

    if(l+2>=r)
    {
        for(i=l;i<=r;i++)
        {
            for(j=l;j<r;j++)
            {
                if(data[j]>data[j+1])
                {
                    m=data[j+1]; data[j+1]=data[j]; data[j]=m;
                }
            }
        }
    }
    else
    {
        merge(l,(l+r)/2);
        merge((l+r)/2+1,r);
        x=l; y=(l+r)/2+1;
        for(j=l;j<=r;j++)
        {
            if(y>r) temp[j]=data[x++];
            else if(x>=(l+r)/2+1) temp[j]=data[y++];
            else if(data[x]<=data[y]) temp[j]=data[x++];
            else if(data[y]<data[x]) temp[j]=data[y++];
        }
        for(j=l;j<=r;j++) data[j]=temp[j];
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&data[i]);
    }
    merge(1,n);
    for(i=1;i<=n;i++) printf("%d ",data[i]);
    return 0;
}
