#include <stdio.h>

int check[105][105]={0};

void F(int i, int j)
{
    if(i<j) return;

    if(check[i][j]==-1)
    {
        printf("%d %d\n",j,i);
        F(i-1,j+1);
    }
    else
    {
        F(check[i][j],j);
        F(i,check[i][j]+1);
    }
}
int main()
{
    freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
    int data[105]={0},map[105][105]={0},hei[105][105]={0},i,j,k,n,wh,bl;
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%1d",&data[i]);
        for(j=1;j<=n;j++)
        {
            map[i][j]=0;
         }
    }
    for(i=2;i<=n;i++)
    {
        for(j=i-1;j>=1;j--)
        {
            wh=bl=0;
            for(k=i;k>=j;k--)
            {
                if(data[k]==0) wh++;
                if(data[k]==1) bl++;
            }
            if(wh==bl && data[i]!=data[j])
            {
                hei[i][j]=(hei[i-1][j+1])+1;
                map[i][j]=map[i-1][j+1]+(hei[i][j]*2+(i-j));
                check[i][j]=-1;
            }
            else map[i][j]=999;

            for(k=j+1;k<=i-2;k++)
            {
                if(map[k][j]+map[i][k+1]<map[i][j])
                {
                    map[i][j]=map[k][j]+map[i][k+1];
                    if(hei[k][j]>hei[i][k+1]) hei[i][j]=hei[k][j];
                    else hei[i][j]=hei[i][k+1];
                    check[i][j]=k;
                }
            }
        }
    }

    F(n,1);
    printf("%d",map[n][1]);
    return 0;
}
