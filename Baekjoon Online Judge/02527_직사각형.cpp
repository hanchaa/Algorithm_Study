#include <stdio.h>

int main()
{
    freopen("input.txt","r",stdin);
    int i,j,data[6][10]={0};
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=8;j++)
        {
            scanf("%d",&data[i][j]);
        }
    }
    for(i=1;i<=4;i++)
    {
        if((data[i][3]==data[i][5] && data[i][4]==data[i][6]) || (data[i][3]==data[i][5] && data[i][2]==data[i][8]) || (data[i][1]==data[i][7] && data[i][2]==data[i][8]) || (data[i][1]==data[i][7] && data[i][4]==data[i][6])) printf("c");
        else if((data[i][1]==data[i][7] && (data[i][2]!=data[i][8] || data[i][4]!=data[i][6])) || (data[i][3]==data[i][5] && (data[i][4]!=data[i][6] || data[i][2]!=data[i][8]))) printf("b");
        else if((data[i][2]==data[i][8] && (data[i][3]>data[i][1] || data[i][1]!=data[i][7])) || (data[i][4]==data[i][6] && (data[i][3]!=data[i][5] || data[i][1]!=data[i][7]))) printf("b");
        else if(data[i][3]<data[i][5] || data[i][4]<data[i][6] || data[i][1]>data[i][7] || data[i][2]>data[i][8]) printf("d");
        else if(data[i][3]>data[i][5] && data[i][4]>data[i][6]) printf("a");
        printf("\n");
    }
    return 0;
}
