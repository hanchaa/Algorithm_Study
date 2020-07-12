#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
	int cost;
	vector<int> cnt;
} DP;

DP dp[10][15];
pair<int, int> block[10];

int main() {
	int n, k, falling[5] = { 0 };

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", falling + i);

	for (int i = 1; i <= k; i++)
		scanf("%d %d", &block[i].first, &block[i].second);

	for (int i = 1; i <= 10; i++)
		dp[0][i].cost = 2e9;

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= 10; j++) {
			if (j - block[i].first <= 0) {
				if (dp[i - 1][j].cost < block[i].second)
					dp[i][j] = dp[i - 1][j];

				else if (dp[i - 1][j].cost > block[i].second) {
					dp[i][j].cost = block[i].second;
					dp[i][j].cnt.push_back(1);
				}

				else {
					dp[i][j] = dp[i - 1][j];
					dp[i][j].cnt.push_back(1);
				}
			}

			else {
				bool flag = false;

				for (const auto& cnt : dp[i][j - block[i].first].cnt)
					if (cnt < n)
						flag = true;

				if (!flag) {
					dp[i][j] = dp[i - 1][j];
					continue;
				}

				if (dp[i - 1][j].cost < dp[i][j - block[i].first].cost + block[i].second)
					dp[i][j] = dp[i - 1][j];

				else if (dp[i - 1][j].cost > dp[i][j - block[i].first].cost + block[i].second) {
					dp[i][j].cost = dp[i][j - block[i].first].cost + block[i].second;

					for (const auto& cnt : dp[i][j - block[i].first].cnt)
						if (cnt < n)
							dp[i][j].cnt.push_back(cnt + 1);
				}

				else {
					dp[i][j] = dp[i - 1][j];

					for (const auto& cnt : dp[i][j - block[i].first].cnt)
						if (cnt < n)
							dp[i][j].cnt.push_back(cnt + 1);
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d %d\n", dp[k][falling[i]].cost, dp[k][falling[i]].cnt.size());

	return 0;
}