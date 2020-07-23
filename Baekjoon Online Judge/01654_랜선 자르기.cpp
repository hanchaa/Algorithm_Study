#include <stdio.h>

#define MAX(a,b)(a>b?a:b)

int data[10000];

int main() {
	int n, k;
	long long lo = 0, hi = 0;

	scanf("%d %d", &k, &n);

	for (int i = 0; i < k; i++) {
		scanf("%d", data + i);
		hi = MAX(hi, data[i]);
	}

	hi++;

	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		int sum = 0;

		for (int i = 0; i < k; i++)
			sum += data[i] / mid;

		if (sum >= n)
			lo = mid;

		else
			hi = mid;
	}

	printf("%lld\n", lo);

	return 0;
}