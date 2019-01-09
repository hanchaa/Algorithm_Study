#include <stdio.h>

int map[25][25];

int main()
{
    int i,j,k;
    for(i=1;i<=19;i++) for(j=1;j<=19;j++) scanf("%d",&map[i][j]);
    for(i=1;i<=19;i++)
    {
        for(j=1;j<=19;j++)
        {
            if(map[i][j]==1)
            {
                if(map[i-1][j]!=1) for(k=0;k<=5;k++) { if(map[i+k][j]!=1 && k==5) { printf("1\n%d %d",i,j); return 0; } if(map[i+k][j]!=1) break; }
                if(map[i][j-1]!=1) for(k=0;k<=5;k++) { if(map[i][j+k]!=1 && k==5) { printf("1\n%d %d",i,j); return 0; } if(map[i][j+k]!=1) break; }
                if(map[i-1][j-1]!=1) for(k=0;k<=5;k++) { if(map[i+k][j+k]!=1 && k==5) { printf("1\n%d %d",i,j); return 0; } if(map[i+k][j+k]!=1) break; }
                if(map[i+1][j-1]!=1) for(k=0;k<=5;k++) { if(map[i-k][j+k]!=1 && k==5) { printf("1\n%d %d",i,j); return 0; } if(map[i-k][j+k]!=1) break; }
            }
            if(map[i][j]==2)
            {
                if(map[i-1][j]!=2) for(k=0;k<=5;k++) { if(map[i+k][j]!=2 && k==5) { printf("2\n%d %d",i,j); return 0; } if(map[i+k][j]!=2) break; }
                if(map[i][j-1]!=2) for(k=0;k<=5;k++) { if(map[i][j+k]!=2 && k==5) { printf("2\n%d %d",i,j); return 0; } if(map[i][j+k]!=2) break; }
                if(map[i-1][j-1]!=2) for(k=0;k<=5;k++) { if(map[i+k][j+k]!=2 && k==5) { printf("2\n%d %d",i,j); return 0; } if(map[i+k][j+k]!=2) break; }
                if(map[i+1][j-1]!=2) for(k=0;k<=5;k++) { if(map[i-k][j+k]!=2 && k==5) { printf("2\n%d %d",i,j); return 0; } if(map[i-k][j+k]!=2) break; }
            }
        }
    }
    printf("0");
}

