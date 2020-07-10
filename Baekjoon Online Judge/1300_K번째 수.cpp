#include <stdio.h>

#define MIN(a,b)(a<b?a:b)

int main() {
	int n, k;
	
	scanf("%d %d", &n, &k);

	long long lo = 0, hi = (long long)n * n;

	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		long long cnt = 0;

		for (int i = 1; i <= n; i++)
			cnt += MIN(mid / i, n);

		if (cnt >= k)
			hi = mid;

		else
			lo = mid;
	}

	printf("%lld\n", hi);

	return 0;
}