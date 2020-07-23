#include <stdio.h>

int main()
{
    char ez[13]={'A','B','C','D','E','F','G','H','I','J','K','L'};
    int n,i,j,k;
    scanf("%d",&n);
    printf("%c%d",ez[(8+n%12)%12],(n%10+6)%10);
    return 0;
}
