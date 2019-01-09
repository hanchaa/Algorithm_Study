#pragma warning (disable : 4996)
#include <conio.h>
#include <stdio.h>

int map[20][20];

int main(void)
{
	int n, m, i, j, k,x,y;
	scanf("%d %d %d", &n, &m, &k);
	map[1][1] = 1;
	y = k / m + 1; x = k%m; if (x == 0) { x = m; y--; }
	if (k == 0) { y = n; x = m; }
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= m;j++)
		{
			if (i == 1 && j == 1) continue;
			if ((i <= y && j <= x) || (i >= y && j >= x))
			{
				map[i][j] = map[i - 1][j] + map[i][j - 1];
			}
		}
	}
	printf("%d", map[n][m]);
	getch();
}