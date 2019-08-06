#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 2005

int map[N], t[N][N];

int main() {
	int n, m, i, j, k = 0;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) scanf("%d", &map[i]);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			t[i][j] = 1;
		}
	}

	for (i = n - 1; i >= 1; i--) {
		for (j = i + 1; j <= n; j++) {
			if (map[i] == map[j] && t[i + 1][j - 1] == 1) t[i][j] = 1;
		}
	}

	scanf("%d", &k);
	for (int a = 1; a <= k; a++) {
		scanf("%d %d", &i, &j);
		printf("%d\n", t[i][j]);
	}
	
	return 0;
} 