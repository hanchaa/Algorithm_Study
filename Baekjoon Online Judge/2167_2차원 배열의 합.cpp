#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 305

int map[N][N], t[N][N];

int main() {
	int n, m, i, j, k = 0;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			t[i][j] = t[i - 1][j] + t[i][j - 1] - t[i - 1][j - 1] + map[i][j];
		}
	}

	scanf("%d", &k);

	for (int a = 1; a <= k; a++) {
		int x, y;
		scanf("%d %d %d %d", &i, &j, &x, &y);

		printf("%d\n", t[x][y] - t[x][j - 1] - t[i - 1][y] + t[i - 1][j - 1]);
	}
	
	return 0;
} 