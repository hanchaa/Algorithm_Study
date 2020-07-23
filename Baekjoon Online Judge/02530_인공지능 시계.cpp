#include <stdio.h>

int main()
{
    FILE *fi=fopen("input.txt","r");
    FILE *fw=fopen("output.txt","w");
    int h,m,s,s2;
    fscanf(fi,"%d %d %d %d",&h,&m,&s,&s2);
    s+=s2;
    while(s>=60)
    {
        s-=60; m++;
    }
    while(m>=60)
    {
        m-=60; h++;
    }
    while(h>=24)
    {
        h-=24;
    }
    fprintf(fw,"%d %d %d",h,m,s);
}
