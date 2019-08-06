#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 1005
#define MAX(a, b)(a > b ? a : b)

int map[N][N], t[N][N];

int main() {
	int n, m, i, j, k;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			t[i][j] = MAX(t[i - 1][j - 1] + map[i][j], MAX(t[i - 1][j] + map[i][j], t[i][j - 1] + map[i][j]));
		}
	}

	printf("%d\n", t[n][m]);

	return 0;
}