#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(a, b)(a > b ? a : b)
#define N 50005

int t1[N], t2[N], map[5][N];

int main() {
	int t;
	scanf("%d", &t);
	for (int a = 1; a <= t; a++) {
		int n, m, i, j, k;

		scanf("%d", &n);
		for (i = 1; i <= 2; i++) {
			for (j = 1; j <= n; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		t1[1] = map[1][1];
		t2[1] = map[2][1];

		for (i = 2; i <= n; i++) {
			t1[i] = MAX(t2[i - 1] + map[1][i], MAX(t1[i - 2] + map[1][i], t1[i - 1]));
			t2[i] = MAX(t1[i - 1] + map[2][i], MAX(t2[i - 2] + map[2][i], t2[i - 1]));
		}

		printf("%d\n", MAX(t1[n], t2[n]));
	}
	return 0;
}