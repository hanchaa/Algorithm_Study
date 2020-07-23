#include <stdio.h>

bool check[15][15];
int n, cnt = 0;

void backtracking(int col) {
	if (col > n) {
		cnt++;
		return;
	}

	for (int i = 1; i <= n; i++) {
		bool flag = false;

		for (int j = 1; j < col; j++) {
			if (check[col - j][i])
				flag = true;

			if (i - j > 0 && check[col - j][i - j])
				flag = true;

			if (i + j <= n && check[col - j][i + j])
				flag = true;
		}

		if (flag)
			continue;

		check[col][i] = true;
		backtracking(col + 1);
		check[col][i] = false;
	}
}

int main() {
	scanf("%d", &n);

	backtracking(1);

	printf("%d", cnt);

	return 0;
}