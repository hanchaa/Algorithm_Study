#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 1005
#define MAX(a, b)(a > b ? a : b)
#define MIN(a, b)(a < b ? a : b)

int map[N][N], t[N][N];

int main() {
	int n, m, i, j, k = 0;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (map[i][j] == 1) {
				t[i][j] = MIN(t[i-1][j-1], MIN(t[i - 1][j], t[i][j - 1])) + 1;
				k = MAX(k, t[i][j]);
			}
		}
	}

	printf("%d\n", k * k);

	return 0;
} 