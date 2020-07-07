#include <stdio.h>

#define MAX(a,b)(a>b?a:b)

int data[1000000];

int main() {
	int n, m, lo = 0, hi = 0, mid, ans;
	
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", data + i);
		hi = MAX(hi, data[i]);
	}

	while (lo  + 1 < hi) {
		mid = (lo + hi) / 2;

		long long sum = 0;

		for (int i = 0; i < n; i++)
			if (data[i] - mid > 0)
				sum += data[i] - mid;

		if (sum >= m)
			lo = mid;

		else
			hi = mid;
	}

	printf("%d\n", lo);

	return 0;
}