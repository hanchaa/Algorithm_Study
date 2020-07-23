#include <stdio.h>

long long segTree[2100000];

long long sum(int idx, int leftBound, int rightBound, int queryL, int queryR) {
	if (queryL > rightBound || queryR < leftBound)
		return 0;

	if (queryL <= leftBound && rightBound <= queryR)
		return segTree[idx];

	int mid = (leftBound + rightBound) / 2;

	return sum(idx * 2, leftBound, mid, queryL, queryR) + sum(idx * 2 + 1, mid + 1, rightBound, queryL, queryR);
}

int main() {
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	int size = 1;

	while (size < n)
		size *= 2;

	for (int i = size; i < size + n; i++)
		scanf("%lld", segTree + i);

	for (int i = size - 1; i > 0; i--)
		segTree[i] = segTree[i * 2] + segTree[i * 2 + 1];

	for (int i = 0; i < m + k; i++) {
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		if (a == 1) {
			int idx = size + b - 1;
			segTree[idx] = c;

			idx /= 2;

			while (idx >= 1) {
				segTree[idx] = segTree[idx * 2] + segTree[idx * 2 + 1];
				idx /= 2;
			}
		}

		if (a == 2)
			printf("%lld\n", sum(1, 1, size, b, c));
	}

	return 0;
}