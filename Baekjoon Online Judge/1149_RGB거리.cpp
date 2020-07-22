#include <stdio.h>

#define MIN(a,b)(a<b?a:b)

int main() {
	int n, color[3], dp[1000][3] = { 0 };

	scanf("%d", &n);

	scanf("%d %d %d", &dp[0][0], &dp[0][1], &dp[0][2]);

	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", color + 0, color + 1, color + 2);

		for (int j = 0; j < 3; j++) {
			if (j == 0)
				dp[i][j] = MIN(dp[i - 1][1], dp[i - 1][2]) + color[j];

			else if (j == 1)
				dp[i][j] = MIN(dp[i - 1][0], dp[i - 1][2]) + color[j];

			else
				dp[i][j] = MIN(dp[i - 1][0], dp[i - 1][1]) + color[j];
		}
	}

	int res = 2e9;

	for (int i = 0; i < 3; i++)
		res = MIN(res, dp[n - 1][i]);

	printf("%d", res);

	return 0;
}