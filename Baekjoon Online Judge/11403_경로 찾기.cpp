#include <stdio.h>

int main() {
	int n, map[100][100] = { 0 };

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				map[i][j] = map[i][k] + map[k][j] == 2 ? 1 : map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", map[i][j]);

		printf("\n");
	}

	return 0;
}