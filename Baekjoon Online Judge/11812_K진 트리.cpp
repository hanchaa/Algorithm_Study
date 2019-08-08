#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

#define N 50005

using namespace std;

int main() {
	long long n, i, k, q, x, y;

	scanf("%lld %lld %lld", &n, &k, &q);

	for (i = 1; i <= q; i++) {
		long long lv1 = 1, lv2 = 1, px, py, d = 0;
		
		scanf("%lld %lld", &x, &y);

		if (x > y) swap(x, y);

		if (k == 1) {
			printf("%lld\n", y - x);
			continue;
		}

		px = x - 1;
		py = y - 1;

		while (px != 0) {
			px = (px - 1) / k;
			lv1++;
		}

		while (py != 0) {
			py = (py - 1) / k;
			lv2++;
		}

		px = x - 1;
		py = y - 1;

		while (lv1 < lv2) {
			py = (py - 1) / k;
			lv2--;
			d++;
		}

		while (px != py) {
			px = (px - 1) / k;
			py = (py - 1) / k;
			d += 2;
		}

		printf("%lld\n", d);
	}

	return 0;
}