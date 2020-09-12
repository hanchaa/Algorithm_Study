#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 1 << 21

long long segTree[N], lazy[N];

void initSegTree() {
	for (int i = (N) / 2 - 1; i > 0; i--)
		segTree[i] = segTree[i * 2] + segTree[i * 2 + 1];
}

void propagate(int n, int l, int r) {
	if (lazy[n]) {
		if (n < (N) / 2) {
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		
		segTree[n] += lazy[n] * (r - l);
		lazy[n] = 0;
	}
}

void Add(int l, int r, int n, int ll, int rr, int k) {
	propagate(n, l, r);

	if (r <= ll || rr <= l)
		return;

	if (ll <= l && r <= rr) {
		lazy[n] += k;
		propagate(n, l, r);
		return;
	}

	int mid = (l + r) / 2;
	Add(l, mid, n * 2, ll, rr, k);
	Add(mid, r, n * 2 + 1, ll, rr, k);
	segTree[n] = segTree[n * 2] + segTree[n * 2 + 1];
}

long long Sum(int l, int r, int n, int ll, int rr) {
	propagate(n, l, r);

	if (r <= ll || rr <= l)
		return 0;

	if (ll <= l && r <= rr)
		return segTree[n];

	int mid = (l + r) / 2;

	return Sum(l, mid, n * 2, ll, rr) + Sum(mid, r, n * 2 + 1, ll, rr);
}

int main() {
	int n, m, k;
	
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < n; i++)
		scanf("%lld", segTree + ((N) / 2 + i));

	initSegTree();

	for (int i = 0; i < m + k; i++) {
		int a, b, c, d;
		scanf("%d", &a);

		if (a == 1) {
			scanf("%d %d %d", &b, &c, &d);
			Add(0, (N) / 2, 1, b - 1, c, d);
		}

		else {
			scanf("%d %d", &b, &c);
			printf("%lld\n",Sum(0, (N) / 2, 1, b - 1, c));
		}
	}

	return 0;
}