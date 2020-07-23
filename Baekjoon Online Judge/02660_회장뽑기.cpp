#pragma warning(disable : 4996)
#include <stdio.h>

#define M 55
#define INF 100000

#define MIN(a,b)(a < b ? a : b)

int main() {
	int D[M][M] = { 0 }, P[M][M] = { 0 };
	int n, i, j, k, a, b, hubo = INF;
	int score[M] = { 0 };

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			D[i][j] = INF;
		}
	}

	while (1) {
		scanf("%d %d", &a, &b);
		if (a == -1 && b == -1) break;

		D[a][b] = D[b][a] = 1;
		P[a][b] = a;
		P[b][a] = b;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j) continue;

			for (k = 1; k <= n; k++) {
				if (i == k || j == k) continue;
				if (D[i][j] > D[i][k] + D[k][j]) {
					D[i][j] = D[j][i] = D[i][k] + D[k][j];
					P[i][j] = P[j][i] = k;
				}
			}
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (score[i] < D[i][j] && D[i][j] < INF)
				score[i] = D[i][j];
		}

		hubo = MIN(hubo, score[i]);
	}
	
	k = 0;
	for (i = 1; i <= n; i++) {
		if (score[i] == hubo) k++;
	}

	printf("%d %d\n", hubo, k);
	for (i = 1; i <= n; i++) {
		if (score[i] == hubo) printf("%d ", i);
	}

	return 0;
}