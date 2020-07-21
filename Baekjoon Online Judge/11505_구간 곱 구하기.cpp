#include <stdio.h>
#include <string.h>

#define mod 1000000007

int segTree[2100000];

int query(int idx, int leftBound, int rightBound, int queryL, int queryR) {
	if (queryL > rightBound || queryR < leftBound)
		return 1;

	if (queryL <= leftBound && rightBound <= queryR)
		return segTree[idx];

	int mid = (leftBound + rightBound) / 2;
	long long tmp = ((long long)query(idx * 2, leftBound, mid, queryL, queryR) * query(idx * 2 + 1, mid + 1, rightBound, queryL, queryR)) % mod;

	return (int)tmp;
}

int main() {
	int n, m, k, size = 1;

	scanf("%d %d %d", &n, &m, &k);

	while (size < n)
		size *= 2;

	for (int i = 1; i < size * 2; i++)
		segTree[i] = 1;

	for (int i = size; i < size + n; i++)
		scanf("%d", segTree + i);

	for (int i = size - 1; i > 0; i--) {
		long long tmp = ((long long)segTree[i * 2] * segTree[i * 2 + 1]) % mod;
		segTree[i] = tmp;
	}

	for (int i = 0; i < m + k; i++) {
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		if (a == 1) {
			int idx = size + b - 1;
			segTree[idx] = c;

			idx /= 2;

			while (idx >= 1) {
				long long tmp = ((long long)segTree[idx * 2] * segTree[idx * 2 + 1]) % mod;
				segTree[idx] = tmp;

				idx /= 2;
			}
		}

		if (a == 2)
			printf("%d\n", query(1, 1, size, b, c));
	}

	return 0;
}