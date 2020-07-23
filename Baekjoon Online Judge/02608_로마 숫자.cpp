#include <stdio.h>
#include <string.h>

char data[5][100],rom[10]={ ' ','I','V','X','L','C','D','M' };
int num[10]={0,1,5,10,50,100,500,1000};

int main()
{
    int i,j,tmp,sum=0,cnt,len;
    scanf("%s %s",data[1],data[2]);
    for(i=1;i<=2;i++)
    {
        len=strlen(data[i]);
        cnt=1;
        for(j=0;j<len;j++)
        {
            if(cnt==1 && data[i][j-1]=='I' && data[i][j]=='V') { sum+=3; cnt=1; continue; }
            if(cnt==1 && data[i][j-1]=='I' && data[i][j]=='X') { sum+=8; cnt=1; continue; }
            if(cnt==1 && data[i][j-1]=='X' && data[i][j]=='L') { sum+=30; cnt=1; continue; }
            if(cnt==1 && data[i][j-1]=='X' && data[i][j]=='C') { sum+=80; cnt=1; continue; }
            if(cnt==1 && data[i][j-1]=='C' && data[i][j]=='D') { sum+=300; cnt=1; continue; }
            if(cnt==1 && data[i][j-1]=='C' && data[i][j]=='M') { sum+=800; cnt=1; continue; }
            if(data[i][j]=='M') sum+=1000; if(data[i][j]=='D') sum+=500;
            if(data[i][j]=='C') sum+=100; if(data[i][j]=='L') sum+=50;
            if(data[i][j]=='X') sum+=10; if(data[i][j]=='V') sum+=5;
            if(data[i][j]=='I') sum+=1;
            if(data[i][j-1]!=data[i][j]) cnt=1;
            else cnt++;
        }
    }
    printf("%d\n",sum);
    for(i=7;i>=1;i--)
    {
        if(i==6 && sum/num[i-1]==9) { printf("CM"); sum=sum%900; continue; }
        if(i==5 && sum/num[i]==4) { printf("CD"); sum=sum%400; continue; }
        if(i==4 && sum/num[i-1]==9) { printf("XC"); sum=sum%90; continue; }
        if(i==3 && sum/num[i]==4) { printf("XL"); sum=sum%40; continue; }
        if(i==2 && sum/num[i-1]==9) { printf("IX"); sum=sum%9; continue; }
        if(i==1 && sum/num[i]==4) { printf("IV"); sum=sum%4; continue; }
        tmp=sum/num[i];
        for(j=1;j<=tmp;j++) printf("%c",rom[i]);
        sum=sum%num[i];
    }
    return 0;
}
