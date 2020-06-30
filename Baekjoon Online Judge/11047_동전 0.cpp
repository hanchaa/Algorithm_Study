#pragma warning (disable : 4996)
#include <stdio.h>

int main() {
	int n, k, coin[10], cnt = 0;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", coin + i);

	for (int i = n - 1; i >= 0; i--) {
		cnt += k / coin[i];
		k %= coin[i];
	}

	printf("%d\n", cnt);

	return 0;
}