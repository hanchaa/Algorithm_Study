#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(a, b)(a > b ? a : b)
#define N 105
#define M 1005

int t[N][M], v[N];

int main() {
	int n, m, i, j, k, s;

	scanf("%d %d %d", &n, &s, &m);
	
	for (i = 1; i <= n; i++) scanf("%d", &v[i]);

	t[0][s] = 1;

	for (i = 1; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			if (j - v[i] >= 0 && t[i - 1][j - v[i]] == 1)
				t[i][j] = 1;

			if (j + v[i] <= m && t[i - 1][j + v[i]] == 1)
				t[i][j] = 1;
		}
	}

	k = -1;

	for (i = 0; i <= m; i++) {
		if (t[n][i] == 1) k = i;
	}
	
	printf("%d\n", k);

	return 0;
}