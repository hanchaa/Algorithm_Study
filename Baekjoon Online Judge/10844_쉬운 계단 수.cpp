#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(a, b)(a > b ? a : b)
#define N 105
#define M 15
#define INF 1000000000

int t[N][M];

int main() {
	int n, m, i, j, k, s;

	scanf("%d", &n);

	for (i = 0; i <= 9; i++) t[1][i] = 1;

	for (i = 2; i <= n; i++) {
		for (j = 0; j <= 9; j++) {
			if (j == 0) t[i][j] = t[i - 1][j + 1];
			else t[i][j] = (t[i - 1][j - 1] + t[i - 1][j + 1]) % INF;
		}
	}

	s = 0;

	for (i = 1; i <= 9; i++) {
		s += t[n][i];
		if (s >= INF) s -= INF;
	}

	printf("%d\n", s);

	return 0;
}