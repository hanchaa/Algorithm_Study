#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 1005
#define MAX(a, b)(a > b ? a : b)

int map[N][N], t[N][N], t2[N];

int main() {
	int n, m, i, j, k;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (i = 1; i <= m; i++) {
		t[1][i] = t[1][i - 1] + map[1][i];
	}

	for (i = 2; i <= n; i++) {
		t[i][1] = t[i - 1][1] + map[i][1];

		for (j = 2; j <= m; j++) {
			t[i][j] = MAX(t[i - 1][j], t[i][j - 1]) + map[i][j];
		}

		t2[m] = t[i - 1][m] + map[i][m];

		for (j = m - 1; j >= 1; j--) {
			t2[j] = MAX(t[i - 1][j], t2[j + 1]) + map[i][j];
		}

		for (j = 1; j <= m; j++) {
			t[i][j] = MAX(t[i][j], t2[j]);
		}
	}

	printf("%d\n", t[n][m]);

	return 0;
}