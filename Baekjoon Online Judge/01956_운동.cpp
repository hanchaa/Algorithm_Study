#pragma warning(disable : 4996)
#include <stdio.h>

#define M 405
#define INF 10000000

#define MIN(a,b)(a < b ? a : b)

int main() {
	int D[M][M] = { 0 };
	int n, m, i, j, k, a, b, c;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			D[i][j] = INF;
		}
	}

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);

		D[a][b] = c;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			for (k = 1; k <= n; k++) {
				if (D[i][j] > D[i][k] + D[k][j]) {
					D[i][j] =  D[i][k] + D[k][j];
				}
			}
		}
	}

	k = INF;

	for (i = 1; i <= n; i++) {
		k = MIN(k, D[i][i]);
	}

	if (k == INF) k = -1;

	printf("%d\n", k);

	return 0;
}