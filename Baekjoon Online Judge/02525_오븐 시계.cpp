#include <stdio.h>

int main(void)
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    m+=k;
    if(m>=60) { n+=m/60; m=m%60; }
    if(n>=24) n=n%24;
    printf("%d %d",n,m);
}
