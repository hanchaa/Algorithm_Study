#pragma warning (disable : 4996)
#include <stdio.h>

int main() {
	int n, min = 1000000;
	scanf("%d", &n);

	for (int i = n; i > 0; i--) {
		int tmp = i, sum = i;

		while (tmp > 0) {
			sum += tmp % 10;
			tmp /= 10;
		}

		if (sum == n)
			min = i;
	}

	if (min == 1000000)
		min = 0;

	printf("%d\n", min);

	return 0;
}