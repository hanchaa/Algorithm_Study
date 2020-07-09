#include <stdio.h>

typedef struct {
	int start, finish, interval;
} Rule;

Rule rule[1000000];

int main() {
	int n, k, d, lo = 0, hi;

	scanf("%d %d %d", &n, &k, &d);

	for (int i = 0; i < k; i++)
		scanf("%d %d %d", &rule[i].start, &rule[i].finish, &rule[i].interval);

	hi = n;

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2, cnt = 0;

		for (int i = 0; i < k; i++)
			cnt += (mid - rule[i].start) / rule[i].interval + 1;

		if (cnt >= d)
			hi = mid;

		else
			lo = mid;
	}

	printf("%d\n", hi);

	return 0;
}