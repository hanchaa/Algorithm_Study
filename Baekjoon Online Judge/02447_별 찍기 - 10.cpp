#pragma warning (disable : 4996)
#include <stdio.h>

char star[2200][2200];

void fill(int x, int y, int n) {
	if (n == 1) {
		star[x][y] = '*';
		return;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;

			fill(x + (n / 3) * i, y + (n / 3) * j, n / 3);
		}
	}
}

int main() {
	int n;
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			star[i][j] = ' ';

	fill(0, 0, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%c", star[i][j]);

		printf("\n");
	}

	return 0;
}