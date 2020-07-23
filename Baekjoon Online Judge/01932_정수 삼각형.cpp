#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 505
#define max(a, b)(a > b ? a : b)

int map[N][N], t[N][N];

int main() {
	int n, m, i, j, k;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			t[i][j] = max(t[i - 1][j - 1] + map[i][j], t[i - 1][j] + map[i][j]);
		}
	}

	k = 0;

	for (i = 1; i <= n; i++) k = max(k, t[n][i]);

	printf("%d\n", k);

	return 0;
}