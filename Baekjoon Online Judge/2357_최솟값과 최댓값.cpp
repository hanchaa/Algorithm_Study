#include <stdio.h>

#define INF 2000000000
#define MIN(a,b)(a<b?a:b)
#define MAX(a,b)(a>b?a:b)

int minSegTree[262145], maxSegTree[262145];

int minQuery(int idx, int leftBound, int rightBound, int queryL, int queryR) {
	if (queryL <= leftBound && rightBound <= queryR)
		return minSegTree[idx];

	int mid = (leftBound + rightBound) / 2;

	int lMin = INF, rMin = INF;

	if (queryL <= mid && leftBound <= queryR)
		lMin = minQuery(idx * 2, leftBound, mid, queryL, queryR);

	if (queryL <= rightBound && mid + 1 <= queryR)
		rMin = minQuery(idx * 2 + 1, mid + 1, rightBound, queryL, queryR);

	return MIN(lMin, rMin);
}

int maxQuery(int idx, int leftBound, int rightBound, int queryL, int queryR) {
	if (queryL > rightBound || queryR < leftBound)
		return 0;

	if (queryL <= leftBound && rightBound <= queryR)
		return maxSegTree[idx];

	int mid = (leftBound + rightBound) / 2;

	int lMax = 0, rMax = 0;

	if (queryL <= mid && leftBound <= queryR)
		lMax = maxQuery(idx * 2, leftBound, mid, queryL, queryR);

	if (queryL <= rightBound && mid + 1 <= queryR)
		rMax = maxQuery(idx * 2 + 1, mid + 1, rightBound, queryL, queryR);

	return MAX(lMax, rMax);
}

int main() {
	int n, m, size = 1;

	scanf("%d %d", &n, &m);

	while (size < n)
		size *= 2;

	for (int i = size; i < size + n; i++) {
		int tmp;
		scanf("%d", &tmp);

		minSegTree[i] = maxSegTree[i] = tmp;
	}

	for (int i = size + n; i < size * 2; i++)
		minSegTree[i] = INF;

	for (int i = size - 1; i > 0; i--) {
		minSegTree[i] = MIN(minSegTree[i * 2], minSegTree[i * 2 + 1]);
		maxSegTree[i] = MAX(maxSegTree[i * 2], maxSegTree[i * 2 + 1]);
	}

	// 루프부터 리프로 내려가는 쿼리
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d %d\n", minQuery(1, 1, size, a, b), maxQuery(1, 1, size, a, b));
	}

	return 0;
}

/* 리프부터 루프로 올라가는 쿼리
for (int i = 0; i < m; i++) {
		int a, b, min = INF, max = 0;
		scanf("%d %d", &a, &b);

		a += size - 1;
		b += size - 1;

		if (a == b) {
			printf("%d %d\n", minSegTree[a], maxSegTree[a]);
			continue;
		}

		while (a != b) {
			if (a % 2) {
				min = MIN(min, minSegTree[a]);
				max = MAX(max, maxSegTree[a]);

				a = a / 2 + 1;
			}

			else
				a /= 2;

			if (b % 2 == 0) {
				min = MIN(min, minSegTree[b]);
				max = MAX(max, maxSegTree[b]);

				b = b / 2 - 1;
			}

			else
				b /= 2;

			if (a >= b) {
				if (a == b) {
					min = MIN(min, minSegTree[a]);
					max = MAX(max, maxSegTree[a]);
				}

				break;
			}
		}

		printf("%d %d\n", min, max);
	}
*/