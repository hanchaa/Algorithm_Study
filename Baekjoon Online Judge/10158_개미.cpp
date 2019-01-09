#include <stdio.h>

int main()
{
    freopen("input.txt","r",stdin);
    int w,h,i,j,k,x,y,t;
    scanf("%d %d %d %d %d",&w,&h,&x,&y,&t);
    i=j=1;
    k=(x+t)/w;
    if(k%2==0) x=(x+t)%w;
    else x=w-(x+t)%w;
    k=(y+t)/h;
    if(k%2==0) y=(y+t)%h;
    else y=h-(y+t)%h;
    printf("%d %d",x,y);
    return 0;
}
