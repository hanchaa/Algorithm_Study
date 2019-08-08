#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>

#define N 1005

int pre[N], in[N];

void f(int p1, int p2, int q1, int q2) {
	if (p1 > p2) return;

	if (p1 == p2) {
		printf("%d ", pre[p1]);
		return;
	}

	int qr;

	for (int i = q1; i <= q2; i++) {
		if (in[i] == pre[p1]) {
			qr = i;
			break;
		}
	}

	f(p1 + 1, p1 + qr - q1, q1, qr - 1);
	f(p1 + qr - q1 + 1, p2, qr + 1, q2);

	printf("%d ", pre[p1]);

}

int main() {
	int n, i, k, t = 0;

	scanf("%d", &t);

	for (k = 1; k <= t; k++) {
		scanf("%d", &n);

		for (i = 1; i <= n; i++) scanf("%d", &pre[i]);
		for (i = 1; i <= n; i++) scanf("%d", &in[i]);

		f(1, n, 1, n);
		printf("\n");

		memset(pre, 0, sizeof(pre));
		memset(in, 0, sizeof(in));
	}
	return 0;
}