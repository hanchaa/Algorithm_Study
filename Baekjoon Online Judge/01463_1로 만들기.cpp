#pragma warning (disable : 4996)
#include <stdio.h>

#define MIN(a,b)(a<b?a:b)

int data[1000005];

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		data[i] = 2e9;

		if (i % 3 == 0)
			data[i] = MIN(data[i], data[i / 3] + 1);

		if (i % 2 == 0)
			data[i] = MIN(data[i], data[i / 2] + 1);

		data[i] = MIN(data[i], data[i - 1] + 1);
	}

	printf("%d\n", data[n]);

	return 0;
}