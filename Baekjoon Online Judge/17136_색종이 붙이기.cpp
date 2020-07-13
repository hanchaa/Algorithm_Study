#include <stdio.h>
#include <vector>

#define MIN(a,b)(a<b?a:b);

using namespace std;

int ans = 2e9, paperCnt[10], map[10][10], check[10][10];
vector<pair<int, int>> ones;


void backtracking(int idx, int cnt) {
	if (cnt >= ans)
		return;

	if (idx == ones.size()) {
		ans = MIN(ans, cnt);
		return;
	}

	if (check[ones[idx].first][ones[idx].second] > 0) {
		backtracking(idx + 1, cnt);
		return;
	}

	for (int i = 5; i >= 1; i--) {
		if (ones[idx].first + i > 10 || ones[idx].second + i > 10 || paperCnt[i] == 5)
			continue;

		bool flag = true;

		for (int j = 0; j < i; j++) {
			for (int k = 0; k < i; k++) {
				if (map[ones[idx].first + j][ones[idx].second + k] == 0 || check[ones[idx].first + j][ones[idx].second + k] == 1)
					flag = false;

				check[ones[idx].first + j][ones[idx].second + k]++;
			}
		}

		if (flag) {
			paperCnt[i]++;
			backtracking(idx + 1, cnt + 1);
			paperCnt[i]--;
		}

		for (int j = 0; j < i; j++)
			for (int k = 0; k < i; k++)
				check[ones[idx].first + j][ones[idx].second + k]--;
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 1)
				ones.push_back({ i,j });
		}
	}

	backtracking(0, 0);

	if (ans == 2e9)
		ans = -1;

	printf("%d", ans);

	return 0;
}