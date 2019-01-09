#include <stdio.h>

int main()
{
    int n,p,k,chk,cnt=0;
    scanf("%d %d",&n,&p);
    k=n*n%p;
    chk=k;
    while(1)
    {
        k=k*n%p;
        cnt++;
        if(k==chk) break;
    }
    printf("%d",cnt);
    return 0;
}
