#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(a, b)(a > b ? a : b)
#define N 1005

int t[N], t2[N], map[N], map2[N];

int main() {
	int n, m, i, j, k;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &map[i]);
		map2[n - i + 1] = map[i];
	}

	t[1] = 1;

	for (i = 2; i <= n; i++) {
		for (j = i - 1; j >= 0; j--) {
			if (map[i] > map[j]) {
				t[i] = MAX(t[i], t[j] + 1);
			}
		}
	}

	t2[1] = 1;

	for (i = 2; i <= n; i++) {
		for (j = i - 1; j >= 0; j--) {
			if (map2[i] > map2[j]) {
				t2[i] = MAX(t2[i], t2[j] + 1);
			}
		}
	}

	k = 0;

	for (i = 1; i <= n; i++) k = MAX(k, t[i] + t2[n - i + 1] - 1);

	printf("%d\n", k);
	return 0;
}