#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 150
#define MAX(a, b)(a > b ? a : b)

long long map[N][N], t[N][N];

int main() {
	int n, m, i, j, k;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%lld", &map[i][j]);
		}
	}

	t[1][1] = 1;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (t[i][j] == 0) continue;
			if (i == n && j == n) continue;
			t[i + map[i][j]][j] += t[i][j];
			t[i][j + map[i][j]] += t[i][j];
		}
	}

	printf("%lld\n", t[n][n]);

	return 0;
}