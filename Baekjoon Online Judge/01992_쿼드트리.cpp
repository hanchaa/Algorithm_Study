#pragma warning (disable : 4996)
#include <stdio.h>

int data[64][64];

void solve(int x, int y, int n) {
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
		printf("%d", flag);

	else {
		printf("(");
		
		solve(x, y, n / 2);
		solve(x, y + n / 2, n / 2);
		solve(x + n / 2, y, n / 2);
		solve(x + n / 2, y + n / 2, n / 2);

		printf(")");
	}
}

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &data[i][j]);

	solve(0, 0, n);

	return 0;
}