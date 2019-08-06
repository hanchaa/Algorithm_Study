#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN(a, b)(a < b ? a : b)
#define N 1000005

int t[N];

int main() {
	int n, i;

	scanf("%d", &n);

	for (i = 2; i <= n; i++) {
		t[i] = t[i - 1] + 1;
		if (i % 2 == 0) t[i] = MIN(t[i], t[i / 2] + 1);
		if (i % 3 == 0) t[i] = MIN(t[i], t[i / 3] + 1);
	}

	printf("%d\n", t[n]);
	return 0;
}