#include <stdio.h>

#define MAX(a,b)(a>b?a:b)

int data[10000];

int main() {
	int n, m, lo = 0, hi = 0;
	long long sum = 0;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", data + i);
		hi = MAX(hi, data[i]);
		sum += data[i];
	}

	scanf("%d", &m);

	if (sum <= m)
		lo = hi;

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		sum = 0;

		for (int i = 0; i < n; i++) {
			if (data[i] > mid)
				sum += mid;

			else
				sum += data[i];
		}

		if (sum > m)
			hi = mid;

		else
			lo = mid;
	}

	printf("%d\n", lo);

	return 0;
}