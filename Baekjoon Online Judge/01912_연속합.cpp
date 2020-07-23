#pragma warning (disable : 4996)
#include <stdio.h>

#define MAX(a, b)(a > b ? a : b)
#define N 100005

int main() {
	int n, data[N] = { 0 }, t[N], max;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", data + i);
	}

	max = t[0] = data[0];

	for (int i = 1; i < n; i++) {
		t[i] = MAX(data[i], t[i - 1] + data[i]);
		max = MAX(max, t[i]);
	}

	printf("%d\n", max);

	return 0;
}