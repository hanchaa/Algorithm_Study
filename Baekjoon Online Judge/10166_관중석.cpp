#pragma warning (disable : 4996)
#include <stdio.h>
#define N 2005

int d[N][N];

int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main(void)
{
	int d1, d2, i, j, k;
	scanf("%d %d", &d1, &d2);
	for (i = d1;i <= d2;i++)
	{
		for (j = 1;j <= i;j++)
		{
			if (j == 1) { d[0][0] = 1; continue; }
			k = gcd(j - 1,i);
			d[i / k][(j-1) / k] = 1;
		}
	}
	k = 0;
	for(i=0;i<=d2;i++)
	{
		for (j = 0;j <= d2;j++) if (d[i][j] == 1) k++;
	}
	printf("%d", k);
}