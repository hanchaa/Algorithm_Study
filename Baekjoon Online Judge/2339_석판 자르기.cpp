#pragma warning (disable : 4996)
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> coord;

int map[20][20];

int isPossible(coord leftUp, coord rightDown) {
	int cnt[2] = { 0 };

	for (int i = leftUp.first; i <= rightDown.first; i++) {
		for (int j = leftUp.second; j <= rightDown.second; j++) {
			if (map[i][j] == 1)
				cnt[0]++;

			else if (map[i][j] == 2)
				cnt[1]++;
		}
	}

	if (cnt[1] == 0)
		return 0;

	else if (cnt[1] == 1) {
		if (cnt[0] == 0)
			return 1;

		else
			return 0;
	}

	else if (cnt[0] == 0)
		return 0;

	return 2;
}

int cut(coord leftUp, coord rightDown, bool direction) {
	int possible = isPossible(leftUp, rightDown), sum = 0;

	if (possible != 2)
		return possible;

	for (int i = leftUp.first; i <= rightDown.first; i++) {
		for (int j = leftUp.second; j <= rightDown.second; j++) {
			possible = 0;

			if (map[i][j] == 1) {
				possible = 1;

				if (direction) {
					for (int k = leftUp.first; k <= rightDown.first; k++) {
						if (map[k][j] == 2)
							possible = 0;
					}
				}

				else {
					for (int k = leftUp.second; k <= rightDown.second; k++) {
						if (map[i][k] == 2)
							possible = 0;
					}
				}
			}

			if (!possible)
				continue;

			int first, second;

			if (direction) {
				first = cut(leftUp, { rightDown.first, j - 1 }, !direction);
				if (!first)
					continue;

				second = cut({ leftUp.first, j + 1 }, rightDown, !direction);
				if (!second)
					continue;
			}

			else {
				first = cut(leftUp, { i - 1, rightDown.second }, !direction);
				if (!first)
					continue;

				second = cut({ i + 1, leftUp.second }, rightDown, !direction);
				if (!second)
					continue;
			}

			sum += first * second;
		}
	}

	return sum;
}

int main() {
	int n, ans;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);

	ans = cut({ 0, 0 }, { n - 1, n - 1 }, 0) + cut({ 0,0 }, { n - 1,n - 1 }, 1);

	if (ans == 0)
		ans = -1;

	printf("%d\n", ans);
	
	return 0;
}