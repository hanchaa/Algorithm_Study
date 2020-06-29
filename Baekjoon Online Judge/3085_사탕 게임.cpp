#pragma warning (disable : 4996)
#include <stdio.h>

#define MAX(a,b)(a>b?a:b)

int countCandy(char map[][50], int n) {
	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = 1, k;
			char tmp = map[i][j];

			k = i + 1;

			while (map[k][j] == tmp && k < n) {
				cnt++;
				k++;
			}

			max = MAX(max, cnt);

			k = j + 1;
			cnt = 1;

			while (map[i][k] == tmp && k < n) {
				cnt++;
				k++;
			}

			max = MAX(max, cnt);
		}
	}

	return max;
}

int main() {
	int n, max = 0;
	char map[50][50] = { 0 };

	scanf("%d\n", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char tmp;
			if (i > 0 && map[i - 1][j] != map[i][j]) {
				tmp = map[i][j];
				map[i][j] = map[i - 1][j];
				map[i - 1][j] = tmp;

				max = MAX(max, countCandy(map, n));

				tmp = map[i][j];
				map[i][j] = map[i - 1][j];
				map[i - 1][j] = tmp;
			}

			if (j > 0 && map[i][j - 1] != map[i][j]) {
				tmp = map[i][j];
				map[i][j] = map[i][j - 1];
				map[i][j - 1] = tmp;

				max = MAX(max, countCandy(map, n));

				tmp = map[i][j];
				map[i][j] = map[i][j - 1];
				map[i][j - 1] = tmp;
			}

			if (i < n - 1 && map[i + 1][j] != map[i][j]) {
				tmp = map[i][j];
				map[i][j] = map[i + 1][j];
				map[i + 1][j] = tmp;

				max = MAX(max, countCandy(map, n));

				tmp = map[i][j];
				map[i][j] = map[i + 1][j];
				map[i + 1][j] = tmp;
			}

			if (j < n - 1 && map[i][j + 1] != map[i][j]) {
				tmp = map[i][j];
				map[i][j] = map[i][j + 1];
				map[i][j + 1] = tmp;

				max = MAX(max, countCandy(map, n));

				tmp = map[i][j];
				map[i][j] = map[i][j + 1];
				map[i][j + 1] = tmp;
			}
		}
	}

	printf("%d\n", max);

	return 0;
}