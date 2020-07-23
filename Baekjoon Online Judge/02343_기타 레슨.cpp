#include <stdio.h>

int data[100000];

int main() {
	int n, m, lo = 0, hi = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", data + i);
		hi += data[i];
	}

	while (lo + 1 < hi) {
		int cnt = 0;
		long long mid = (lo + hi) / 2, sum = 0;

		int i = 0;

		while (cnt < m && i < n) {
			sum += data[i++];
			
			if (sum > mid) {
				sum = 0;
				cnt++;
				i--;
			}
		}

		if (i >= n)
			hi = mid;

		else
			lo = mid;
	}

	printf("%d\n", hi);

	return 0;
}