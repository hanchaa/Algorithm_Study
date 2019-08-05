#pragma warning (disable : 4996)
#include <stdio.h>

#define M 105
#define INF 100000000

int main() {
	int D[M][M] = { 0 };
	int n, m, i, j, k, a, b, s;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j) continue;
			D[i][j] = INF;
		}
	}

	for (i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);

		D[a][b] = D[b][a] = 1;
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

	k = INF;

	for (i = 1; i <= n; i++) {
		int sum = 0;
		for (j = 1; j <= n; j++) {
			if (i == j) continue;
			sum += D[i][j];
		}
		if (k > sum) {
			k = sum;
			s = i;
		}
	}

	printf("%d\n", s);

	return 0;
}