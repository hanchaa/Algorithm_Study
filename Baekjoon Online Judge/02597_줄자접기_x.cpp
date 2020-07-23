#include <stdio.h>
#include <algorithm>
#define MAX(a,b)(a>b?a:b)

float color[5][4];

int main(void)
{
    int i,j;
    float n,k,m;
    scanf("%f",&n);
    for(i=1;i<=3;i++)
    {
        scanf("%f %f",&color[i][1],&color[i][2]);
        if(color[i][1]>color[i][2]) { m=color[i][1]; color[i][1]=color[i][2]; color[i][2]=m; }
    }
    for(i=1;i<=3;i++)
    {
        if(color[i][1]==color[i][2]) k=0;
        else k=(color[i][1]+color[i][2])/2;
        for(j=i+1;j<=3;j++)
        {
            if(color[j][1]<k && color[j][2]>k) color[j][1]=k+k-color[j][1];
            if(color[j][1]<k && color[j][2]<k) { color[j][1]=k+k-color[j][1]; color[j][2]=k+k-color[j][2]; }
            color[j][1]-=k; color[j][2]-=k;
            if(color[j][1]>color[j][2]) { m=color[j][1]; color[j][1]=color[j][2]; color[j][2]=m; }
        }
        n=MAX(k,n-k);
    }
    printf("%.1f",n);
}
