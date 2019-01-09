#pragma warning (disable : 4996)
#include <stdio.h>

int main(void)
{
	int k, c, n, m, i, j, p, q;
	scanf("%d %d", &k, &c);
	for (i = 1;i <= c;i++)
	{
		n = m = 0;
		scanf("%d %d", &p, &q);
		for (j = 1;j <= k;j++)
		{
			if(n < p) n++;
			if (m + k - j + 1 < n) break;
			if (n + k - j < m) break;
			if (m < q) m++;
			if (n + k - j < m) break;
			if (m + k - j < n) break;
		}
		if (p==n && q==m) printf("1\n");
		else printf("0\n");
	}
}