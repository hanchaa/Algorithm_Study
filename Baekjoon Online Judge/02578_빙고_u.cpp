#include <stdio.h>

int main()
{
    FILE *fi=fopen("input.txt","r");
    FILE *fw=fopen("output.txt","w");
    int bingo=0,i,j,k,data[6][6],su=0,ga[6]={0},se[6]={0},dae[2]={0};
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            fscanf(fi,"%d",&data[i][j]);
        }
    }
    for(i=1;i<=25;i++)
    {
        fscanf(fi,"%d",&su);
        for(j=1;j<=5;j++)
        {
            for(k=1;k<=5;k++)
            {
                if(data[j][k]==su) { data[j][k]==26; break; }
            }
            if(k<=5) break;
        }
        for(j=1;j<=5;j++)
        {
            ga[j]=0;
            se[j]=0;
            for(k=1;k<=5;k++)
            {
                if(data[j][k]!=26) ga[j]=1;
                if(data[k][j]!=26) se[j]=1;
            }

        }
    }
}
