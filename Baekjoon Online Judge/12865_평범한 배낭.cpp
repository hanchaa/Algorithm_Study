#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(a, b)(a > b ? a : b)
#define N 105
#define M 100005

int t[N][M], w[N], v[N];

int main() {
	int n, m, i, j, k;

	scanf("%d %d", &n, &m);
	
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &w[i], &v[i]);
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (j - w[i] >= 0)
				t[i][j] = MAX(t[i - 1][j], t[i - 1][j - w[i]] + v[i]);
			else
				t[i][j] = t[i - 1][j];
		}
	}

	printf("%d\n", t[n][m]);

	return 0;
}