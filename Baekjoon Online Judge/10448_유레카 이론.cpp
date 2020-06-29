#pragma warning (disable : 4996)
#include <stdio.h>

int main() {
	int n, k, data[45];

	data[0] = 1;

	for (int i = 1; i < 45; i++)
		data[i] = data[i - 1] + i + 1;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int res = 0;
		scanf("%d", &k);

		for (int a = 0; a < 45; a++) {
			for (int b = 0; b < 45; b++) {
				for (int c = 0; c < 45; c++) {
					if (k == data[a] + data[b] + data[c]) {
						res = 1;
						break;
					}
				}
				if (res)
					break;
			}
			if (res)
				break;
		}

		printf("%d\n", res);
	}

	return 0;
}