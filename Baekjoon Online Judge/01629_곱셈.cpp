#pragma warning (disable : 4996)
#include <stdio.h>

long long solve(int l, int r, int a, int c) {
	if (l == r)
		return a % c;

	int mid = (l + r) / 2;
	long long res;

	if ((r - l) % 2 == 0)
		res = solve(l, r - 1, a, c) * (a % c) % c;

	else {
		res = solve(l, mid, a, c);
		res = res * res % c;
	}

	return res;
}

int main() {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	printf("%lld\n", solve(1, b, a, c));

	return 0;
}