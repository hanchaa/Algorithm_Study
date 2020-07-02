#pragma warning (disable : 4996)
#include <stdio.h>

int data[2200][2200], cnt[3];

void devide(int x, int y, int n) {
	int flag = data[x][y];
	bool possible = true;

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (data[i][j] != flag) {
				possible = false;
				break;
			}
		}

		if (!possible)
			break;
	}

	if (possible)
		cnt[flag + 1]++;

	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				devide(x + i * (n / 3), y + j * (n / 3), n / 3);
			}
		}
	}
}

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &data[i][j]);

	devide(0, 0, n);

	printf("%d\n%d\n%d\n", cnt[0], cnt[1], cnt[2]);

	return 0;
}