#include <stdio.h>

int data[50][50], test[50][50], min[50][50];

int main() {
	int n, m, ans = 1e9;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &data[i][j]);

	for (int a = 0; a < 128; a++) {
		for (int b = 0; b < 128; b++) {
			int sum = 0;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if ((data[i][j] - a) * (data[i][j] - a) < (data[i][j] - b) * (data[i][j] - b)) {
						sum += (data[i][j] - a) * (data[i][j] - a);
						test[i][j] = a;
					}

					else {
						sum += (data[i][j] - b) * (data[i][j] - b);
						test[i][j] = b;
					}
				}
			}

			if (sum < ans) {
				ans = sum;

				for (int i = 0; i < n; i++)
					for (int j = 0; j < m; j++)
						min[i][j] = test[i][j];
			}
		}
	}

	printf("%d\n", ans);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d ", min[i][j]);

		printf("\n");
	}

	return 0;
}