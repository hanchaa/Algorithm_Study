#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN(a, b)(a < b ? a : b)
#define N 1005

int t[N], map[N];

int main() {
	int n, i, j;

	scanf("%d", &n);

	for (i = 2; i <= n; i++) t[i] = N;

	for (i = 1; i <= n; i++) scanf("%d", &map[i]);

	for (i = 1; i <= n; i++) {
		for (j = i; j <= i + map[i]; j++) {
			t[j] = MIN(t[j], t[i] + 1);
		}
	}

	if (t[n] == N) t[n] = -1;

	printf("%d\n", t[n]);
	
	return 0;
}