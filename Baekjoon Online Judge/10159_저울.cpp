#pragma warning (disable : 4996)
#include <stdio.h>

#define M 105
#define INF 100000000

#define MIN(a,b)(a < b ? a : b)

int main() {
	int D[M][M] = { 0 };
	int n, m, i, j, k, a, b, s;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			D[i][j] = INF;
		}
	}

	for (i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);

		D[a][b] = 1;
	}

	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (D[i][j] > D[i][k] + D[k][j]) {
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (D[i][j] != INF)
				D[j][i] = D[i][j];
		}
	}

	for (i = 1; i <= n; i++) {
		int cnt = 0;
		for (j = 1; j <= n; j++) {
			if (i != j && D[i][j] == INF) cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}