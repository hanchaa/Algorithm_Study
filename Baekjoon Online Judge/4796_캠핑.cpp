#pragma warning (disable : 4996)
#include <stdio.h>

#define MIN(a,b)(a<b?a:b)

int main() {
	int l, p, v, cnt = 1;

	scanf("%d %d %d", &l, &p, &v);

	while (l != 0 || p != 0 || v != 0) {
		int sum = l * (v / p);

		sum += MIN(l, v % p);

		printf("Case %d: %d\n", cnt, sum);

		cnt++;

		scanf("%d %d %d", &l, &p, &v);
	}
}